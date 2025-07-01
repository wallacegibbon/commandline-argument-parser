#include "cmd_argument_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int is_option(const char *s)
{
	if (s[0] == '\0' || s[1] == '\0' || s[2] == '\0')
		return 0;
	else
		return s[0] == '-' && s[1] == '-';
}

int cmd_argument_parser_step(struct cmd_argument_parser *self)
{
	if (self->index == self->argc)
		return 1;

	if (!is_option(self->argv[self->index])) {
		self->others[self->others_index++] = self->argv[self->index];
		self->index++;
		return 0;
	}

	self->keys[self->option_count] = self->argv[self->index] + 2;
	if (self->index == self->argc - 1 ||
			is_option(self->argv[self->index + 1])) {
		self->values[self->option_count] = NULL;
		self->index++;
	} else {
		self->values[self->option_count] = self->argv[self->index + 1];
		self->index += 2;
	}
	self->option_count++;

	return 0;
}

/*
 * We need to call `cmd_argument_parser_deinit` to free allocated memories.
 */
void cmd_argument_parser_init(struct cmd_argument_parser *self,
		int argc, const char **argv)
{
	self->argc = argc;
	self->argv = argv;
	self->index = 0;
	self->keys = (const char **)malloc(sizeof(const char *) * argc);
	self->values = (const char **)malloc(sizeof(const char *) * argc);
	self->others = (const char **)malloc(sizeof(const char *) * argc);
	self->others_index = 0;
	self->option_count = 0;

	while (!cmd_argument_parser_step(self));
}

void cmd_argument_parser_deinit(struct cmd_argument_parser *self)
{
	free(self->keys);
	free(self->values);
	free(self->others);
}

const char *cmd_argument_parser_get(struct cmd_argument_parser *self,
		const char *key, const char *default_value)
{
	int i;
	for (i = 0; i < self->option_count; i++) {
		if (strcmp(self->keys[i], key) == 0 && self->values[i] != NULL)
			return self->values[i];
	}
	return default_value;
}

int cmd_argument_parser_has(struct cmd_argument_parser *self, const char *key)
{
	int i;
	for (i = 0; i < self->option_count; i++) {
		if (strcmp(self->keys[i], key) == 0)
			return 1;
	}
	return 0;
}

void cmd_argument_parser_describe(struct cmd_argument_parser *self)
{
	int i;
	for (i = 0; i < self->option_count; i++)
		printf("\"%s\":\"%s\" ", self->keys[i], self->values[i]);

	printf("  <<<- options:others ->>>   ");
	for (i = 0; i < self->others_index; i++)
		printf("\"%s\" ", self->others[i]);

	printf("\n");
}
