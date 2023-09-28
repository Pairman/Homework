#include<bits/stdc++.h>
using namespace std;

int len(char *str){
    return strlen(str);
}

int main(){
    char *str=(char*)calloc(101,sizeof(char)); gets(str);
    cout<<len(str);
}