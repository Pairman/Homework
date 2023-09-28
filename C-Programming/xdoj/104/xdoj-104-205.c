#include<stdio.h>

void tow(int a,int n){
    for(int i=1;i<=n;i++){
        for(int j=n-i-1;j>=0;j--){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            if(j!=i){
                printf("%c ",a);
            } else{
                printf("%c",a);
            }
        }
        printf("\n");
    }
}

int main(){
    char a;
    int n;
    scanf("%c",&a);
    scanf("%d",&n);
    tow(a,n);
    return 0;
}