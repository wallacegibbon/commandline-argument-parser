#include "cmd_argument_parser.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv)
{
	struct cmd_argument_parser parser;
	const char *name;
	int age;
	int active;
	int i;

	printf("raw arguments:\n\t");
	for (i = 0; i < argc; i++)
		printf("%s ", argv[i]);

	printf("\n\n");

	cmd_argument_parser_init(&parser, argc - 1, argv + 1);
	name = cmd_argument_parser_get(&parser, "name", NULL);
	age = atoi(cmd_argument_parser_get(&parser, "age", "0"));
	active = cmd_argument_parser_has(&parser, "active");

	cmd_argument_parser_describe(&parser);
	printf("\tperson: %s, age: %d, active: %d\n\n", name, age, active);

	cmd_argument_parser_deinit(&parser);

	return 0;
}
