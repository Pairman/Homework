#include<bits/stdc++.h>

int main(){
    char ch[512]={'\0'};
    gets(ch);

    int sum=0;
    int i=0;
    while(ch[i]!='\0'){
        
        sum*=16;
        switch(ch[i]){
            case '0': sum+=0; break;
            case '1': sum+=1; break;
            case '2': sum+=2; break;
            case '3': sum+=3; break;
            case '4': sum+=4; break;
            case '5': sum+=5; break;
            case '6': sum+=6; break;
            case '7': sum+=7; break;
            case '8': sum+=8; break;
            case '9': sum+=9; break;
            case 'A': sum+=10; break;
            case 'B': sum+=11; break;
            case 'C': sum+=12; break;
            case 'D': sum+=13; break;
            case 'E': sum+=14; break;
            case 'F': sum+=15; break;
            case 'a': sum+=10; break;
            case 'b': sum+=11; break;
            case 'c': sum+=12; break;
            case 'd': sum+=13; break;
            case 'e': sum+=14; break;
            case 'f': sum+=15; break;
        }
        i++;
    }
    printf("%d",sum);
}