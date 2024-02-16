all:mul.o num.o mul run

mul:mul.o num.o 
	gcc mul.o num.o -omul
mul.o:mul.c 
	gcc -c mul.c
num.o:num.c 
	gcc -c num.c
run:
	./mul
clean:
	rm -rf mul.o num.o mul

