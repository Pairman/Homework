#include<iostream>
#include<cstring>
#include<string>



struct Unit{
    Unit *last=NULL,*next=NULL;
    char data=0;
};



struct String{
    Unit *head=NULL,*end=NULL;
    int length=0;
};



inline Unit* newUnit(){
    return (Unit*)calloc(1,sizeof(Unit));
}



inline String* newString(){
    String* new_s=(String*)calloc(1,sizeof(String));
    new_s->head=(Unit*)calloc(1,sizeof(Unit));
    new_s->end=(Unit*)calloc(1,sizeof(Unit));
    new_s->head->next=new_s->end;
    new_s->end->last=new_s->head;
    return new_s;
}



void destroyString(String* string_i){
    Unit* p=string_i->head;
    while(p){
        Unit* prev_u=p;
        p=p->next;
        free(prev_u);
    }
    free(string_i);
    string_i=NULL;
}



void traverseString(String* string_i,bool quiet_i=1){
    Unit* p=string_i->head->next;
    if(!quiet_i){
        std::cout<<"length { "<<string_i->length<<" } , unit { ";
    }
    while(p!=string_i->end){
        std::cout<<p->data;
        p=p->next;
    }
    if(!quiet_i){
        std::cout<<" }\n";
    }
}



String* cToString(char *cstring_i){
    String* string_o=newString();
    char* p=cstring_i;
    while(*p!=0){
        // copy unit
        Unit* copy_u=newUnit();
        copy_u->data=*p++;
        // insert unit
        Unit* prev_u=string_o->end->last;
        prev_u->next=copy_u;
        copy_u->last=prev_u;
        copy_u->next=string_o->end;
        string_o->end->last=copy_u;
    }
    // update length
    string_o->length=strlen(cstring_i);
    return string_o;
}



String* cppToString(std::string cppstring_i){
    String* string_o=newString();
    for(std::string::const_reference p:cppstring_i){
        // copy unit
        Unit* copy_u=newUnit();
        copy_u->data=p;
        // insert unit
        Unit* prev_u=string_o->end->last;
        prev_u->next=copy_u;
        copy_u->last=prev_u;
        copy_u->next=string_o->end;
        string_o->end->last=copy_u;
    }
    // update length
    string_o->length=cppstring_i.length();
    return string_o;
}



String* charToString(char char_i){
    Unit* copy_u=newUnit();
    String* string_o=newString();
    copy_u->data=char_i;
    string_o->head->next=copy_u;
    copy_u->last=string_o->head;
    copy_u->next=string_o->end;
    string_o->end->last=copy_u;
    ++string_o->length;
    return string_o;
}



char* cFromString(String* string_i){
    char* cstring_o=(char*)calloc(string_i->length+1,sizeof(char));
    Unit* p=string_i->head->next;
    for(int i=0;i<string_i->length;++i){
        cstring_o[i]=p->data;
        p=p->next;
    }
    return cstring_o;
}



std::string cppFromString(String* string_i){
    std::string cppstring_o;
    for(Unit* p=string_i->head->next;p!=string_i->end;p=p->next){
        cppstring_o+=p->data;
    }
    return cppstring_o;
}



char charFromString(String* string_i,int index_i=0){
    Unit* p=string_i->head->next;
    int i=0;
    while(i<index_i&&p){
        p=p->next;
        ++i;
    }
    return p->data;
}



String* subString(String* string_i,int start_i=0,int end_i=0){
    String* string_o=newString();
    // overflow proof
    if(start_i>=end_i){
        return string_o;
    }
    if(start_i<0){
        start_i=0;
    }
    if(end_i>string_i->length){
        end_i=string_i->length;
    }
    // locate and copy
    Unit* p=string_i->head->next;
    for(int i=0;i<start_i;++i){
        p=p->next;
    }
    for(int i=start_i;i<end_i;++i){
        // copy unit
        Unit* copy_u=newUnit();
        copy_u->data=p->data;
        p=p->next;
        // insert unit
        Unit* prev_u=string_o->end->last;
        prev_u->next=copy_u;
        copy_u->last=prev_u;
        copy_u->next=string_o->end;
        string_o->end->last=copy_u;
    }
    // update length
    string_o->length=end_i-start_i;
    return string_o;
}



