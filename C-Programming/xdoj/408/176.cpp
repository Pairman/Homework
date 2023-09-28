#include<bits/stdc++.h>
using namespace std;

int main(){
    int left=0,right=0,m=0,n=0,a[1001]={0}; cin>>n; m=n/2;
    for(int i=0;i<n;++i){cin>>a[i];}
    sort(a,a+n);
    for(int i=0;i<m;++i){
        if(a[i]<a[m]){++left;}
    }
    for(int i=m;i<n;++i){
        if(a[i]>a[m]){++right;}
    }
    if(left==right){cout<<a[m];}
    else{cout<<-1;}
}