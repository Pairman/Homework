#include<stdio.h>

int main(){
    int gcd,a,b,t,r;
    scanf("%d %d",&a,&b);
    if(a<b){
        t=a;
        a=b;
        b=t;
    }
    if(b==0){
        gcd=a;
    } else{
        while((a%b)!=0){
            r=a%b;
            a=b;
            b=r;
        }
        gcd=b;
    }
    printf("%d\n",gcd);
    return 0;
}