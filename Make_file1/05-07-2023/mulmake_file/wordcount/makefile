all:word.o count.o word run

word:word.o count.o 
	gcc word.o count.o -o word
word.o:word.c 
	gcc -c word.c
count.o:count.c
	gcc -c count.c
run:
	./word
clean:
	rm -rf  word.o count.o word
