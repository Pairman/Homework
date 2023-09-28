#include<iostream>
using namespace std;

double cos(double a,double b,double c){
    return (b*b+c*c-a*a)/(2*b*c);
}

int main(){
    double a=0,b=0,c=0;
    cin>>a>>b>>c;

    if(a<=0||b<=0||c<=0){
        cout<<"error";
        return 0;
    }

    if(!(a+b>c&&b+c>a&&c+a>b)){
        cout<<"error";
        return 0;
    }

    if(a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b){
        cout<<"right angled triangle";
        return 0;
    }

    if(cos(a,b,c)<0||cos(b,c,a)<0||cos(c,a,b)<0){
        cout<<"obtuse angled triangle";
        return 0;
    }

    cout<<"acute angled triangle";
}