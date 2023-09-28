#include<bits/stdc++.h>

int Mul(int n){
    if(n==0){
        return 1;
    }
    return n*Mul(n-1);
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    printf("%.2lf",(double)Mul(m)/Mul(n)/Mul(m-n));
}