#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int e=0,k=0;
}term;

int polyN[114514]={0},polyM[114514]={0},polyS[114514]={0};

int main(){
    int n=0,m=0,t=0,k=0,e=0,eMax=0,eMin=114514,i=0;  cin>>n>>m>>t;
    if(t==1){t=-1;}
    else{t=1;}

    
    for(i=0;i<n;++i){
        cin>>k>>e; polyN[e]=k;
        if(e>eMax){eMax=e;}
        if(e<eMin){eMin=e;}
    }
    for(i=0;i<m;++i){
        cin>>k>>e; polyM[e]=k;
        if(e>eMax){eMax=e;}
        if(e<eMin){eMin=e;}
    }

    for(int i=eMin;i<=eMax;++i){polyS[i]=polyN[i]+t*polyM[i];}

    if(polyS[eMin]){
        if((polyS[eMin]==1&&eMin==0)||(polyS[eMin]!=1&&eMin>0)){cout<<polyS[eMin];}
        if(eMin==1){cout<<"x";}
        else if(eMin>1){cout<<"x^"<<eMin;}
    }
    for(int i=eMin+1;i<=eMax;++i){
        if(polyS[i]){
            cout<<"+";
            if((polyS[i]==1&&i==0)||(polyS[i]!=1&&i>0)){cout<<polyS[i];}
            if(i==1){cout<<"x";}
            else if(i>1){cout<<"x^"<<i;}
        }
    }
}