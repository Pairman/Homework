#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10]={0};
    for(int i=0;i<10;++i){cin>>a[i];}
    cout<<a[1]/a[0];
    for(int i=2;i<10;++i){cout<<" "<<a[i]/a[i-1];}
}