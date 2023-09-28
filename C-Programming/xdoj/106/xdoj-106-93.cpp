#include<bits/stdc++.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b){
        int t=b;
        b=a;
        a=t;
    }
    b%=10;
    a*=a;
    printf("%d %d\n",b,a);
    return 0;
}