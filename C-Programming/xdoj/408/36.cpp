#include<bits/stdc++.h>
#define elif else if
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    int m=0; cin>>m;
    int mat[21][21]={0},sum[45]={0},count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){cin>>mat[i][j];}
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){sum[count]+=mat[i][j];}
        count++;
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<m;i++){sum[count]+=mat[i][j];}
        count++;
    }
    for(int i=0;i<m;i++){sum[count]+=mat[i][i];}
    count++;
    for(int i=0;i<m;i++){sum[count]+=mat[i][m-1-i];}
    count++;
    sort(sum,sum+count,cmp);
    cout<<sum[0];
    for(int i=1;i<count;i++){cout<<" "<<sum[i];}
}