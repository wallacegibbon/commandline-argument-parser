#ifndef __CMD_ARGUMENT_PARSER_H
#define __CMD_ARGUMENT_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif

struct cmd_argument_parser {
	int argc;
	const char **argv;
	int index;
	const char **keys;
	const char **values;
	const char **others;
	int others_index;
	int option_count;
};

void cmd_argument_parser_init(struct cmd_argument_parser *self,
		int argc, const char **argv);

void cmd_argument_parser_deinit(struct cmd_argument_parser *self);

const char *cmd_argument_parser_get(struct cmd_argument_parser *self,
		const char *key,
		const char *default_value);

int cmd_argument_parser_has(struct cmd_argument_parser *self,
		const char *key);

void cmd_argument_parser_describe(struct cmd_argument_parser *self);

#ifdef __cplusplus
}
#endif

#endif
