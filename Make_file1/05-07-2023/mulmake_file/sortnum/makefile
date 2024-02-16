all:sort.o num.o sort run

sort:sort.o num.o 
	gcc sort.o num.o -osort
sort.o:sort.c
	gcc -c sort.c
num.o:num.c
	gcc -c num.c
run:
	./sort
clean:
	rm -rf sort.o num.o sort

