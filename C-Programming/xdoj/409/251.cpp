#include<bits/stdc++.h>
using namespace std;

static unsigned short month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

bool isLeap(int y){
    if(y%4){return 0;}
    if(!(y%400)){return 1;}
    if(!(y%100)){return 0;}
    return 1;
}

int daycount(int y1,int m1,int d1,int y2,int m2,int d2){
    int daycount=0;
    while(y1<y2||m1<m2||d1<d2){
        d1++;
        if(d1==month[m1][isLeap(y1)]+1){m1++;d1=1;}
        if(m1==13){y1++;m1=1;}
        daycount++;
    }
    return daycount;
}

int main(){
    int y=0,m=0,d=0; scanf("%d,%d,%d",&y,&m,&d);
    cout<<daycount(y,1,0,y,m,d);
}