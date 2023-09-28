#include<bits/stdc++.h>
using namespace std;

int n=0,cnt[100001]={0},tmp=0;

int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tmp;
        cnt[tmp]++;
    }
    for(int i=0;i<100001;++i){
        if(cnt[i]){cout<<i<<":"<<cnt[i]<<endl;}
    }
}