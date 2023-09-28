#include<bits/stdc++.h>

int main(){
    
    int n,tmp=0,flag=0,score=0;
    scanf("%d",&n);
    while(n!=0){
        if(n==1){
            flag=1;
        }
        if(n==2){
            if(tmp==1){
                flag=2;
            } else{
                flag+=2;
            }
        }
        score+=flag;
        tmp=n;
        scanf("%d",&n);
    }
    printf("%d",score);
    return 0;
}