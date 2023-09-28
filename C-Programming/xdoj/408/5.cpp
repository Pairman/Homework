#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
    int n=0,m=0,i=0,j=0; cin>>n>>m;
    int a[32][32]={0},b[32][32]={0};
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){cin>>a[i][j];}
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<m-2;j++){
            if(a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2]){b[i][j]=b[i][j+1]=b[i][j+2]=1;}
        }
    }
    for(i=0;i<n-2;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j]){b[i][j]=b[i+1][j]=b[i+2][j]=1;}
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b[i][j]){cout<<0;}
            else{cout<<a[i][j];}
            if(j==m-1){cout<<endl;continue;}
            cout<<" ";
        }
    }
}