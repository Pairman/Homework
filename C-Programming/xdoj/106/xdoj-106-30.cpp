#include<bits/stdc++.h>

int perf(int n){
    unsigned short sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n){
        return 1;
    }
    return 0;
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
        if(perf(i))
            printf("%d\n",i);
    }
    return 0;
}