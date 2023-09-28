#include<bits/stdc++.h>
using namespace std;


int a[100000]={0},n=0;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){cin>>a[i];}
    a[0]>=a[n-1]?cout<<a[0]<<" ":cout<<a[n-1]<<" ";
    switch(n%2){
        case 0: cout<<(a[n/2-1]+a[n/2])/2; break;
        case 1: cout<<a[n/2];
    }
    a[0]<=a[n-1]?cout<<" "<<a[0]:cout<<" "<<a[n-1];
}