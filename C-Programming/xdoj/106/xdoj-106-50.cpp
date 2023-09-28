#include<bits/stdc++.h>

int sum(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main(){
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int qq=a[0];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(sum(a[j])>sum(a[j+1])){
                int t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
            if(sum(a[j])==sum(a[j+1])&&a[j]>a[j+1]){
                int t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    printf("%d\n",a[n-1]);
    return 0;
}