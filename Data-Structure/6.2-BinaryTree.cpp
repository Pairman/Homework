#include<algorithm>
#include<iostream>
#include<vector>



template<typename T> struct Unit{
    int level=0;
    Unit<T> *left=nullptr,*right=nullptr,*parent=nullptr;
    T data=0;
};



template<typename T> struct BinaryTree{
    Unit<T> *root=nullptr;
};



template<typename T> void destroyUnit(Unit<T>* unit_i){
    if(unit_i==nullptr){
        return;
    }
    destroyUnit(unit_i->left);
    destroyUnit(unit_i->right);
    free(unit_i);
    unit_i=nullptr;
}



template<typename T> void destroyBinaryTree(BinaryTree<T>* tree_i){
    if(tree_i){
        destroyUnit(tree_i->root);
        free(tree_i);
        tree_i=nullptr;
    }
}



template<typename T> inline Unit<T>* newUnit(T data_i=NULL){
    Unit<T>* new_u=(Unit<T>*)calloc(1,sizeof(Unit<T>));
    new_u->parent=new_u->left=new_u->right=nullptr;
    new_u->data=data_i;
    return new_u;
}



template<typename T> inline BinaryTree<T>* newBinaryTree(){
    BinaryTree<T>* new_t=(BinaryTree<T>*)calloc(1,sizeof(BinaryTree<T>));
    new_t->root=nullptr;
    return new_t;
}



template<typename T> void append(Unit<T>* unit_i,T data_i,bool branch_i=false){
    if(unit_i->left==nullptr&&!branch_i){
        unit_i->left=newUnit(data_i);
        unit_i->left->level=unit_i->level+1;
        unit_i->left->parent=unit_i;
        return;
    }
    if(unit_i->right==nullptr){
        unit_i->right=newUnit(data_i);
        unit_i->right->level=unit_i->level+1;
        unit_i->right->parent=unit_i;
    }
}



template<typename T> void preorderTraverseUnit(Unit<T>* unit_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    if(unit_i==nullptr){
        std::cout<<placeholder_i<<(unnest_i?seperator_i:(char)0);
        return;
    }
    if(!unnest_i){
        std::cout<<'('<<unit_i->data<<',';
        preorderTraverseUnit(unit_i->left,unnest_i,placeholder_i,seperator_i);
        std::cout<<',';
        preorderTraverseUnit(unit_i->right,unnest_i,placeholder_i,seperator_i);
        std::cout<<')';
        return;
    }
    std::cout<<unit_i->data<<seperator_i;
    preorderTraverseUnit(unit_i->left,unnest_i,placeholder_i,seperator_i);
    preorderTraverseUnit(unit_i->right,unnest_i,placeholder_i,seperator_i);
}



template<typename T> void preorderTraverseBinaryTree(BinaryTree<T>* tree_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    preorderTraverseUnit(tree_i->root,unnest_i,placeholder_i,seperator_i);
    std::cout<<'\n';
}



template<typename T> void inorderTraverseUnit(Unit<T>* unit_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    if(unit_i==nullptr){
        std::cout<<placeholder_i<<(unnest_i?seperator_i:(char)0);
        return;
    }
    if(!unnest_i){
        std::cout<<'(';
        inorderTraverseUnit(unit_i->left,unnest_i,placeholder_i,seperator_i);
        std::cout<<','<<unit_i->data<<',';
        inorderTraverseUnit(unit_i->right,unnest_i,placeholder_i,seperator_i);
        std::cout<<')';
        return;
    }
    inorderTraverseUnit(unit_i->left,unnest_i,placeholder_i,seperator_i);
    std::cout<<unit_i->data<<seperator_i;
    inorderTraverseUnit(unit_i->right,unnest_i,placeholder_i,seperator_i);
}



template<typename T> void inorderTraverseBinaryTree(BinaryTree<T>* tree_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    inorderTraverseUnit(tree_i->root,unnest_i,placeholder_i,seperator_i);
    std::cout<<'\n';
}



template<typename T> void postorderTraverseUnit(Unit<T>* unit_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    if(unit_i==nullptr){
        std::cout<<placeholder_i<<(unnest_i?seperator_i:(char)0);
        return;
    }
    if(!unnest_i){
        std::cout<<'(';
        postorderTraverseUnit(unit_i->left,unnest_i,placeholder_i,seperator_i);
        std::cout<<',';
        postorderTraverseUnit(unit_i->right,unnest_i,placeholder_i,seperator_i);
        std::cout<<','<<unit_i->data<<')';
        return;
    }
    postorderTraverseUnit(unit_i->left,unnest_i,placeholder_i,seperator_i);
    postorderTraverseUnit(unit_i->right,unnest_i,placeholder_i,seperator_i);
    std::cout<<unit_i->data<<seperator_i;
}



template<typename T> void postorderTraverseBinaryTree(BinaryTree<T>* tree_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    postorderTraverseUnit(tree_i->root,unnest_i,placeholder_i,seperator_i);
    std::cout<<'\n';
}



template<typename T> inline bool compareLevelUnits(Unit<T>* p_u,Unit<T>* q_u){
    return p_u->level<q_u->level;
}



template<typename T> void collectUnit(Unit<T>* unit_i,std::vector<Unit<T>*> &units_v){
    if(unit_i==nullptr){
        return;
    }
    units_v.push_back(unit_i);
    collectUnit(unit_i->left,units_v);
    collectUnit(unit_i->right,units_v);
}



template<typename T> void levelorderTraverseUnit(Unit<T>* unit_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    if(unit_i==nullptr){
        return;
    }
    std::vector<Unit<T>*> units_v;
    collectUnit(unit_i,units_v);
    std::sort(units_v.begin(),units_v.end(),compareLevelUnits<T>);
    int units_s=units_v.size();
    if(!units_s){
        return;
    }
    if(!unnest_i){
        for(int i=0;i<units_s;++i){
            std::cout<<'('<<units_v[i]->level<<','<<units_v[i]->data<<')';
        }
        return;
    }
    for(int i=0;i<units_s;++i){
        std::cout<<units_v[i]->data<<seperator_i;
    }
}



template<typename T> void levelorderTraverseBinaryTree(BinaryTree<T>* tree_i,bool unnest_i=false,char placeholder_i=' ',char seperator_i=0){
    levelorderTraverseUnit(tree_i->root,unnest_i,placeholder_i,seperator_i);
    std::cout<<'\n';
}



template<typename T> inline int depthUnit(Unit<T>* unit_i){
    return unit_i==nullptr?0:(unit_i->left==nullptr&&unit_i->right==nullptr?1:(1+std::max(depthUnit(unit_i->left),depthUnit(unit_i->right))));
}



template<typename T> inline int depthBinaryTree(BinaryTree<T>* tree_i){
    return tree_i==nullptr?0:depthUnit(tree_i->root);
}



int main(){
    BinaryTree<char>* tree=newBinaryTree<char>();
    tree->root=newUnit<char>('A');
    append(tree->root,'B');
    append(tree->root->left,'C');
    append(tree->root->left,'D');
    append(tree->root->left->right,'E');
    append(tree->root->left->right,'F');
    append(tree->root->left->right->left,'G',true);
    preorderTraverseBinaryTree(tree,1,'#');
    inorderTraverseBinaryTree(tree,1,'#');
    postorderTraverseBinaryTree(tree,1,'#');
    levelorderTraverseBinaryTree(tree,1,'#');
    destroyBinaryTree(tree);
}