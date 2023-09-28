#include<bits/stdc++.h>
using namespace std;

struct STR{
    char s[20]={0};
}str[10];

bool cmp(STR x,STR y){
    if(strcmp(x.s,y.s)<=0){return 1;}
    return 0;
}

int main(){
    int n=0; cin>>n;
    for(int i=0;i<n;++i){cin>>str[i].s;}
    sort(str,str+n,cmp);
    for(int i=0;i<n;++i){
        cout<<str[i].s<<endl;
    }
}