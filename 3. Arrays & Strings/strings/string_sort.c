#include<stdio.h>
int main()
{
        char i,j,temp=0;
	int num;
	
        char a[20];
	//char s[20];
	printf("Enter the string: ");
	fgets(a,sizeof(a),stdin);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==' ')
		{
			a[i]=a[i+1];
			a[i+1]=i--;
		}
	}
	
       for(i=0;a[i]!='\0';i++)
        {
                for(j=i+1;a[j];j++)
                {
                        if(a[i]>a[j])
                        {
                                temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                }
        }
        printf("The sorted string is:");
        for(i=0;a[i]!='\0';i++)
        {
		printf("%c",a[i]);
        }
}
