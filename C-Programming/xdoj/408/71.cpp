#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
    int n=0,m=0,a[22][22]={0},t=0,k=0;
    cin>>n>>m>>t>>k;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){cin>>a[i][j];}
    }

    int K[51]={0};
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]==k){
                if(a[i][j-1]!=k){K[a[i][j-1]]=1;}
                if(a[i][j+1]!=k){K[a[i][j+1]]=1;}
                if(a[i-1][j]!=k){K[a[i-1][j]]=1;}
                if(a[i+1][j]!=k){K[a[i+1][j]]=1;}
                }
        }
    }

    int sum=0;
    for(int i=1;i<=t;++i){
        if(K[i]){++sum;}
    }
    cout<<sum;
}