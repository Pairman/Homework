#include<iostream>



struct Unit{
    Unit *last=NULL,*next=NULL;
    int data=0;
};



struct Queue{
    Unit *head=NULL,*front=NULL,*back=NULL,*end=NULL;
    int size=0;
};



inline Unit* newUnit(){
    return (Unit*)calloc(1,sizeof(Unit));
}



inline Queue* newQueue(){
    Queue* new_q=(Queue*)calloc(1,sizeof(Queue));
    new_q->back=new_q->front=new_q->head=(Unit*)calloc(1,sizeof(Unit));
    new_q->end=(Unit*)calloc(1,sizeof(Unit));
    new_q->head->next=new_q->end;
    new_q->end->last=new_q->head;
    return new_q;
}



void destroyQueue(Queue* queue_i){
    Unit* p=queue_i->head;
    while(p){
        Unit* prev_u=p;
        p=p->next;
        free(prev_u);
    }
    free(queue_i);
    queue_i=NULL;
}



void traverseQueue(Queue* queue_i){
    Unit* p=queue_i->front;
    std::cout<<"size { "<<queue_i->size<<" } , front { "<<queue_i->front->data<<" } , back {"<<queue_i->back->data<<"} , unit {";
    while(p!=queue_i->end){
        std::cout<<" "<<p->data;
        p=p->next;
    }
    std::cout<<" }\n";
}



void push(Queue* queue_i,int data_i){
    // locate
    Unit* prev_u=queue_i->end->last;
    // push
    Unit* push_u=newUnit();
    unit_i->data=data_i;
    prev_u->next=push_u;
    unit_i->last=prev_u;
    unit_i->next=queue_i->end;
    queue_i->end->last=push_u;
    // update front, back and size
    if(!queue_i->size){
        queue_i->front=push_u;
    }
    queue_i->back=push_u;
    ++queue_i->size;
}



int pop(Queue* queue_i){
    // locate with overflow proof
    if(!queue_i->size){
        return (int)NULL;
    }
    // pop
    Unit *purged_u=queue_i->head->next,*prev_u=queue_i->head,*next_u=queue_i->head->next->next;
    prev_u->next=next_u;
    next_u->last=prev_u;
    // update front, back and size
    queue_i->front=next_u;
    --queue_i->size;
    if(!queue_i->size){
        queue_i->back=queue_i->front=queue_i->head;
    }
    // return purged unit
    int ret_d=purged_u->data;
    free(purged_u);
    return ret_d;
}



int main(){
    Queue* tmp_q=newQueue();
    int tmp_n;
    while(std::cin>>tmp_n){
        if(tmp_n==0){
            std::cout<<"    pop { "<<pop(tmp_q)<<" }\n";
        }
        else{
            push(tmp_q,tmp_n);
            std::cout<<"    push { "<<tmp_n<<" }\n";
        }
        std::cout<<"    ";
        traverseQueue(tmp_q);
    }
}