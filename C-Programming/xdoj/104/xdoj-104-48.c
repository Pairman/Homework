#include<stdio.h>

int main(){
    int m,n,q,r,x,y;
    scanf("%d %d %d %d",&m,&n,&q,&r);
    x=m/n; y=m%n;
    if(x==q&y==r){
        printf("yes");
    } else{
        printf("%d %d",x,y);
    }
}