#include<algorithm>
#include<vector>
#include<iterator>
#include<iostream>

int main(){
	std::vector<int> vec,idx;
	int n,m;
	std::cin>>n>>m;
	for(int i=0,tmp;i<n;++i){
		std::cin>>tmp;
		vec.push_back(tmp);
		idx.push_back(i+1);
	}

	std::vector<int>::iterator p=vec.begin(),q=idx.begin();
	while(vec.size()){
		for(int i=0;i<m-1;++i){
			if(p+1==vec.end()){
				p=vec.begin();
				q=idx.begin();
			}
			else{
				++p;
				++q;
			}
		}
		m=*p;
		std::cout<<*q<<' ';
		if(p+1==vec.end()){
			vec.erase(p);
			p=vec.begin();
			idx.erase(q);
			q=idx.begin();
		}
		else{
			p=vec.erase(p);
			q=idx.erase(q);
		}
		
	}

}

/*
7 20
3 1 7 2 4 8 4
*/
