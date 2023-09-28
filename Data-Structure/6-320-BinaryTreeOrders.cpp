#include<iostream>
#include<vector>



#define newLeaf() (leaf*)calloc(1,sizeof(leaf))



struct leaf{
    std::vector<int> v;
    leaf *p=NULL,*l=NULL,*r=NULL;
};



leaf* createBiTree(std::vector<int> lvlorder,std::vector<int> inorder){
    if(!inorder.size()||!lvlorder.size()){
        return NULL;
    }

    std::vector<int>::iterator i=lvlorder.begin(),d;
    while(i<lvlorder.end()){
        d=inorder.begin();
        while(d<inorder.end()){
            if(*d==*i){
                lvlorder.erase(i);
                i=lvlorder.end();
                break;
            }
            ++d;
        }
        ++i;
    }

    leaf* ret=newLeaf();
    std::vector<int> value(d,d+1),linorder(inorder.begin(),d),rinorder(d+1,inorder.end());
    ret->v=value;
    ret->l=createBiTree(lvlorder,linorder);
    ret->r=createBiTree(lvlorder,rinorder);

    return ret;
}



void traverseBiTreeLeafInorder(leaf* bitree){
    if(bitree==NULL){
        return;
    }

    traverseBiTreeLeafInorder(bitree->l);
    if(bitree->l==NULL&&bitree->r==NULL){
        std::cout<<bitree->v[0]<<" ";
    }
    traverseBiTreeLeafInorder(bitree->r);
}



void traverseBiTreePreorder(leaf* bitree){
    if(bitree==NULL){
        return;
    }

    std::cout<<bitree->v[0]<<" ";
    traverseBiTreePreorder(bitree->l);
    traverseBiTreePreorder(bitree->r);
}



void traverseBiTreePostorder(leaf* bitree){
    if(bitree==NULL){
        return;
    }

    traverseBiTreePostorder(bitree->l);
    traverseBiTreePostorder(bitree->r);
    std::cout<<bitree->v[0]<<" ";
}



int main(){
    int n;
    std::cin>>n;
    std::vector<int> vecLvlorder(n,0),vecInorder(n,0);
    for(std::vector<int>::reference u:vecLvlorder){
        std::cin>>u;
    }
    for(std::vector<int>::reference u:vecInorder){
        std::cin>>u;
    }

    leaf* biTree=createBiTree(vecLvlorder,vecInorder);

    traverseBiTreeLeafInorder(biTree);
    std::cout<<std::endl;
    traverseBiTreePreorder(biTree);
    std::cout<<std::endl;
    traverseBiTreePostorder(biTree);
    std::cout<<std::endl;
}



/*

7
3 5 4 2 6 7 1
2 5 3 6 4 7 1

*/