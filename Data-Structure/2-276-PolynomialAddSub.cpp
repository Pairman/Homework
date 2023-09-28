#define elif else if
#define getVarName(var) #var



#include<algorithm>
#include<iostream>
#include<iterator>
#include<vector>



struct node{
    int e,k=0;
};



struct poly{
    int m=0;
    std::vector<node> t;
};




poly inputPoly(){
    poly expr;
    std::cin>>expr.m;
    node tmpnode;
    for(int tmpe=0,tmpk=0,i=0;i<expr.m;++i){
        std::cin>>tmpnode.k>>tmpnode.e;
        expr.t.push_back(tmpnode);
    }

    return expr;
}



void printPoly(poly expr){
    std::cout<<expr.m;
    for(int tmpe=0,tmpk=0,i=0;i<expr.m;++i){
        std::cout<<" "<<expr.t[i].k<<" "<<expr.t[i].e;
    }
    std::cout<<std::endl;
}



poly polyAdd(poly expr1,poly expr2){
    poly exprAdd;
    node tmpnode;
    int i=0,j=0;
    std::vector<node>::iterator p=expr1.t.begin(),q=expr2.t.begin();
    while(p!=expr1.t.end()&&q!=expr2.t.end()){
        if(p->e>q->e){
            exprAdd.t.push_back(*p);
            ++p;
        }
        elif(p->e<q->e){
            exprAdd.t.push_back(*q);
            ++q;
        }
        else{
            tmpnode.k=p->k+q->k;
            if(tmpnode.k){
                tmpnode.e=p->e;
                exprAdd.t.push_back(tmpnode);
            }
            ++p;
            ++q;
        }
    }
    while(p!=expr1.t.end()){
        exprAdd.t.push_back(*p);
        ++p;
    }
    while(q!=expr2.t.end()){
        exprAdd.t.push_back(*q);
        ++q;
    }
    exprAdd.m=exprAdd.t.size();

    return exprAdd;
}



poly polySub(poly expr1,poly expr2){
    poly exprSub;
    node tmpnode;
    int i=0,j=0;
    std::vector<node>::iterator p=expr1.t.begin(),q=expr2.t.begin();
    while(p!=expr1.t.end()&&q!=expr2.t.end()){
        if(p->e>q->e){
            exprSub.t.push_back(*p);
            ++p;
        }
        elif(p->e<q->e){
            q->k=-q->k;
            exprSub.t.push_back(*q);
            ++q;
        }
        else{
            tmpnode.k=p->k-q->k;
            if(tmpnode.k){
                tmpnode.e=p->e;
                exprSub.t.push_back(tmpnode);
            }
            ++p;
            ++q;
        }
    }
    while(p!=expr1.t.end()){
        exprSub.t.push_back(*p);
        ++p;
    }
    while(q!=expr2.t.end()){
        q->k=-q->k;
        exprSub.t.push_back(*q);
        ++q;
    }
    exprSub.m=exprSub.t.size();

    return exprSub;
}



int main(){
    poly expr1,expr2;
    expr1=inputPoly();
    expr2=inputPoly();
    printPoly(polyAdd(expr1,expr2));
    printPoly(polySub(expr1,expr2));

    return 0;
}



/*

4 1 10 2 5 3 4 4 0
4 1 8 -2 5 3 3 4 1

*/
