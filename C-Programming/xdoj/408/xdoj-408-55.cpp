#include<bits/stdc++.h>

int a(int n){
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }
    return a(n-1)+a(n-2);
}

int b(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return b(n-1)+b(n-2);
}

double sum(int n){
    if(n==1){
        return 2.0;
    }
    return sum(n-1)+(1.0*a(n)/b(n));
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%.2lf",sum(n));
}