#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    double d=(1.0/3.0)*(a+b+c);
    printf("%.2f",d);
    return 0;
}