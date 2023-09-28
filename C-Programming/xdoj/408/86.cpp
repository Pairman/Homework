#include<bits/stdc++.h>
using namespace std;

int min(int x,int y){
    return x<=y?x:y;
}

int max(int x,int y){
    return x>=y?x:y;
}

int main(){
    int area=0,xmax=0,xmin=101,x=0,x1=0,x2=0,ymax=0,ymin=101,y=0,y1=0,y2=0,n=0,image[101][101]={0};
    cin>>n;
    while(n--){
        cin>>x1>>y1>>x2>>y2;
        if(min(x1,x2)<=xmin){xmin=min(x1,x2);}
        if(max(x1,x2)>=xmax){xmax=max(x1,x2);}
        if(min(y1,y2)<=ymin){ymin=min(y1,y2);}
        if(max(y1,y2)>=ymax){ymax=max(y1,y2);}
        for(x=min(x1,x2);x<max(x1,x2);++x){
            for(y=min(y1,y2);y<max(y1,y2);++y){image[x][y]=1;}
        }
    }
    for(x=xmin;x<xmax;++x){
        for(y=ymin;y<ymax;++y){
            if(image[x][y]){area++;}
        }
    }
    cout<<area;
}