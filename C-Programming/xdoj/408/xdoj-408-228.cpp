#include<bits/stdc++.h>

void fun(char ch[]){
    for(int i=0;i<strlen(ch);i++){
        if(i%2==0){
            printf("%c",ch[i]);
        }
    }
}

int main(){
    char ch[512]={};
    gets(ch);

    fun(ch);
}