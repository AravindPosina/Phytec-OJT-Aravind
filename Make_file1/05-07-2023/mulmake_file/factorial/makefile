all:fact.o num.o fact run 

fact:fact.o num.o 
	gcc fact.o num.o -o fact 
fact.o:fact.c
	gcc -c fact.c 
num.o:num.c 
	gcc -c num.c
run:
	./fact
clean:
	rm -rf fact.o num.o fact

