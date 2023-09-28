#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
    int i=0,j=0,n=0,a[101][101]={32767}; cin>>n;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){cin>>a[i][j];}
    }
    cout<<a[0][0];
    for(i=1;i<2*n;++i){
        if(i%2){
            for(j=0;j<=i;++j){
                if(i-j<n&&j<n){
                    cout<<" "<<a[j][i-j];
                }
            }
        }
        else{
            for(j=0;j<=i;++j){
                if(i-j<n&&j<n){
                    cout<<" "<<a[i-j][j];
                }
            }
        }
    }
}