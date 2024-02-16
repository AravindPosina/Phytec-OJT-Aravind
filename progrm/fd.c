#include<stdio.h>
int main()
{

FILE *fptr;

// Create a file
fptr = fopen("filename.txt", "w");

fprintf(fptr, "hello harish");

// Close the file
fclose(fptr);
}

