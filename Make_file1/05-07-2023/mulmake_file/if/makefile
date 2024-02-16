all: if.o even.o if run

if:if.o even.o
	gcc if.o even.o -o if
if.0:if.c
	gcc -c if.c
even.o:even.c
	gcc -c even.c
run:
	./if
clean:
	rm -rf if if.o even.o


