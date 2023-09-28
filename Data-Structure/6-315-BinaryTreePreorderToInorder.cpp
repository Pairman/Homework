#include<iostream>



#define newLeaf() (leaf*)calloc(1,sizeof(leaf))



struct leaf{
    char c=0;
    leaf *p=NULL,*l=NULL,*r=NULL;
};



leaf* createBiTreePreorder(){
    leaf *ret=newLeaf();
    std::cin>>ret->c;
    if(ret->c=='#'){
        return NULL;
    }
    ret->l=createBiTreePreorder();
    ret->r=createBiTreePreorder();
    return ret;
}



void traverseBiTreeInorder(leaf* l){
    if(l==NULL){
        std::cout<<" ";
        return;
    }
    traverseBiTreeInorder(l->l);
    std::cout<<l->c;
    traverseBiTreeInorder(l->r);
}



int main(){
    traverseBiTreeInorder(createBiTreePreorder());
}



/*

abc##de#g##f###
 c b e g d f a

*/