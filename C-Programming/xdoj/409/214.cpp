#include<bits/stdc++.h>
using namespace std;

int *count(char *str){
    char a=0;
    int i=0,l=strlen(str),*n=(int*)calloc(5,sizeof(int));
    for(;i<l;++i){
        a=str[i];
        if('A'<=a&&a<='Z'){++n[0];}
        else if('a'<=a&&a<='z'){++n[1];}
        else if(a==' '){++n[2];}
        else if('0'<=a&&a<='9'){++n[3];}
        else{++n[4];}
    }
    return n;
}

int main(){
    char str[101]={0}; gets(str);
    int *n=count(str);
    cout<<n[0]<<" "<<n[1]<<" "<<n[2]<<" "<<n[3]<<" "<<n[4];
}