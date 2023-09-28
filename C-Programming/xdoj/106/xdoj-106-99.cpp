#include<bits/stdc++.h>

double fare(double e){
    double w;
    if(e<=110){
        w=0.5*e;
    } else if(e<=210){
        w=0.5*110+0.55*(e-110);
    } else{
        w=0.5*110+0.55*100+0.7*(e-210);
    }
    return w;
}

char level(double e){
    char l;
    if(e<=110){
        l='A';
    } else if(e<=210){
        l='B';
    } else{
        l='C';
    }
    return l;
}

double exceed(double e){
    double w;
    if(e<=110){
        w=0.00;
    } else if(e<=210){
        w=e-110;
    } else{
        w=e-210;
    }
    return w;
}

int main(){
    double e;
    scanf("%lf",&e);
    printf("%.2lf %c %.2lf\n",fare(e),level(e),exceed(e));
    return 0;
}