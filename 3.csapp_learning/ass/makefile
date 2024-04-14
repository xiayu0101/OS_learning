CC = /usr/bin/gcc
CFLAGS = -Wall -g -o2 -Werror -std=gnu99
EXE = program
CODE = ./memory/instruction.c ./disk/code.c ./cpu/mmu.c ./memory/dram.c ./main.c
.PHONY:program
main:
	$(CC) $(CFLAGS) -I. $(CODE) -o $(EXE)

run:
	./${EXE}