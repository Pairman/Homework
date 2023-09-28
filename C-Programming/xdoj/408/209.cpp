#include<bits/stdc++.h>
using namespace std;

char *char_cp(char str[],int m){
    int len=strlen(str)-m;
    char *p=(char*)calloc(len,sizeof(char));
    for(int i=0;i<len;++i){
        p[i]=str[m+1+i];
    }
    return p;
}
int main(){
    char str[51]={0}; gets(str);
    int m=0; cin>>m;
    cout<<char_cp(str,m);
}