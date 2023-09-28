#include<bits/stdc++.h>
using namespace std;

int main(){
    char str[255]={0}; gets(str);
    sort(str,str+strlen(str));
    cout<<str;
}