all:leapy.o year.o leap run

leap:leapy.o year.o 
	gcc leapy.o year.o -o leap
leapy.o:leapy.c 
	gcc -c leapy.c
year.o:year.c
	gcc -c year.c
run:
	./leap
clean:
	rm -rf leapy.o year.o leap
