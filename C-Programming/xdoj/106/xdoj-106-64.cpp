#include<bits/stdc++.h>

int main(){
    int m,a;
    scanf("%d",&m);

    for(int i=1;;i+=2){
        if((i+m-1)==m*m){
            a=i;
            break;
        }
    }
    for(int i=a;i<a+2*m-2;i+=2){
        printf("%d ",i);
    }
    printf("%d\n",a+2*m-2);
    return 0;
}