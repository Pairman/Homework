#include<bits/stdc++.h>
using namespace std;

int factor(int n){
	int f=-1;
	for(int i=2;i<n;++i){
		if(!(n%i)){f=i;}
	}
	if(f==-1){return n;}
	return f;
}

int main(){
	char str[101]={0}; gets(str);
	int num=0,count=0;
	for(int i=0;i<strlen(str);++i){
		if('0'<=str[i]&&str[i]<='9'){num=10*num+str[i]-'0';}
	}
	cout<<factor(num);
}