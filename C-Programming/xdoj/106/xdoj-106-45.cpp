#include<bits/stdc++.h>

int main(){
    int n,a[30]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int d=abs(a[1]-a[0]);
    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1])>d){
            d=abs(a[i]-a[i+1]);
        }
    }

    printf("%d\n",d);
    return 0;
}