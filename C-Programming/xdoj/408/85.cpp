#include<bits/stdc++.h>
using namespace std;

unsigned compare(char s1[],char s2[]){
    unsigned mat[100][100]={0},l1=strlen(s1),l2=strlen(s2),max=0;
	for(int i=0;i<l1;++i){
		for(int j=0;j<l2;++j){
			if(s1[i]==s2[j]||abs(s1[i]-s2[j])==32){
				if(i&&j){mat[i][j]=mat[i-1][j-1]+1;}
				else{mat[i][j]=1;};
			}
            if(mat[i][j]>=max){max=mat[i][j];}
		}
	}
    return max;
}

int main(){
    char s1[101]={0},s2[101]={0}; gets(s1); gets(s2);

    printf("%.3lf",(double)2*compare(s1,s2)/(strlen(s1)+strlen(s2)));
}