#include<stdio.h>
int main()
{
	int n,j,i,s,s0;
	int a[n][n];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);	
			}
		}
		for(i=0,j=0;i<n;i++,j++){
			if(n-1-i>i){
			s0=a[i][i]+a[i][n-1-i]+a[n-1-i][i]+a[n-1-i][n-1-i];
			s=s+s0;
		}
			if(n-1-i==i){
			s0=a[i][i];
			s=s+s0;
			}
			if(n-1-i<i){
			break;
			}
		}
		printf("%d",s);
	return 0;
}