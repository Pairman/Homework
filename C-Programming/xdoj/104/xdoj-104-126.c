#include<stdio.h>
#include<math.h>

int main(){
    double d,p,r;
    scanf("%lf %lf %lf",&d,&p,&r);
    double m=log(p/(p-(d*r)))/log(1+r);
    printf("%.2f",m);
}