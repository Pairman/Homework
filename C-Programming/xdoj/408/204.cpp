#include<bits/stdc++.h>
using namespace std;

int count(char str[],char s[]){
    int i=0,count=0,pos=0,c=0;
    char word[101][9]={0};
    for(i=0;i<strlen(str);++i){
        if(str[i]!=' '){word[count][pos]=str[i]; ++pos;}
        else{++count; pos=0;}
    }
    for(i=0;i<=count;++i){
        if(!strcmp(word[i],s)){++c;}
    }
    return c;
}

int main(){
    char str[101]={0},s[9]={0}; gets(str); gets(s);
    cout<<s<<" "<<count(str,s);
}