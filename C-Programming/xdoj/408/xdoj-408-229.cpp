#include<bits/stdc++.h>

void fun(char line1[],char line2[]){
    for(int i=0;i<strlen(line1);i++){
        printf("%c",line1[i]);
    }
    for(int i=0;i<strlen(line2);i++){
        printf("%c",line2[i]);
    }
}

int main(){
    char line1[512]={},line2[512]={};
    gets(line1);
    gets(line2);

    fun(line1,line2);
}