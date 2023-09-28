#include<bits/stdc++.h>
using namespace std;

int a[10]={1,2,3,4,5,6,7,8,9,10};


int main(){
    int p=0; cin>>p;
    cout<<a[(p+1)%10];
    for(int i=p+2;i<p+11;++i){cout<<" "<<a[i%10];}
}