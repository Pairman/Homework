#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,max=-32768,a[81]={0}; cin>>n;
    for(int i=0;i<n;++i){cin>>a[i]; if(a[i]>=max){max=a[i];}}
    
    cout<<n<<" "<<max;
    for(int i=0;i<n;++i){if(a[i]==max){cout<<" "<<i;}}
}