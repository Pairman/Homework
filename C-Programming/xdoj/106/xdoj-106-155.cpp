#include<bits/stdc++.h>

int Mul(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
}

int main(){
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=Mul(i);
    }
    printf("%d %d %d\n",n,Mul(n),sum);
    return 0;
}