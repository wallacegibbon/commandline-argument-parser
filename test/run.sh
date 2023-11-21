#! /bin/sh

TEST_BUILD_DIR=$(dirname $0)/tmp
mkdir -p $TEST_BUILD_DIR

gcc -I include -c src/cmd_argument_parser.c -o $TEST_BUILD_DIR/cmd_argument_parser.o
gcc -I include test/test.c $TEST_BUILD_DIR/cmd_argument_parser.o -o $TEST_BUILD_DIR/out.elf

$TEST_BUILD_DIR/out.elf --name wallace junk1 --age 100 --active - junk2 -- junk3
$TEST_BUILD_DIR/out.elf junk1 --name harry

rm -rf $TEST_BUILD_DIR

