#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=0,n=0,num[31]={-1},tmp=0,count=0; cin>>n;
    for(i=0;i<n;i++){cin>>num[i];}
    sort(num,num+n);
    for(i=0;i<n;i++){
        if(num[i]==tmp){count++;}
        else{
            if(count){cout<<tmp<<":"<<count<<endl;}    
            tmp=num[i]; count=1;
        }
        if(i==n-1){cout<<tmp<<":"<<count<<endl;}
    }
}