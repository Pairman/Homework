#include<bits/stdc++.h>

int main(){
    int n,i=1,sum=0;
    scanf("%d",&n);
    while(i<=n){
        sum+=i;
        i++;
    }
    printf("%d\n",sum);
    return 0;
}