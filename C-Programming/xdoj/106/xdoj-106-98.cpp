#include<bits/stdc++.h>

int main(){
    double score;
    scanf("%lf",&score);
    printf("%.2lf ",score);
    int lvl=score/=10;
    switch(lvl){
        case 10: printf("A\n"); return 0;
        case 9: printf("A\n"); return 0;
        case 8: printf("B\n"); return 0;
        case 7: printf("C\n"); return 0;
        case 6: printf("D\n"); return 0;
        default: printf("E\n"); return 0;
    }
}