#include<bits/stdc++.h>
using namespace std;

int main(){
	char str[51]={0},str1[51]={0},ch=0,i=0,j=0; gets(str); cin>>ch;
	for(i=0;i<strlen(str);++i){
		if(str[i]!=ch){str1[j]=str[i]; ++j;}
	}
	cout<<str1;
}