#include<bits/stdc++.h>
using namespace std;

int *change(int a[],int n){
    int max=a[0],min=a[0];
    for(int i=0;i<n;++i){
        if(a[i]>=max){max=a[i];}
        if(a[i]<=min){min=a[i];}
    }
    int *p=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;++i){
        if(a[i]==max){p[i]=min; continue;}
        if(a[i]==min){p[i]=max; continue;}
        p[i]=a[i];
    }
    return p;
}

int main(){
    int n=0,a[21]={0}; cin>>n;
    for(int i=0;i<n;++i){cin>>a[i];}
    int *p=change(a,n);
    cout<<p[0];
    for(int i=1;i<n;i++){
        cout<<" "<<p[i];
    }
}