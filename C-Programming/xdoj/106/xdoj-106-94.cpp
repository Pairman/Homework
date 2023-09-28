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
    printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
    return 0;
}