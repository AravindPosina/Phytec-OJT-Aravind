all:hello.o hello run
	
hello.o:hello.c
	gcc -c hello.c

hello: hello.o
	gcc hello.o -o hello
run:
	./hello
clean:
	rm -rf hello hello.o
