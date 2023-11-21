#ifndef __CMD_ARGUMENT_PARSER_H
#define __CMD_ARGUMENT_PARSER_H

struct cmd_argument_parser {
	int argc;
	const char **argv;
	int index;
	const char **keys;
	const char **values;
	int option_count;
};

void cmd_argument_parser_prepare(struct cmd_argument_parser *self, int argc, const char **argv);
void cmd_argument_parser_cleanup(struct cmd_argument_parser *self);

const char *cmd_argument_parser_get(struct cmd_argument_parser *self, const char *key, const char *default_value);
int cmd_argument_parser_has(struct cmd_argument_parser *self, const char *key);

void cmd_argument_parser_describe(struct cmd_argument_parser *self);

#endif
