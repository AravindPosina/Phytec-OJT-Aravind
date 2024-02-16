all:file.o gcd.o gcd run

gcd:file.o gcd.o 
	gcc file.o gcd.o -ogcd
file.o:file.c 
	gcc -c file.c
gcd.o:gcd.c 
	gcc -c gcd.c
run:
	./gcd
clean:
	rm -rf gcd.o file.o gcd
