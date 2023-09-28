#include<stdio.h>

int main(){
    float k1=7.86*3.1415926*4/24000,k2=19.3*3.1415926*4/24000;
    int di,dg;
    scanf("%d %d",&di,&dg);
    printf("%.3f %.3f\n",k1*di*di*di,k2*dg*dg*dg);
    return 0;
    }