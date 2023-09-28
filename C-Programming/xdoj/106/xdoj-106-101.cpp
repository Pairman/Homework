#include<bits/stdc++.h>

int main(){
    char d[4];
    for(int i=0;i<4;i++)
        scanf("%c",&d[i]);
    for(int i=0;i<4;i++){
        if('a'<=d[i]&&d[i]<='z'){
            d[i]=d[i]-32;
        } else if('A'<=d[i]&&d[i]<='Z'){
            d[i]=d[i]+32;
        } else if('0'<=d[i]&&d[i]<='9'){
            d[i]='*';
        } else{
            d[i]='@';
        }
    }
    printf("%c%c%c%c\n",d[0],d[1],d[2],d[3]);
    return 0;
}