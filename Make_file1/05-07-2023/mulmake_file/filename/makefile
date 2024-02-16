all:file.o name.o file run

file:file.o name.o 
	gcc file.o name.o -o file
file.o:file.c 
	gcc -c file.c
name.o:name.c
	gcc -c name.c
run:
	./file
clean:
	rm -rf file.o name.o file

