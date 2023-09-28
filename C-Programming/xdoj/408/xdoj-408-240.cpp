#include<bits/stdc++.h>
#define elif else if
using namespace std;

int len(int n){
    if(n==0){return 1;}
    int l=0;
    while(n!=0){
        n/=10;
        l++;
    }
    return l;
}

int main(){
    int n=0; cin>>n;
    char str[20]={'\0'};
    int i=len(n);
    if(n==0){str[0]='0';}
    elif(n<0){
        str[0]='-'; n=-n;
        while(i--){str[i+1]='0'+n%10; n/=10;}
    }
    elif(n>0){
        while(i--){str[i]='0'+n%10; n/=10;}
    }
    cout<<str;
}