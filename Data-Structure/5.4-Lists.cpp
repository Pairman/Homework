#include<iostream>
#include<stack>
#include<string>



typedef enum{ATOM,LISTS}ListsType;



struct Lists{
    ListsType type=ATOM;
    int data=0;
    Lists *head=NULL,*end=NULL;
};



inline Lists* newLists(){
    return (Lists*)calloc(1,sizeof(Lists));
}



bool isFreed(void* pointer_i){
    uintptr_t pointer_a=(uintptr_t)pointer_i;
    void* temp_p=malloc(1);
    uintptr_t temp_a=(uintptr_t)temp_p;
    free(temp_p);
    temp_p=NULL;
    return pointer_a==temp_a;
}



void destroyLists(Lists* lists_i){
    if(!lists_i){
        return;
    }
    if(isFreed(lists_i)){
        lists_i=NULL;
        return;
    }
    Lists *p=lists_i->head,*q=lists_i->end;
    free(lists_i);
    lists_i=NULL;
    destroyLists(p);
    destroyLists(q);
}



void setLists(Lists* lists_i,int data_i=0){
    lists_i->type=ATOM;
    lists_i->data=data_i;
    lists_i->end=lists_i->head=NULL;
}



void setLists(Lists* lists_i,Lists* head_i,Lists* end_i){
    lists_i->type=LISTS;
    lists_i->head=head_i;
    lists_i->end=end_i;
    lists_i->data=0;
}



int depthLists(Lists* lists_i){
    return !lists_i||isFreed(lists_i)?0:(lists_i->type==LISTS?1+(depthLists(lists_i->head)>depthLists(lists_i->end)?depthLists(lists_i->head):depthLists(lists_i->end)):1);
}



std::string cppStringFromLists(Lists* lists_i){
    return !lists_i||isFreed(lists_i)?" ":(lists_i->type==LISTS?"("+cppStringFromLists(lists_i->head)+","+cppStringFromLists(lists_i->end)+")":std::to_string(lists_i->data));
}



void traverseLists(Lists* lists_i){
    std::cout<<"depth { "<<depthLists(lists_i)<<" } , data { "<<cppStringFromLists(lists_i)<<" }\n";
}



Lists* copyLists(Lists* lists_i){
    if(!lists_i||isFreed(lists_i)){
        return NULL;
    }
    Lists* copied_l=newLists();
    copied_l->type=lists_i->type;
    copied_l->data=lists_i->data;
    copied_l->head=copyLists(lists_i->head);
    copied_l->end=copyLists(lists_i->end);
    return copied_l;
}



int main(){
    Lists *l0=newLists(),*l1=newLists(),*l2=newLists(),*l3=newLists(),*l4=newLists(),*l5=newLists();
    setLists(l0,l1,l2);
    setLists(l1,2);
    setLists(l2,l3,l4);
    setLists(l3,4);
    setLists(l4,NULL,l5);
    setLists(l5,8);
    traverseLists(l0);
    destroyLists(l0);
}