#include<stdio.h>

int main(){
    double s;
    scanf("%lf",&s);
    int d=s/10;
    switch(d){
        case 9: printf("A"); break;
        case 8: printf("B"); break;
        case 7: printf("C"); break;
        case 6: printf("D"); break;
        default: printf("E"); break;
    }
}