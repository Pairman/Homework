#include<stdio.h>
#include<string.h>
int main()
{
	char b[100];
	int a[10]={0},i,j,end,l=0,c=0,t;
	gets(b);
	for(i=0;i<strlen(b)-1;i++)
	{	
		if((b[i]<'0')||(b[i]>'9'))
		continue;
		if(b[i]>='0'&&b[i]<='9')
		{
			end=i;
			l=l+1;
		}
		if(b[i+1]>='0' && b[i+1]<='9')
		{
			end=i+1;
			l=l+1;
		} 
		else if((b[i+1]<'0')||(b[i+1]>'9'))
		{
			for(j=end-l+1;j<=end;j++)
		 	a[c]=a[c]*10+b[j]-48;
		 	l=0;
		 	c++;
		}
		 if(i==strlen(b)-2 && l!=0)
		 {
		 	for(j=end-l+1;j<=end;j++)
		 	a[c]=a[c]*10+b[j]-48;
		 	l=0;
		 	c++;
		 }
	}
		for(j=0;j<c-1;j++)
	{
		for(i=0;i<c-1-j;i++)
		{
			if(a[i]<a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	for(i=0;i<c;i++)
	printf("%d ",a[i]);
	return 0;
 } 
