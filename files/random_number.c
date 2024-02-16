#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 25;
    int i;

    for (i = 0; i < n; i++) {
        int rd = rand() % 25; 
	if (i = rd)
	{
		printf("");
	}
	else
	{
        printf("%d ", rd);
	}
    }

    return 0;
}

