#include<bits/stdc++.h>

int main(){
    
    int n,sum=0;
    scanf("%d",&n);
    while(n!=0){
        if(n%2){
            sum+=n;
        }
        scanf("%d",&n);
    }
    printf("%d",sum);
    return 0;
}