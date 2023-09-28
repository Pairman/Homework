#define elif else if



#include<iostream>
#include<string>
#include<stack>



bool match(std::string str){
    std::stack<char> stk;
    std::string::iterator c=str.begin();
    while(c!=str.end()){
        if(*c=='('||*c=='['||*c=='{'){
            stk.push(*c);
        }
        if(*c==')'){
            if(stk.empty()){
                return 0;
            }
            if(stk.top()=='('){
                stk.pop();
            }
            else{
                return 0;
            }
        }
        if(*c==']'){
            if(stk.empty()){
                return 0;
            }
            if(stk.top()=='['){
                stk.pop();
            }
            else{
                return 0;
            }
        }
        if(*c=='}'){
            if(stk.empty()){
                return 0;
            }
            if(stk.top()=='{'){
                stk.pop();
            }
            else{
                return 0;
            }
        }
        ++c;
    }

    return stk.empty();
}



int main(){
    std::string str;
    std::getline(std::cin,str);
    std::cout<<(match(str)?"right":"wrong");
}