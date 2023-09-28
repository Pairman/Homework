#include<bits/stdc++.h>
using namespace std;

int value(char s[]){
    int sum=0;
    if(s[0]=='-'){   
        for(int i=1;i<strlen(s);++i){
            sum=10*sum+s[i]-'0';
        }
        return -sum;
    }
    for(int i=0;i<strlen(s);++i){
        sum=10*sum+s[i]-'0';
    }
    return sum;
}

int main(){
    char s1[10]={0},s2[10]={0},s3[10]={0},op=0;
    int n1=0,n2=0,ans=0;
    cin>>s1>>s2>>s3;
    if(s1[0]=='+'||s1[0]=='-'||s1[0]=='*'||s1[0]=='/'||s1[0]=='%'){op=s1[0]; n1=value(s2); n2=value(s3);}
    if(s2[0]=='+'||s2[0]=='-'||s2[0]=='*'||s2[0]=='/'||s2[0]=='%'){op=s2[0]; n1=value(s1); n2=value(s3);}
    if(s3[0]=='+'||s3[0]=='-'||s3[0]=='*'||s3[0]=='/'||s3[0]=='%'){op=s3[0]; n1=value(s1); n2=value(s2);}
    
    switch(op){
        case '+': ans=n1+n2; break;
        case '-': ans=n1-n2; break;
        case '*': ans=n1*n2; break;
        case '/': ans=n1/n2; break;
        case '%': ans=n1%n2; break;
    }
    cout<<ans;
}