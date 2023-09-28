#include<bits/stdc++.h>

int *count(char ch[]){
    int let=0,num=0;
    int i=0;    
    do{
        if(('a'<=ch[i]&&ch[i]<='z')||('A'<=ch[i]&&ch[i]<='Z')){
            let++;
        } else if('0'<=ch[i]&&ch[i]<='9'){
            num++;
        }
        i++;
    }while(ch[i]!='\0'&&i!=0);
    
    int *result=(int *)malloc(2*sizeof(int));
    result[0]=let;
    result[1]=num;

    return result;
}

int main(){
    char ch[512]={};
    gets(ch);

    int *ret=count(ch);
    printf("%d,%d",ret[0],ret[1]);
}