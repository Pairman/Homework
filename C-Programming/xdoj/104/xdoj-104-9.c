#include<stdio.h>
int main(){
    const float k=3.1415926*4/24000;
    int di,dg;
    scanf("%d %d",&di,&dg);
    printf("%.3f %.3f",7.86*k*di*di*di,19.3*k*dg*dg*dg);
    return 0;
    }