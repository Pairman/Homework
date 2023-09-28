#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
    int flag=0,maxmaxi=0,maxmaxj=0,i=0,j=0,m=0,n=0,mat[100][100]={0},sad[100][100]={0}; cin>>m>>n;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){cin>>mat[i][j];}
    }
    for(i=0;i<m;++i){
        int min=mat[i][0],minj=0;
        for(j=0;j<n;++j){
            if(mat[i][j]<min){min=mat[i][j]; minj=j;}
            if(minj>maxmaxj){maxmaxj=minj;}
        }
        int max=mat[0][minj],maxi=0;
        for(int k=0;k<m;++k){
            if(mat[k][minj]>max){max=mat[k][minj]; maxi=k;}
            if(maxi>maxmaxi){maxmaxi=maxi;}
        }
        if(min==max){sad[maxi][minj]=1; flag=1;}
    }
    if(flag==0){cout<<"no"; return 0;}
    for(i=0;i<=maxmaxi;++i){
        for(j=0;j<=maxmaxj;++j){
            if(sad[i][j]){cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;}
        }
    }
}