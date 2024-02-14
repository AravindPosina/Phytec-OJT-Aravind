#include<stdio.h>
#include<string.h>
display_sorted() {
	char a[50][50];
	int i,j,k,count=0;
	char *p[10];
	char *temp;
	printf("Enter the count:\n");
	scanf("%d",&count);
	printf("Enter %d names\n",count);
	__fpurge(stdin);
	for(i=0;i<count;i++) {
		fgets(a[i],50,stdin);
	}
	for(i=0;i<count;i++) {
		p[i]=a[i];
	}
	for(i=0;i<count;i++) {
	       for(j=0;j<count-1-i;j++) {
	       k=strcmp(p[j],p[j+1]);
	if(k>0) {
	 temp=p[j];
	 p[j]=p[j+1];
	 p[j+1]=temp;
	}
	       }
	}
	printf("The sorted names are:");
	for(i=0;i<count;i++) {
		printf("%s\n",p[i]);
	}
}
