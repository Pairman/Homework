#include<stdio.h>

int main(){
    double i,a=10000,b=7500,c=10000,d=6000,e=6000,k;
    scanf("%lf",&i);
    if(i<=100000){
        k=i/10;
        printf("%.2f",k);
    } else if(i<=200000){
        k=(i-100000)/100*7.5;
        printf("%.2f",a+k);
    } else{
        if(i<=400000){
            k=(i-200000)/100*5;
            printf("%.2f",a+b+k);
        } else if(i<=600000){
            k=(i-400000)/100*3;
            printf("%.2f",a+b+c+k);
        } else{
            if(i<=600000){
                k=(i-600000)/100*1.5;
                printf("%.2f",a+b+c+d+k);
            } else{
                k=(i-1000000)/100*1;
                printf("%.2f",a+b+c+d+e+k);

            }
        }
    }
    return 0;
}