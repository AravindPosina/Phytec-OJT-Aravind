all:fibo.o num.o fibo run

fibo:fibo.o num.o 
	gcc fibo.o num.o -o fibo 
fibo.o:fibo.c 
	gcc -c fibo.c 
num.o:num.c
	gcc -c num.c
run:
	./fibo
clean:
	rm -rf fibo.o num.o fibo

