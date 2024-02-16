all: hello.o greeting.o hello run

hello:hello.o greeting.o
	gcc hello.o greeting.o -o hello
hello.o:hello.c
	gcc -c hello.c 
greeting.o:greeting.c
	gcc -c greeting.c
run:
	./hello
clean:
	rm -rf greeting.o  hello.o hello
