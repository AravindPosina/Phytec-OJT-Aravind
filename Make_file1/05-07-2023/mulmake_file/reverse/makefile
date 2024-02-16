all: rev.o num.o rev run

rev:rev.o num.o 
	gcc rev.o num.o -o rev
rev.o:rev.c 
	gcc -c rev.c 
num.o:num.c
	gcc -c num.c
run:
	./rev
clean:
	rm -rf rev.o num.o rev

