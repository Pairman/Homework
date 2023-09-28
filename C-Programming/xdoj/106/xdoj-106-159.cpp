#include<bits/stdc++.h>

int Mul(int n){
    if(n==0){
        return 1;
    }
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
}

float P(int m,int n){
    float p=1.0*Mul(m)/(Mul(n)*Mul(m-n));
    return p;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%.2f\n",P(m,n));
    return 0;
}