#include<bits/stdc++.h>

int main(){
    char str[100];
    gets(str);
    unsigned short sum=0;
    for(unsigned short i=0;i<strlen(str);i++){
        sum+=str[i];
    }
    printf("%d\n",sum&0xFF);
    return 0;
}