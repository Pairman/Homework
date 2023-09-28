#include<stdio.h>

int g(int x){
    int a=1;
    if(x==0){
        a=1;
    }
    else{
        a=1;
        for(int i=1;i<=x;i++){
            a*=10;
        }
    }
    return a;
}

int main(){
    unsigned x,s=0;
    scanf("%d",&x);
    for(int i=1;i<=9;i++){
        s+=(x%g(i)-x%g(i-1))/g(i-1);
    }
    printf("%d\n",s);
    return 0;
}