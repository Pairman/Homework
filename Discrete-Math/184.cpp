#include<iostream>
#include<cstring>
#include<bitset>
#define ull unsigned long long
using namespace std;

inline ull ibpow(int exp){
    if(!exp){
        return 1;
    }
    return 2*ibpow(exp-1);
}

inline ull length(int paircount){
    if(paircount==0){
        return 2;
    }
    if(paircount==1){
        return 7;
    }
    return 6*paircount+1;
}


int main(){
    // Input n
    int n=0;
    cin>>n;

    // Input the set and split the elements.
    char input[2048]={0};
    cin>>input;
    char ele[1024]={0};
    for(int i=0;i<n;++i){
        ele[i]=input[2*i+1];
    }

    char result[1024][1024]={0};
    ull statell=0;
    ull matlen=ibpow(n*n);
    for(int l=0;l<matlen;++l){
        bitset<1024> state(statell);
        // Do work there:
        ull indexforresult=0;
        result[l][indexforresult]='{';
        ++indexforresult;
        bool flagforindent=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(state[i*n+j]){
                    if(flagforindent){
                        result[l][indexforresult]=',';
                        ++indexforresult;
                    }
                    flagforindent=1;

                    result[l][indexforresult]='<';
                    ++indexforresult;
                    result[l][indexforresult]=ele[i];
                    ++indexforresult;
                    result[l][indexforresult]=',';
                    ++indexforresult;
                    result[l][indexforresult]=ele[j];
                    ++indexforresult;
                    result[l][indexforresult]='>';
                    ++indexforresult;
                }
            }
        }
        result[l][indexforresult]='}';
        ++statell;
    }

    for(int l=0;l<matlen;++l){
        for(int m=l+1;m<matlen;++m){
            if(strlen(result[l])>strlen(result[m])){
                char tmp[1024]={0};
                strcpy(tmp,result[m]);
                strcpy(result[m],result[l]);
                strcpy(result[l],tmp);
            }
        }
    }

    for(int l=0;l<matlen;++l){
        for(int m=l+1;m<matlen;++m){
            if(strlen(result[l])==strlen(result[m])){
                if(strcmp(result[l],result[m])>0){
                    char tmp[1024]={0};
                    strcpy(tmp,result[m]);
                    strcpy(result[m],result[l]);
                    strcpy(result[l],tmp);
                }
            }
        }
    }

    for(int l=0;l<matlen;++l){
        cout<<result[l]<<endl;
    }

}