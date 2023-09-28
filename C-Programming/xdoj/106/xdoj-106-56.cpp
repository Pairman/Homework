#include<bits/stdc++.h>

int main(){
    int a,b,c,a1,b1,c1;
    scanf("%d %d %d",&a,&b,&c);
    a1=a*a;
    b1=b*b;
    c1=c*c;
    if(a1+b1==c1||b1+c1==a1||c1+a1==b1){
        double p=0.5*(a+b+c),s;
        s=2.0*pow(p*(p-a)*(p-b)*(p-c),0.5);
        printf("%.0lf\n",s);
    } else{
        printf("no\n");
    }
    return 0;    
}
