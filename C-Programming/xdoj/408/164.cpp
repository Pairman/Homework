#include<bits/stdc++.h>
using namespace std;

int main(){
    char str[81]={0},len=0,cap[81]={0},count=0;
    gets(str); len=strlen(str);
    for(int i=0;i<len;++i){
        if('a'<=str[i]&&str[i]<='z'){str[i]-=32;}
        if('A'<=str[i]&&str[i]<='Z'){cap[count]=str[i]; count++;}
    }
    sort(cap,cap+count);
    for(int i=0,j=0;i<len;++i){
        if('A'<=str[i]&&str[i]<='Z'){cout<<cap[j];j++;}
        else{cout<<str[i];}
    }
}