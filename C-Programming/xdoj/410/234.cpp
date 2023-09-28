#include<bits/stdc++.h>
using namespace std;

struct STU{
    int id=0,s1=0,s2=0,s3=0;
    double s=0;
    char n[21]={0};
}stu[101];

bool cmp(STU x,STU y){
    return x.s>y.s;
}

int main(){
    int n=0; cin>>n;
    for(int i=0;i<n;++i){
        cin>>stu[i].id>>stu[i].n>>stu[i].s1>>stu[i].s2>>stu[i].s3;
    stu[i].s=(double)(stu[i].s1+stu[i].s2+stu[i].s3)/3;
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<n;++i){printf("%d %s %.1lf\n",stu[i].id,stu[i].n,stu[i].s);}
}