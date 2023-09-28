#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    scanf("%d",&n);
    
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    
    sort(array,array+n);

    for(int tmp=-1,count=1,i=0;i<=n;i++){
        if(array[i]==tmp){
            count++;
        } else if(i!=0&&array[i]!=tmp){
            printf("%d:%d\n",array[i-1],count);
            tmp=array[i];
            count=1;
        }
    }
}