#define elif else if



#include<iostream>
#include<stack>
#include<string>
#include<vector>



int main(){
    int m=0,n=0,k=0;
    std::cin>>m>>n>>k;
    std::cin.clear();

    std::vector<int> stk0;
    int tmpint=0;
    for(int j=0;j<n;++j){
        std::cin>>tmpint;
        stk0.push_back(tmpint);
    }

    std::vector<std::vector<int>> stks;
    for(int i=0;i<k;++i){
        std::vector<int> stk;
        int tmpint=0;
        for(int j=0;j<n;++j){
            std::cin>>tmpint;
            stk.push_back(tmpint);
        }
        std::cin.clear();
        stks.push_back(stk);
    }

    for(auto stk:stks){
        std::stack<int> tmpstk;
        std::vector<int>::iterator p=stk0.begin(),q=stk.begin();
        while(p!=stk0.end()&&q!=stk.end()){
            tmpstk.push(*p);
            while(tmpstk.size()&&tmpstk.size()<m+1&&tmpstk.top()==*q){
                tmpstk.pop();
                ++q;
            }
            ++p;
        }
        std::cout<<(tmpstk.empty()?"YES":"NO")<<std::endl;
    }
}



/*

5 7 5
1 2 3 4 5 6 7
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

*/
