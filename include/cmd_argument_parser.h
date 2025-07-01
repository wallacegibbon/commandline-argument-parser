#ifndef __CMD_ARGUMENT_PARSER_H
#define __CMD_ARGUMENT_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif

struct cmd_argument_parser {
	/* argc and argv are copied from arguments of `main` function */
	int argc;
	const char **argv;

	/* keys and values are 2 arrays whose element index matches */
	const char **keys;
	const char **values;

	const char **others;

	/* index is a cursor to iterat through the arguments with values */
	int index;

	/* others_index is a cursor to iterate through simple arguments */
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
