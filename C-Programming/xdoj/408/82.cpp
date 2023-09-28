#include<bits/stdc++.h>
using namespace std;

int main(){
    char score=0,len=0,passwd[128]={0},cap=0,low=0,num=0,cha=0;
    gets(passwd);
    len=strlen(passwd);
    if(!len){cout<<0; return 0;}
    if(len<=8){len=1;}
    else if(len>8){len=2;}
    for(int i=0;i<strlen(passwd);++i){
        if('A'<=passwd[i]&&passwd[i]<='Z'){cap=1;}
        else if('a'<=passwd[i]&&passwd[i]<='z'){low=1;}
        else if('0'<=passwd[i]&&passwd[i]<='9'){num=1;}
        else{cha=1;}
    }
    printf("%d",len+cap+low+num+cha-1);
}