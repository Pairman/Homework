#include<bits/stdc++.h>

int len(int n){
    if(n==0){
        return 1;
    }
    int l=0;
    while(n!=0){
        l++;
        n/=10;
    }
    return l;
}

int sum(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);

    while(len(n)>1){
        n=sum(n);
    }

    printf("%d",n);
}