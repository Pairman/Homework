#include<bits/stdc++.h>
#define elif else if
using namespace std;

int sum(int n){
    int s=0;
    while(n){s+=n%10; n/=10;}
    return s;
}

int palindrome(int n){
    char str[12]={0};
    sprintf(str,"%d",n);
    int len=strlen(str),m=len/2;
    if(len%2){goto odd;}
    for(int i=0;i<=m;++i){
        if(str[m-i]!=str[m-1+i]){return 0;}
    }
    return 1;
    odd:
    for(int i=0;i<=m;++i){
        if(str[m-i]!=str[m+i]){return 0;}
    }
    return 1;
}

int main(){
    int n=0; cin>>n;
    if(palindrome(n)){cout<<sum(n);}
    else{cout<<"no";}
}