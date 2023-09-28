#include<stdio.h>

int main(){
    unsigned w;
    scanf("%d",&w);
    printf("%d %d %d %d %d %d",w/100,w%100/50,w%100%50/20,w%100%50%20/10,w%100%50%20%10/5,w%5);
    return 0;
}