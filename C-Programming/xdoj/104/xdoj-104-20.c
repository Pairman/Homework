#include<stdio.h>

int main(){
    int a,b; char o;
    scanf("%d%c%d",&a,&o,&b);
    printf("%d%c%d=",a,o,b);

    switch(o){
        case '+':
            printf("%d",a+b);
            break;
        case '-':
            printf("%d",a-b);
            break;
        case '*':
            printf("%d",a*b);
            break;
        case '/':
            printf("%d",a/b);
            break;
        case '%':
            printf("%d",a%b);
            break;
    }
    return 0;
}