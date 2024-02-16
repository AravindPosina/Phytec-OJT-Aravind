#include<stdio.h>
int e(int x,int n)
{
	static int s=1;
	if(n==0)
	{
		return 1;
	}
	for(int n>0;n--);
	 {
		s=(1+(x%n))*s;
		return e(x,n-1);
	 }

		return s;
}
int main()
{	
	int n=1,s=4;
	printf("the value of %ls");
	return 0;

}





