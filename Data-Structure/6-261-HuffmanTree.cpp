#include<algorithm>
#include<iostream>
#include<vector>



#define newLeaf() (leaf*)calloc(1,sizeof(leaf))



struct leaf{
    int d=0,v=0;
    leaf *p=NULL,*l=NULL,*r=NULL;
} nullleaf;



bool cmpLeaf(leaf* x,leaf* y){
    return x->v<y->v;
}



void deepBiTree(leaf* bitree){
    if(bitree==NULL){
        return;
    }

    if(bitree->l!=NULL){
        bitree->l->d=bitree->d+1;
    }
    if(bitree->r!=NULL){
        bitree->r->d=bitree->d+1;
    }
    deepBiTree(bitree->l);
    deepBiTree(bitree->r);
}



int weighHmTree(leaf* hmtree){
    if(hmtree->l==NULL&&hmtree->r==NULL){
        return hmtree->d*hmtree->v;
    }
    return weighHmTree(hmtree->l)+weighHmTree(hmtree->r);
}



leaf* createHmTree(std::vector<leaf*> vec){
    while(vec.size()>1){
        std::sort(vec.begin(),vec.end(),cmpLeaf);
        for(auto i:vec){
        }
        leaf *n=newLeaf(),*l=vec[0],*r=vec[1];
        n->v=l->v+r->v;
        n->l=l;
        n->r=r;
        vec.erase(vec.begin(),vec.begin()+2);
        vec.push_back(n);
    }

    return vec[0];
}



int main(){
    int n=0;
    std::cin>>n;
    std::vector<leaf*> vec(n,NULL);
    for(std::vector<leaf*>::reference r:vec){
        r=newLeaf();
        r->d=1;
        std::cin>>r->v;
    }

    leaf* hmTree=createHmTree(vec);
    deepBiTree(hmTree);
    std::cout<<weighHmTree(hmTree)<<std::endl;
}