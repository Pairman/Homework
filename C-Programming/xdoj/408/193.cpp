#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum=0,min=100,max=0,n=0,score[11]={0}; cin>>n;
    for(int i=0;i<n;++i){
        cin>>score[i];
        sum+=score[i];
        if(score[i]<=min){min=score[i];}
        if(score[i]>=max){max=score[i];}
    }
    printf("%.2lf",(double)(sum-max-min)/(n-2));
}