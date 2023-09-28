#include<bits/stdc++.h>

int jud(int n){
    if(n%7!=0&&n%11!=0){
        return 0;
    } if(n%77==0){
        return 0;
    }
    return 1;
}

int main(){
    int count=0;
    for(int i=100;i<500;i++){
        count+=jud(i);
    }
    printf("%d\n",count);
    return 0;
}