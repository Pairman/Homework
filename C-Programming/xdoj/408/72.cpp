#include<bits/stdc++.h>
using namespace std;

int main(){
    char max[101]={0},tmp[101]={0};
    while(1){
        gets(tmp);
        if(!strcmp(tmp,"***end***")){break;}
        if(strlen(tmp)>strlen(max)){strcpy(max,tmp);}
    }
    cout<<strlen(max)<<endl<<max;
}