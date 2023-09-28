#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;



int main(){
    int n=0,t=0;
    cin>>n;
    double *A=(double*)calloc(n,sizeof(double)),*B=(double*)calloc(n,sizeof(double));
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    for(int i=0;i<n;++i){
        cin>>B[i];
    }
    cin>>t;
    if(t==1){
        for(int i=0;i<n;++i){
            i&&printf(" ");
            printf("%.6lf",((A[i]<=B[i])?A[i]:B[i]));
        }
    }
    if(t==2){
        for(int i=0;i<n;++i){
            i&&printf(" ");
            printf("%.6lf",((A[i]>=B[i])?A[i]:B[i]));
        }
    }
    if(t==3){
        for(int i=0;i<n;++i){
            i&&printf(" ");
            printf("%.6lf",1-A[i]);
        }
    }
    free(A);
    free(B);
}