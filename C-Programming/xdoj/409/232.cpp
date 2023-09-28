#include<bits/stdc++.h>
using namespace std;

int main(){
    char str[51]={0}; gets(str);
    for(int i=0;i<strlen(str);++i){
        if(str[i]!=str[strlen(str)-1-i]){cout<<"no"; return 0;}
    }
    cout<<"yes";
}