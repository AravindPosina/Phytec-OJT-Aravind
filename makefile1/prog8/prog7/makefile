all:strrev strrev1
strrev:strrev.c strrev1.c
	gcc -c strrev.c strrev1.c
strrev:strrev.o strrev1.o
	gcc strrev.o strrev1.o -o strrev
	./strrev
clean:
	rm -rf strrev.o strrev1.o strrev
