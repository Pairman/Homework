#include<bits/stdc++.h>

int main(){
    int score;
    scanf("%d",&score);
    score/=10;
    switch(score){
        case 10: printf("A\n"); break;
        case 9: printf("A\n"); break;
        case 8: printf("B\n"); break;
        case 7: printf("C\n"); break;
        case 6: printf("D\n"); break;
        default: printf("E\n");
    }
    return 0;
}