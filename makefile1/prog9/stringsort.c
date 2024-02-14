#include<stdio.h>
#include<string.h>
int main()
{
	char a[50][50],temp[50];
	int i,j,k,count=0;
	printf("Enter the count:\n");
	scanf("%d",&count);
	printf("Enter %d names\n",count);
	__fpurge(stdin);
	for(i=0;i<count;i++)
		fgets(a[i],50,stdin);
	
	for (i=0;i<count-1;i++)
	{
		for (j=0;j<count-1-i;j++)
		{
			k=strcmp(a[j],a[j+1]);
			if(k > 0)
			{
			strcpy(temp,a[j]);
			strcpy(a[j],a[j+1]);
			strcpy(a[j+1],temp);
			}
		}
	}
	printf("The sorted names are:");
	for (i=0;i<count;i++)
	{
		printf("%s\n",a[i]);
	}
}
