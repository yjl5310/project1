all: prog4 prog4_rusage

prog4: prog4.c check.o
	gcc -g -std=gnu99 prog4.c check.o -o prog4 -lm

prog4_rusage: prog4_rusage.c check.o
	gcc -g -std=gnu99 prog4_rusage.c check.o -o prog4_rusage -lm

check.o: check.c check.h
	gcc -c -std=gnu99 check.c -o check.o -lm

clean:
	rm -f prog4 check.o prog4_rusage
