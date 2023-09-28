#include<bits/stdc++.h>
using namespace std;

int main(){
    int m=0,n=0, a[101][101]={0}, num=1, u=0,d=m-1,l=0,r=n-1, i=u,j=l;
    cin>>m>>n;
    while(u<=d&&l<=r){
        for(j=l;j<=r;++j){a[u][j]=num; ++num;} ++u;
        for(i=u;i<=d;++i){a[i][r]=num; ++num;} --r;
        if(d>=u){for(j=r;j>=l;--j){a[d][j]=num; ++num;} --d;}
        if(r>=l){for(i=d;i>=u;--i){a[i][l]=num; ++num;} ++l;}
    }
    for(int i=0;i<m;++i){
        cout<<a[i][0];
        for(int j=1;j<n;++j){cout<<" "<<a[i][j];}
        cout<<endl;
    }
}