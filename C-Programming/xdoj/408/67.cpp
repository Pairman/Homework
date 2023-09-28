#include<stdio.h>
int main()
{
	int i,k,n,a[100],flag1=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(k==a[i])
		{
			printf("%d ",i);
			flag1=1;
		}
	}
	if(flag1==0) printf("-1");
	return 0;
 } 
