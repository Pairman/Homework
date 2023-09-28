#include<bits/stdc++.h>

int main(){
    int a[4];
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3-i;j++){
            if(a[j]>a[j+1]){
                int t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    printf("%d\n",a[3]);
    return 0;
}