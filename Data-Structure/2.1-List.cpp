#include<iostream>



struct Unit{
    Unit *last=NULL,*next=NULL;
    T data=0;
};



struct List{
    Unit *head=NULL,*end=NULL;
    int size=0;
};



inline Unit* newUnit(){
    return (Unit*)calloc(1,sizeof(Unit));
}



inline List* newList(){
    List* new_l=(List*)calloc(1,sizeof(List));
    new_l->head=(Unit*)calloc(1,sizeof(Unit));
    new_l->end=(Unit*)calloc(1,sizeof(Unit));
    new_l->head->next=new_l->end;
    new_l->end->last=new_l->head;
    return new_l;
}



void destroyList(List* list_i){
    Unit* p=list_i->head;
    while(p){
        Unit* prev_u=p;
        p=p->next;
        free(prev_u);
    }
    free(list_i);
    list_i=NULL;
}



void resizeList(List* list_i,int size_i=0){
    // enlarge list to given size
    if(list_i->size<size_i){
        Unit* p=list_i->end->last;
        while(list_i->size<size_i){
            Unit* new_u=newUnit();
            p->next=new_u;
            new_u->last=p;
            new_u->next=list_i->end;
            list_i->end->last=new_u;
            // update list size
            ++list_i->size;
            p=p->next;
        }
    }
    elif(list_i->size>size_i){
        Unit* p=list_i->end->last->last;
        while(list_i->size>size_i){
            free(list_i->end->last);
            p->next=list_i->end;
            list_i->end->last=p;
            // update list size
            --list_i->size;
            p=p->last;
        }
    }
}



void traverseList(List* list_i){
    Unit* p=list_i->head->next;
    std::cout<<"size { "<<list_i->size<<" } , unit {";
    while(p!=list_i->end){
        std::cout<<" "<<p->data;
        p=p->next;
    }
    std::cout<<" }\n";
}



void insert(List* list_i,int data_i,int index_i=-1){
    // locate with overflow proof
    Unit* prev_u;
    if(index_i>=0&&index_i<list_i->size){
        prev_u=list_i->head;
        for(int i=0;i<index_i;++i){
            prev_u=prev_u->next;
        }
    }
    else{
        prev_u=list_i->end->last;
    }
    Unit* next_u=prev_u->next;
    // insert
    Unit* insert_u=newUnit();
    unit_i->data=data_i;
    prev_u->next=insert_u;
    unit_i->last=prev_u;
    unit_i->next=next_u;
    next_u->last=insert_u;
    // update size
    ++list_i->size;
}



int purge(List* list_i,int index_i=-1){
    // locate with overflow proof
    Unit* prev_u;
    if(index_i>=0&&index_i<list_i->size){
        prev_u=list_i->head;
        for(int i=0;i<index_i;++i){
            prev_u=prev_u->next;
        }
    }
    else{
        prev_u=list_i->end->last->last;
    }
    Unit *purged_u=prev_u->next,*next_u=purged_u->next;
    // purge
    prev_u->next=next_u;
    next_u->last=prev_u;
    // update size
    --list_i->size;
    // return purged unit
    int ret_d=purged_u->data;
    free(purged_u);
    return ret_d;
}



int main(){
    List* tmp_l=newList();
    resizeList(tmp_l,8);
    Unit* p=tmp_l->head->next;
    while(p!=tmp_l->end){
        p->data=p->last->data+1;
        p=p->next;
    }
    traverseList(tmp_l);
    resizeList(tmp_l,5);
    traverseList(tmp_l);
    destroyList(tmp_l);
}