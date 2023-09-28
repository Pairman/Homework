#include<bits/stdc++.h>
using namespace std;

bool num(char x){return '0'<=x&&x<='9';}

bool let(char x){return !num(x);}

int main(){
    char str[101]={0},tmp=0; gets(str);
    int i=0,repeat=0;
    while(i<strlen(str)){
        if(let(str[i])&&num(str[i+1])){tmp=str[i];}
        if(num(str[i])){repeat=10*repeat+str[i]-'0';}
        if(num(str[i])&&let(str[i+1])){
            for(int j=0;j<repeat;++j){cout<<tmp;}
            repeat=0;
        }
        if(let(str[i])&&let(str[i+1])){cout<<str[i];}
        ++i;
    }
}