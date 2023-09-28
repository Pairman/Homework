#include<bits/stdc++.h>
using namespace std;

bool cmp(char x,char y){
    return x<y;
}

int main(){
    char str[101]={0},a=0; gets(str); a=str[0];
    for(int i=0;i<strlen(str);++i){
        if(str[i]>a){cout<<str[i];}
    }
    sort(str,str+strlen(str),cmp);

    for(int i=0;i<strlen(str);++i){
        if(str[i]<=a){cout<<str[i];}
    }
}