#include<bits/stdc++.h>
using namespace std;

struct NUM{
    int n=0;
}num[21];

bool cmp(NUM x,NUM y){
    if(x.n%2==y.n%2){return x.n<y.n;}
    return x.n%2>y.n%2;
}

int main(){
    int n=0; cin>>n;
    for(int i=0;i<n;++i){cin>>num[i].n;}
    sort(num,num+n,cmp);
    int odd=num[1].n%2,even=!(num[n-1].n%2);

    cout<<num[0].n;
    if(odd==1){
        for(int i=1;i<n;++i){
            if(num[i].n%2){cout<<" "<<num[i].n;}
            else{break;}
        }
    }
    if(odd==1&&even==1){cout<<"   ";}
    if(even==1){
        for(int i=1;i<n-1;++i){
            if(!(num[i].n%2)){cout<<num[i].n<<" ";}
        }
        cout<<num[n-1].n;
    }
}