TARGET = cmd_argument_parser

C_SOURCE_FILES += $(wildcard ./src/*.c)
C_INCLUDES += ./src ./include

include ./cc-with-test.mk
