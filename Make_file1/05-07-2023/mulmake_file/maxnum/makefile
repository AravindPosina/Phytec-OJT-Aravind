all: max.o num.o max run

max:max.o num.o 
	gcc max.o num.o -o max
max.o:max.c
	gcc -c max.c
num.o:num.c
	gcc -c num.c
run:
	./max
clean:
	rm -rf max.o num.o max 

