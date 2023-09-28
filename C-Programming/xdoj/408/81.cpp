#include<bits/stdc++.h>
using namespace std;

unsigned compare(char s1[],char s2[],bool flag){
    unsigned mat[100][100]={0},l1=strlen(s1),l2=strlen(s2),max=0;
	for(int i=0;i<l1;++i){
		for(int j=0;j<l2;++j){
			if((flag&&s1[i]==s2[j])||((!flag)&&abs(s1[i]-s2[j])==32)){
				if(i&&j){mat[i][j]=mat[i-1][j-1]+1;}
				else{mat[i][j]=1;};
			}
            if(mat[i][j]>=max){max=mat[i][j];}
		}
	}
    return max;
}

int main(){
    char word[101]={0},word1[101]={0},str[101][101]={0},str1[101][101]={0}; gets(word); strcpy(word1,word);
    bool flag=0; int n=0; cin>>flag>>n;
    for(int i=0;i<n;++i){cin>>str[i]; strcpy(str1[i],str[i]);}

    for(int i=0;i<n;++i){
        if(compare(word,str[i],flag)==strlen(word)){cout<<str[i]<<endl;}
    }
}