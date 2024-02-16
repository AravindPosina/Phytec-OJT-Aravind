#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("enter the string:");
    scanf("%s",s);
    printf("ASCII values :");
    for(int i=0;i<strlen(s);i++)
    {
        printf("the ascii %c value is %d\n",s[i],s[i]);
    }
}
