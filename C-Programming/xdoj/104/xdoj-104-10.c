#include<stdio.h>

int main(){
    double f;
    scanf("%lf",&f);
    printf("%.2f",(f-32)*5.0/9.0);
    return 0;
}