#include<stdio.h>

int main(){
    int a,b,gcd,i=1;
    scanf("%ld %ld",&a,&b);
    for(i=1;i<=a||i<=b;i++){
        if(a%i==0&b%i==0){
            gcd=i;
        }
    }
    printf("%ld %ld\n",gcd,a*b/gcd);
    return 0;
}