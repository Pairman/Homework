#include<bits/stdc++.h>
using namespace std;

struct NUM{
    int n=0,i=0;
}num[5];

bool cmp(NUM x,NUM y){
    return x.i>y.i;
}

int main(){
    scanf("%d,%d,%d,%d,%d",&num[0].n,&num[1].n,&num[2].n,&num[3].n,&num[4].n);
    for(int i=0;i<5;++i){num[i].i=i;}
    sort(num,num+5,cmp);
    cout<<num[0].n;
    for(int i=1;i<5;++i){cout<<" "<<num[i].n;}
}