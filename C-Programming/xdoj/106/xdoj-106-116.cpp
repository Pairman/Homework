#include<bits/stdc++.h>

int main(){
    double e,w=0;
    scanf("%lf",&e);
    if(e<=110){
        w=0.5*e;
    } if(110<e&&e<=210){
        w=0.5*110+0.55*(e-110);
    } if(e>210){
        w=0.5*110+0.55*100+0.7*(e-210);
    }
    printf("%.2lf\n",w);
    return 0;
}