#include<bits/stdc++.h>

int main(){
    char str[200];
    gets(str);

    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    for(int i=len-1;i>=0;i--){
        printf("%c",str[i]);
    }
}