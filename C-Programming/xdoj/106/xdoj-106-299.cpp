#include<bits/stdc++.h>

int main(){
    int i,o;
    scanf("%d",&i);
    if(i<=100000){
        o=0.1*i;
    } else if(i<=200000){
        o=0.1*100000+0.075*(i-100000);
    } else if(i<=400000){
        o=0.1*100000+0.075*100000+0.05*(i-200000);
    } else if(i<=600000){
        o=0.1*100000+0.075*100000+0.05*200000+0.03*(i-400000);
    } else if(i<=1000000){
        o=0.1*100000+0.075*100000+0.05*200000+0.03*200000+0.015*(i-600000);
    } else{
        o=0.1*100000+0.075*100000+0.05*200000+0.03*200000+0.015*400000+0.01*(i-1000000);
    }
    printf("%d\n",o);
    return 0;
}