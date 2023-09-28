#include<bits/stdc++.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    int mc=0,ms=0;
    for(int i=1;i<m;i++){
        if(m%i==0){
            ms+=i;
            mc++;
        }
    }

    int nc=0,ns=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            ns+=i;
            nc++;
        }
    }

    if(m==ns&&n==ms){
        printf("yes %d %d\n",mc,nc);
    } else{
        printf("no %d %d\n",mc,nc);
    }
    return 0;
}