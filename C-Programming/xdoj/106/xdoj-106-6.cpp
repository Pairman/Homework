#include<bits/stdc++.h>

int main(){
    int n,num[1000],sum[1000],a,b,c,d,e,p,q;
    scanf("%d",&n);
    for(int s=0,i=0;i<n;i++){
        scanf("%d",&s);
        num[i]=s;
        sum[i]=num[i]%10+(num[i]%100-num[i]%10)/10+(num[i]%1000-num[i]%100)/100+(num[i]%10000-num[i]%1000)/1000+(num[i]%100000-num[i]%10000)/10000;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(sum[j]>sum[j+1]){
                p=sum[j]; q=num[j];
                sum[j]=sum[j+1]; num[j]=num[j+1];
                sum[j+1]=p; num[j+1]=q;
            }
        }
    }
    for(int i=n-1;i>-1;i--){
        printf("%d %d\n",num[i],sum[i]);
    }
}