#include<stdio.h>

int main(){
    int day,haz,num;
    scanf("%d %d %d",&day,&haz,&num);
    num%=10;
    if(day==6||day==7){
        printf("%d no",num);
    } else{
        if(haz<200){
            printf("%d no",num);
        } else if(haz<400){
            if(num==day||num==(day+5)%10){
                printf("%d yes",num);
            } else{
                printf("%d no",num);
            }
        } else{
            if(num%2==day%2){
                printf("%d yes",num);
            } else{
                printf("%d no",num);
            }
        }
    }
}