#include<stdio.h>
void isKthBitSet(int n,int k) {
	int mask = 1 << (k-1);
	if (n & mask)
		printf("SET");
	else
		printf("NOT SET");
}
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	isKthBitSet(a,b);
}
