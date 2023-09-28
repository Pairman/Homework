#include<bits/stdc++.h>
#define elif else if
using namespace std;

struct NUM{
    int num=0;
    int sum=0;
}num[1001];

bool cmp(NUM x,NUM y){
    if(x.sum==y.sum){return x.num<y.num;}
    return x.sum>y.sum;
}

int sum(int n){
    int s=0;
    while(n){
        s+=n%10;
        n/=10;
    }
    return s;
}

int main(){
    int n=0; cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i].num;
        num[i].sum=sum(num[i].num);
    }
    sort(num,num+n,cmp);
    for(int i=0;i<n;i++){
        cout<<num[i].num<<" "<<num[i].sum<<endl;
    }
}