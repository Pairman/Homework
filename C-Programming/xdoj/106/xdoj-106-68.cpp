#include<bits/stdc++.h>

int leap(int y){
    if(y%400==0){
        return 1;
    } else{
        if(y%4==0&&y%100!=0){
            return 1;
        }
    }
    return 0;
}

void date(int a){
    int m,d;
    if(a<=31){
        m=1; d=a;
    } else if(a<=59){
        m=2; d=a-31;
    } else if(a<=90){
        m=3; d=a-59;
    } else if(a<=120){
        m=4; d=a-90;
    } else if(a<=151){
        m=5; d=a-120;
    } else if(a<=181){
        m=6; d=a-151;
    } else if(a<=212){
        m=7; d=a-181;
    } else if(a<=243){
        m=8; d=a-212;
    } else if(a<=273){
        m=9; d=a-243;
    } else if(a<=304){
        m=10; d=a-273;
    } else if(a<=334){
        m=11; d=a-304;
    } else{
        m=12; d=a-334;
    }
    printf("%d %d\n",m,d);
}

void datel(int a){
    int m,d;
    if(a<=31){
        m=1; d=a;
    } else if(a<=60){
        m=2; d=a-31;
    } else if(a<=91){
        m=3; d=a-60;
    } else if(a<=121){
        m=4; d=a-91;
    } else if(a<=152){
        m=5; d=a-121;
    } else if(a<=182){
        m=6; d=a-152;
    } else if(a<=213){
        m=7; d=a-182;
    } else if(a<=244){
        m=8; d=a-213;
    } else if(a<=274){
        m=9; d=a-244;
    } else if(a<=305){
        m=10; d=a-274;
    } else if(a<=335){
        m=11; d=a-305;
    } else{
        m=12; d=a-335;
    }
    printf("%d %d\n",m,d);
}

int main(){
    int y,d;
    scanf("%d %d",&y,&d);
    if(leap(y)==0){
        date(d);
    } else{
        datel(d);
    }
    return 0;
}