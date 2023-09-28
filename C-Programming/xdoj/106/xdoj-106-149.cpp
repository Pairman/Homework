#include<bits/stdc++.h>

int main(){
    unsigned int n;
    double sum=0;
    scanf("%d",&n);
    for(unsigned int i=1;i<=n;i++){
        sum+=1.0*pow(-1,i+1)*i/(2*i-1);
    }
    printf("%.3lf\n",sum);
    return 0;
}