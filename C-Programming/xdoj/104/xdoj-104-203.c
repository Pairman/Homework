#include<stdio.h>

int cal(int a,int b,int o){
    int r;
    switch(o){
        case '+':
            r=a+b;
            break;
        case '-':
            r=a-b;
            break;
        case '*':
            r=a*b;
            break;
        case '/':
            r=a/b;
            break;
        case '%':
            r=a%b;
            break;
    }
    return r;
}

int main(){
    int a,b;
    char o;
    scanf("%d %d %c",&a,&b,&o);
    printf("%d%c%d=%d",a,o,b,cal(a,b,o));
}
