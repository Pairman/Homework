#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=0,j=0,h=0,w=0,image[101][101]={0}; cin>>h>>w;
    for(i=0;i<h;++i){
        for(j=0;j<w;++j){cin>>image[i][j];}
    }
    for(j=0;j<w;j++){
        cout<<image[h-1][j];
        for(i=h-2;i>=0;i--){cout<<" "<<image[i][j];}
        cout<<endl;
    }
}