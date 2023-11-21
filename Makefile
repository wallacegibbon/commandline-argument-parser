C_SOURCE_FILES += $(wildcard ./src/*.c)

C_INCLUDES += ./include ./src

TARGET = cmd_argument_parser

#LD_FLAGS += -lserialport

include ./miscellaneous-makefiles/simple-gcc-lib.mk

