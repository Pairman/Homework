#include<bits/stdc++.h>

int isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);

    switch(isPrime(n)){
        case 0:
            printf("NO");
            break;
        case 1:
            printf("YES");
    }
}