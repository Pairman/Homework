#include <stdio.h>
 
int main()
{
	int n,i,j;
	int t;
	char a;
	scanf("%c",&a);
	scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n-i; j++)
			putchar(' ');
		for(j=1; j<=i; j++)
		{
				printf(" %c",a);
		}
 
		putchar('\n');
	}
 
	return 0;
}