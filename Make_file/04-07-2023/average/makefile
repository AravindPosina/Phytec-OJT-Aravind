all:average.o num.o average run

average:average.o num.o 
	gcc average.o num.o -oaverage
average.o:average.c
	gcc -c average.c 
num.o:num.c
	gcc -c num.c
run:
	./average
clean:
	rm -rf average.o num.o average
