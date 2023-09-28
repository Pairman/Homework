#include <bits/stdc++.h>
using namespace std;

int main(){
    int y=0,m=0,d=0; cin>>y>>m>>d;
    if(m==1||m==2){m+=12; --y;}
    int w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    switch(w){
        case 0: cout<<"Monday"; break;
        case 1: cout<<"Tuesday"; break;
        case 2: cout<<"Wendnesday"; break;
        case 3: cout<<"Thursday"; break;
        case 4: cout<<"Friday"; break;
        case 5: cout<<"Saturday"; break;
        case 6: cout<<"Sunday"; break;
    }
}