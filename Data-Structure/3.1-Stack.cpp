#include<iostream>



struct Unit{
    Unit *last=NULL,*next=NULL;
    int data=0;
};



struct Stack{
    Unit *head=NULL,*top=NULL;
    int size=0;
};



inline Unit* newUnit(){
    return (Unit*)calloc(1,sizeof(Unit));
}



inline Stack* newStack(){
    Stack* new_s=(Stack*)calloc(1,sizeof(Stack));
    new_s->top=new_s->head=(Unit*)calloc(1,sizeof(Unit));
    return new_s;
}



void destroyStack(Stack* stack_i){
    Unit* p=stack_i->head;
    while(p){
        Unit* prev_u=p;
        p=p->next;
        free(prev_u);
    }
    free(stack_i);
    stack_i=NULL;
}



void traverseStack(Stack* stack_i){
    Unit* p=stack_i->head->next;
    std::cout<<"size { "<<stack_i->size<<" } , top { "<<stack_i->top->data<<" } , unit {";
    while(p){
        std::cout<<" "<<p->data;
        p=p->next;
    }
    std::cout<<" }\n";
}



void push(Stack* stack_i,int data_i){
    // locate
    Unit* prev_u=stack_i->top;
    // push
    Stack* push_u=newUnit();
    unit_i->data=data_i;
    prev_u->next=push_u;
    unit_i->last=prev_u;
    unit_i->next=NULL;
    // update top and size
    stack_i->top=push_u;
    ++stack_i->size;
}



int pop(Stack* stack_i){
    // locate with overflow proof
    if(!stack_i->size){
        return (int)NULL;
    }
    // pop
    Unit *purged_u=stack_i->top,*prev_u=stack_i->top->last;
    prev_u->next=NULL;
    // update top and size
    stack_i->top=prev_u;
    --stack_i->size;
    // return purged unit
    int ret_d=purged_u->data;
    free(purged_u);
    return ret_d;
}



int main(){
    Stack* tmp_s=newStack();
    int tmp_n;
    while(std::cin>>tmp_n){
        if(tmp_n==0){
            std::cout<<"    pop { "<<pop(tmp_s)<<" }\n";
        }
        else{
            push(tmp_s,tmp_n);
            std::cout<<"    push { "<<tmp_n<<" }\n";
        }
        std::cout<<"    ";
        traverseStack(tmp_s);
    }
    destroyStack(tmp_s);
}