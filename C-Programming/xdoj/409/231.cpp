#include<bits/stdc++.h>
using namespace std;

int main(){
    char tmp=0,word[101][101]={0};
    int i=0,count=1,maxl=0;
    while(1){
        tmp=getchar();
        if(tmp==' '){i=0; ++count;}
        else if(tmp=='.'){++count; break;}
        else{word[count][i]=tmp; ++i;}
        if(strlen(word[count])>=maxl){maxl=strlen(word[count]);}
    }
    cout<<maxl;
}