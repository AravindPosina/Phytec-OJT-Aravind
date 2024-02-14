:void mystrrev(char *ptch)
{
	int i,j,len=0;
	char x;
	for(i=0;*(ptch+i);i++) {
		len++;
	}
	for(i=0,j=len-1;i<(len/2);i++,j--)
	{
		x=*(ptch+i);
		*(ptch+i)=*(ptch+j);
		*(ptch+j)=x;
	}
}
