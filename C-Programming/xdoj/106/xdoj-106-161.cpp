#include<bits/stdc++.h>

void Even(int n){
    if(n%2==0){
        printf("%d ",n/2);
    } else{
        printf("%d ",(n-1)/2);
    }
}

void Odd(int n){
    if(n%2==0){
        printf("%d ",n/2);
    } else{
        printf("%d ",(n+1)/2);
    }
}

void Sum_3(int n){
    n=n-(n%3);
    printf("%d ",n/3);
}

void Sum_5(int n){
    n=n-(n%5);
    printf("%d ",n/5);
}

void Sum_7(int n){
    n=n-(n%7);
    printf("%d\n",n/7);
}

int main(){
    int n;
    scanf("%d",&n);
    Odd(n);
    Even(n);
    Sum_3(n);
    Sum_5(n);
    Sum_7(n);
}