#include<bits/stdc++.h>

int fibonacci(int n){
    if(n==1||n==2){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int prime(int n){
    if(n==1){
        return 0;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);

    int f=fibonacci(n);

    switch(prime(f)){
        case 1:
            printf("yes");
            break;
        default:
            printf("%d",f);
    }
}