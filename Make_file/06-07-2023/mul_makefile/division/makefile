all:div.o two.o div run

div:div.o two.o 
	gcc div.o two.o -o div
div.o:div.c 
	gcc -c div.c

two.o:two.c
	gcc -c two.c
run:
	./div
clean:
	rm -rf div.o two.o div

