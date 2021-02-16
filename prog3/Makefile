all: prog3_32 prog3_64

prog3_32: prog3.c
	gcc -g -std=gnu99 prog3.c -o prog3_32 -lm -m32

prog3_64: prog3.c
	gcc -g -std=gnu99 prog3.c -o prog3_64 -lm
clean:
	rm -rf prog3_32 prog3_64
