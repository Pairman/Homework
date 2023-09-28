#include<bits/stdc++.h>

int len(int n){
    int len;
    while(n!=0){
        len++;
        n/=10;
    }
    return len;
}

int function(int a,int b){
    int count=0;
    
    if(a<100){
        if(b<100){
            return 0;
        }
        a=100;
    }

    for(int n=a;n<=b;n++){
        int sum= pow((n%10),len(n)) + pow((n%100-n%10)/10,len(n)) + pow((n%1000-n%100)/100,len(n)) + pow((n%10000-n%1000)/1000,len(n));
        if(sum==n){
            count++;
        }
    }
    return count;
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    printf("%d",function(a,b));
}