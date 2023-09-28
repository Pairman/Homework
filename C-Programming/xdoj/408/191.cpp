#include<bits/stdc++.h>
using namespace std;

int main(){
    char str[8]={0}; gets(str);
    for(int i=0;i<7;i++){
        if('A'<=str[i]&&str[i]<='Z'){str[i]='Z'+'A'-str[i];}
        if('a'<=str[i]&&str[i]<='z'){str[i]='z'+'a'-str[i];}
        cout<<str[i];
    }
}