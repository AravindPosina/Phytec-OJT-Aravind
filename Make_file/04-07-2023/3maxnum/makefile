all:3max.o num.o max run

max:3max.o num.o
	gcc 3max.o num.o -o max
3max.o:3max.c
	gcc -c 3max.c
num.o:num.c
	gcc -c num.c
run:
	./max
clean:
	rm -rf 3max.o num.o max
