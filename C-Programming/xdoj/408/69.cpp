#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
    int i=0,j=0,m=0,n=0,a[101][101]; cin>>m>>n;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){cin>>a[i][j];}
    }

    for(int i=0;i<m;++i){
        int start=-1,end=-1;
        for(int j=0,tmpstart=-1,tmpend=-1;j<n;++j){
            //START
            if(j==0&&a[i][0]==1){tmpstart=0;}
            if(j!=0&&a[i][j-1]==0&&a[i][j]==1){tmpstart=j;}
            //END
            if(j!=m-1&&a[i][j]==1&&a[i][j+1]==0){tmpend=j;}
            if(j==m-1&&a[i][j]==1){tmpend=j;}
            //COMPARE
            if(tmpend-tmpstart>=end-start){start=tmpstart; end=tmpend;}
        }
        cout<<start<<" "<<end<<endl;
    }
}