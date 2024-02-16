all:add.o num.o add run

add:add.o num.o
	gcc add.o num.o -o add
add.o:add.c
	gcc -c add.c 
num.o:num.c
	gcc -c num.c
run:
	./add
clean:
	rm -rf add.o  num.o add
