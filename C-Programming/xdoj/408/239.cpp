#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,a[100][100]={0}; cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            if(!j){a[i][j]=1;}
            else if(i==j){a[i][j]=1; cout<<" ";}
            else{a[i][j]=a[i-1][j-1]+a[i-1][j]; cout<<" ";}
            cout<<a[i][j];
        }
        cout<<endl;
    }
}