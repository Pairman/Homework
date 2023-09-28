#include<bits/stdc++.h>

int count(char ch[]){
    int let=0;

    int i=0;
    do{
        if(('a'<=ch[i]&&ch[i]<='z')||('A'<=ch[i]&&ch[i]<='Z')){
            let++;
        }
        i++;
    }while(ch[i]!='\0'&&i!=0);
    
    return let;
}

int main(){
    char ch[512]={};
    gets(ch);

    printf("%d",count(ch));
}