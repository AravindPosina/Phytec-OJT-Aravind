all:sortstring sortstring1
sortstring:sortstring.c sortstring1.c
	gcc -c sortstring.c sortstring1.c
sortstring1:sortstring.o sortstring1.o
	gcc sortstring.o sortstring1.o -o sortstring1
	./sortstring1
clean:
	rm -rf sortstring.o sortstring1.o sortstring
