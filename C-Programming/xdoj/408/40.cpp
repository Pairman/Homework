#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
    int diff=0,i=0,n=0,a[100]={0};
    cin>>n;
    for(i=0;i<n;i++){cin>>a[i];}
    if(n==0||n==1){cout<<"no"; return 0;}
    sort(a,a+n);
    diff=a[1]-a[0];
    for(i=0;i<n-1;i++){
        if((a[i+1]-a[i])!=diff){cout<<"no"; return 0;}
    }
    cout<<diff;
}