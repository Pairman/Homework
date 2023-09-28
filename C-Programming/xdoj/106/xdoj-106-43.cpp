#include<bits/stdc++.h>

int main(){
    int n,i=0,max,min;
    scanf("%d",&n);
    if(n==0){
        printf("1 0 0\n");
        return 0;
    }
    max=min=n%10;
    while(n){
        if(max<n%10)
            max=n%10;
        if(min>n%10)
            min=n%10;
        n/=10;
        i++;
    }
    printf("%d %d %d\n",i,max,min);
    return 0;
}