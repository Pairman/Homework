#include<bits/stdc++.h>

int main(){
    int matA[6]={}; int matB[6]={};
    scanf("%d %d %d %d %d %d\n%d %d %d %d %d %d",&matA[0],&matA[1],&matA[2],&matA[3],&matA[4],&matA[5],&matB[0],&matB[1],&matB[2],&matB[3],&matB[4],&matB[5]);
    printf("%d %d %d\n%d %d %d\n\n",matA[0],matA[1],matA[2],matA[3],matA[4],matA[5]);
    printf("%d %d\n%d %d\n%d %d\n\n",matB[0],matB[1],matB[2],matB[3],matB[4],matB[5]);
    printf("%d %d\n%d %d\n",matA[0]*matB[0]+matA[1]*matB[2]+matA[2]*matB[4],matA[0]*matB[1]+matA[1]*matB[3]+matA[2]*matB[5],matA[3]*matB[0]+matA[4]*matB[2]+matA[5]*matB[4],matA[3]*matB[1]+matA[4]*matB[3]+matA[5]*matB[5]);
}
