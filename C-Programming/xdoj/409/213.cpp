#include<bits/stdc++.h>
using namespace std;

void place(int num[],int m,int n){
    int a[101][101]={0};
    for(int i=0;i<m*n;++i){a[i/n][i%n]=num[i];}

    for(int i=0;i<m;++i){
        if(i%2==0){
            printf("%3d",a[i][n-1]);
            for(int j=1;j<n;++j){printf(" %3d",a[i][n-1-j]);}
        }
        else{
            printf("%3d",a[i][0]);
            for(int j=1;j<n;++j){printf(" %3d",a[i][j]);}
        }
        if(i!=m-1){cout<<endl;}
    }
}

int main(){
    int m=0,n=0,num[101]={0}; cin>>m>>n;
    for(int i=0;i<m*n;++i){cin>>num[i];}
    sort(num,num+m*n);
    place(num,m,n);
}