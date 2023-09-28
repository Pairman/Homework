#include<bits/stdc++.h>
using namespace std;

int main(){
    char str[51]={0}; gets(str);
    int m=0; cin>>m;
    if(strlen(str)<m){cout<<"error"; return 0;}
    for(int i=m-1;i<strlen(str);++i){cout<<str[i];}
}