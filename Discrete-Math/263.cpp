#include<bits/stdc++.h>
using namespace std;

int main(){
    int m=0;
    cin>>m;

    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            for(int k=1;k<=m;++k){
                for(int l=1;l<=m;++l){
                    if(i*j*k*l==m){
                        printf("<%d,%d,%d,%d>\n",i,j,k,l);
                    }
                }
            }
        }
    }
}