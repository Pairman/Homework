#include<stdio.h>

int main(){
    unsigned x;
    scanf("%d",&x);
    unsigned a=x%10,b=(x%100-x%10)/10,c=(x%1000-x%100)/100,d=(x%10000-x%1000)/1000,e=(x%100000-x%10000)/10000;
    printf("%d",a+b+c+d+e);
    return 0;
}