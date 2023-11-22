#include "cmd_argument_parser.h"
#include <cstdlib>
#include <iostream>

int main(int argc, const char **argv) {
	struct cmd_argument_parser parser;
	const char *name;
	int age;
	int active;
	int i;

	std::cout << "raw arguments" << std::endl
		  << "\t";

	for (i = 0; i < argc; i++)
		std::cout << argv[i] << " ";

	std::cout << std::endl
		  << std::endl;

	cmd_argument_parser_prepare(&parser, argc - 1, argv + 1);
	name = cmd_argument_parser_get(&parser, "name", NULL);
	age = atoi(cmd_argument_parser_get(&parser, "age", "0"));
	active = cmd_argument_parser_has(&parser, "active");

	cmd_argument_parser_describe(&parser);
	std::cout << "\tperson: " << name << ", age: " << age << ", active: " << active << std::endl
		  << std::endl;

	cmd_argument_parser_cleanup(&parser);

	return 0;
}
