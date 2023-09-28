#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3][3]={0},aT[3][3]={0};
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cin>>a[i][j];
            aT[j][i]=a[i][j];
        }
    }

    for(int i=0;i<3;++i){
        cout<<aT[i][0]+a[i][0];
        for(int j=1;j<3;++j){
            cout<<" "<<aT[i][j]+a[i][j];
        }
        cout<<endl;
    }
}