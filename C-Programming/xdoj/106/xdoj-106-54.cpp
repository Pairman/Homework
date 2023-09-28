#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            for(int c=0;c<10;c++){
                if(101*(a+c)+20*b==n){
                    printf("%d %d %d\n",a,b,c);
                }
            }
        }
    }
    return 0;
}