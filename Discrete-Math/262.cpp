#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,m=0;
    cin>>n>>m;

    for(int i=n+1;i<m;++i){
        for(int j=i+1;j<m;++j){
            for(int k=j+1;k<m;++k){
                printf("<%d,%d,%d>\n",i,j,k);
            }
        }
    }
}