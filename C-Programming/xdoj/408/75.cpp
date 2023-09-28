#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
    int i=0,tmp=0,w=0,h=0,s=0,map[16]={0}; cin>>w>>h; s=w*h;
    for(i=0;i<s;++i){cin>>tmp; ++map[tmp];}
    for(i=0;i<16;++i){
        if(map[i]){cout<<i<<" "<<map[i]<<endl;}
    }
}