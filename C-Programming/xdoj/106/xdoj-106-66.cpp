#include<bits/stdc++.h>

int main(){
    int n,a,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        sum+=a;
    }
    double avg=1.0*sum/n;
    printf("%.2lf\n",avg);
    return 0;
}