#include<stdio.h>
 
int main(){
	float s=100,h=50;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		s+=2*h;
		h/=2;
	}
	printf("S=%.3f h=%.3f",s,h);
    return 0;
}