#include<stdio.h>

int main(){
    int a,b,c[4],i,j;
    scanf("%d %d",&a,&b);
    c[0]=(a+b)*(a+b);
    c[1]=(a-b)*(a-b);
    c[2]=a*a+b*b;
    c[3]=a*a-b*b;
    for(i=0;i<=3;i++){
        for(j=0;j<=2-i;j++){
            if(c[j]>=c[j+1]){
                int t=c[j];
                c[j]=c[j+1];
                c[j+1]=t;
            }
        }
    }
    printf("%d %d",c[3],c[0]);
    return 0;
}