String* joinString(String* string1_i,String* string2_i){
    String* string_o=newString();
    Unit* p=string1_i->head->next;
    while(p!=string1_i->end){
        // copy unit
        Unit* copy_u=newUnit();
        copy_u->data=p->data;
        p=p->next;
        // insert unit
        Unit* prev_u=string_o->end->last;
        prev_u->next=copy_u;
        copy_u->last=prev_u;
        copy_u->next=string_o->end;
        string_o->end->last=copy_u;    
    }
    p=string2_i->head->next;
    while(p!=string2_i->end){
        // copy unit
        Unit* copy_u=newUnit();
        copy_u->data=p->data;
        p=p->next;
        // insert unit
        Unit* prev_u=string_o->end->last;
        prev_u->next=copy_u;
        copy_u->last=prev_u;
        copy_u->next=string_o->end;
        string_o->end->last=copy_u;
    }
    // update length
    string_o->length=string1_i->length+string2_i->length;
    return string_o;
}



int compareString(String* string1_i,String* string2_i){
    // compare lengths
    if(string1_i->length>string2_i->length){
        return 1;
    }
    if(string1_i->length<string2_i->length){
        return -1;
    }
    // compare chars
    Unit *p=string1_i->head->next,*q=string2_i->head->next;
    while(p!=string1_i->end&&q!=string2_i->end){
        if(p->data>q->data){
            return 1;
        }
        if(p->data<q->data){
            return -1;
        }
        p=p->next;
        q=q->next;
    }
    return 0;
}



int* lpsString(String* string_i,bool next_i=0){
    // create indexes i,j for corresponding pointer p,q and array lps_v
    int j=0,i=1,*lps_v=(int*)calloc(string_i->length,sizeof(int));
    Unit *q=string_i->head->next,*p=string_i->head->next->next;
    // compute array for kmp algorithm
    while(i<string_i->length){
        // if char at i,j are equal: lps_v[i]=j+1, then increment both i,j by 1
        if(p->data==q->data){
            lps_v[i++]=j+++1;
            p=p->next;
            q=q->next;
        }
        else{
            // if j non 0: j go back to lps_v[j-1]
            if(j){
                for(int k=lps_v[j-1];k<j;++k){
                    q=q->last;
                }
                j=lps_v[j-1];
            }
            // else aka j cannot go back: lps_V[i]=0, then increment i by 1
            else{
                lps_v[i++]=0;
                p=p->next;
            }
        }
    }
    // if next_i is true, transform lps array to textbook-styled next array
    if(next_i){
        for(int i=string_i->length-1;i>0;--i){
            lps_v[i]=lps_v[i-1]+1;
        }
        lps_v[0]=0;
    }
    return lps_v;
}



int findString(String* string_i,String* pattern_i){
    // pattern matching using kmp algorithm
    // create indexes i,j for corresponding pointer p,q and array lps_v
    int i=0,j=0,*lps_v=lpsString(pattern_i);
    Unit *p=string_i->head->next,*q=pattern_i->head->next;
    // search
    while(i<string_i->length&&j<pattern_i->length){
        // if char at i,j are equal: increment both i,j by 1
        if(p->data==q->data){
            ++i;
            ++j;
            p=p->next;
            q=q->next;
        }
        else{
            // if j non 0: j go back to lps_v[j-1]
            if(j){
                for(int k=lps_v[j-1];k<j;++k){
                    q=q->last;
                }
                j=lps_v[j-1];
            }
            // else aka j cannot go back: increment i by 1
            else{
                ++i;
                p=p->next;
            }
        }
    }
    free(lps_v);
    // return index of the first occurrence
    return ((j==pattern_i->length)?(i-j):(-1));
}



int main(){
    String *s=cppToString("aaabaaaab"),*p=cppToString("aaaab");
    std::cout<<findString(s,p)<<'\n';
    int* lps_v=lpsString(p);
    traverseString(p,1);
    std::cout<<'\n';
    for(int i=0;i<p->length;++i){
        std::cout<<lps_v[i];
    }
    std::cout<<'\n';
    destroyString(s);
    destroyString(p);
}