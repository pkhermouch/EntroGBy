all: memory.c memory.h main.c CPU.c CPU.h interpreter.c interpreter.h cb_switch.h common.h opcode_switch.h ROM.h tables.c tables.h
	gcc -std=c99 *.c

clean:
	rm a.out
