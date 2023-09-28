#include<stdio.h>

int main(){
    unsigned int h,m;
    scanf("%d %d",&h,&m);
    double t=h+(m/60.0),T=4*t*t/(t+2)-20;
    printf("%.2f",T);
    return 0;
}