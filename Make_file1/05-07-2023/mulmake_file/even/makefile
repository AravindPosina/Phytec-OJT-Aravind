all:even.o num.o even run

even:even.o num.o 
	gcc even.o num.o -o even
even.o:even.c 
	gcc -c even.c
num.o:num.c 
	gcc -c  num.c
run:
	./even
clean:
	rm -rf even.o num.o even 

