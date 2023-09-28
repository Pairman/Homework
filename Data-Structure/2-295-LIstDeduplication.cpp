#include<algorithm>
#include<vector>
#include<iostream>

int main(){
	std::vector<int> l1,l2,l3;
	int a,b,tmp;
	std::cin>>a>>b;
	for(int i=0;i<a;++i){
		std::cin>>tmp;
		l1.push_back(tmp);
	}

	for(int i=0;i<b;++i){
		std::cin>>tmp;
		l2.push_back(tmp);
	}

	l3.resize(l1.size()+l2.size());
	std::merge(l1.begin(),l1.end(),l2.begin(),l2.end(),l3.begin());

	std::vector<int>::iterator p=l3.begin()+1;
	while(p!=l3.end()){
		if(*p==*(p-1)){
			p=l3.erase(p);
		}
		else{
			++p;
		}
	}

	for(int i=0;i<l3.size();++i){
		std::cout<<l3[i]<<" ";
	}
}

/*
6 7
1 2 5 6 10 13
1 3 5 8 19 22 31
*/
