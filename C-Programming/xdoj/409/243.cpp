#include<bits/stdc++.h>
using namespace std;

struct STU{
    char n[21]={0};
    int s=0,e=0;
}stu[101];

bool cmp(STU x,STU y){
    if(x.s==y.s){return x.e>y.e;}
    return x.s>y.s;
}

int main(){
    int n=0; cin>>n;
    for(int i=0;i<n;++i){
        int s1=0,s2=0,s3=0,s4=0,s5=0,e=0;
        cin>>stu[i].n>>s1>>s2>>s3>>s4>>s5>>e;
        stu[i].s=s1+s2+s3+s4+s5+e;
        stu[i].e=e;
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<n;++i){
        cout<<stu[i].n<<" "<<stu[i].s<<" "<<stu[i].e<<endl;
    }
}