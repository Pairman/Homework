#include<iostream>
using namespace std;

int main(){
    int n=0,r[256][256]={0};
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>r[i][j];
        }
    }

    int isSym=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(r[i][j]!=r[j][i]){
                isSym=0;
            }
        }
    }

    int isRef=1;
    for(int i=0;i<n;++i){
        if(r[i][i]!=1){
            isRef=0;
        }
    }

    int isTra=1,t[256][256]={0};
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                t[i][j]&=r[i][k]&&r[k][j];
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(r[i][j]<t[i][j]){
                isTra=0;
            }
        }
    }

    if(isSym&isRef&isTra){
        cout<<"yes";
        return 0;
    }
    cout<<"no";
}