
#include<iostream>
using namespace std;

int dayinyear(int y,int m,int d){

	int monthlength[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i,sum=d;
    if((0==y%4&&y%100!=0)||(0==y%400)){
        ++monthlength[2];
    }

    if(m>12||m<1||d<1||d>monthlength[m]){
        return 0;
    }

	for(i=0;i<m;++i)
	{
		sum+=monthlength[i];
	}
	return sum;
}
int main(){
    int y=0,m=0,d=0;
	cin>>y>>m>>d;
    if(dayinyear(y,m,d)){
        cout<<dayinyear(y,m,d);
    }
    else{
        cout<<"error";
    }
	return 0;
}