// #include<bits/stdc++.h>
// using namespace std;



// int prints(int cnt,int *set){
// printf("abcdefghijklmnopqrstuvwxyz\n");
// for(int i=0;i<26;++i){
//     printf("%d",set[i]);
// }
// printf("\n");
//     cout<<'{';
//     int flag=0;
//     for(int i=0;i<26;++i){
//         if(set[i]){
//             flag&&cout<<',';
//             printf("%c",'a'+i);
//             (!flag)&&(flag=1);
//         }
//     }

//     cout<<'}';

//     return 0;
// }



// int main(){
//     int cntA=0,cntB=0,eleA[26]={0},eleB[26]={0};
//     char strA[1024]={0},strB[1024]={0};
//     cin>>strA>>strB;

//     for(int i=0;i<strlen(strA);++i){
//         if(strA[i]>='a'&&strA[i]<='z'){
//             eleA[strA[i]-'a']=1;
//             ++cntA;
//         }
//     }
//     for(int i=0;i<strlen(strB);++i){
//         if(strB[i]>='a'&&strB[i]<='z'){
//             eleB[strB[i]-'a']=1;
//             ++cntB;
//         }
//     }


//     int cntUni=0,eleUni[26]={0};
//     for(int i=0;i<26;++i){
//         if(eleA[i]|eleB[i]){
//             eleUni[i]=1;
//             ++cntUni;
//         }
//     }



//     int cntInt=0,eleInt[26]={0};
//     for(int i=0;i<26;++i){
//         if(eleA[i]&eleB[i]){
//             eleInt[i]=1;
//             ++cntInt;
//         }
//     }



//     int cntDif=0,eleDif[26]={0};
//     for(int i=0;i<26;++i){
//         if(eleA[i]==1&&eleB[i]==0){
//             eleDif[i]=1;
//             ++cntDif;
//         }
//     }



//     int cntSymDif=0,eleSymDif[26]={0};
//     for(int i=0;i<26;++i){
//         if((eleA[i]==1&&eleB[i]==0)||(eleA[i]==0&&eleB[i]==1)){
//             eleSymDif[i]=1;
//             ++cntSymDif;
//         }
//     }

//     prints(cntUni,eleUni);
//     printf("\n");
//     prints(cntInt,eleInt);
//     printf("\n");
//     prints(cntDif,eleDif);
//     printf("\n");
//     prints(cntSymDif,eleSymDif);

// }

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int n1=0,n2=0;
typedef struct Collection{char c;struct Collection *next;}*collection;
void clear(collection c)
{
    collection p=c->next,q;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        free(q);
    }
    c->next=NULL;
}
void sort(char x[MAXSIZE],int len)
{
    int min=0;
    for(int i=0;i<len;i++)
    {
        int start=i;
        min=start;
        while(start<len)
        {
            if (x[start]<x[min])
                min=start;
            start++;
        }
        char c=x[i];
        x[i]=x[min];
        x[min]=c;
    }
}
collection init(collection c)
{
    c=(collection)malloc(sizeof(struct Collection));
    c->next=NULL;
    return c;
}
int createmember(char *x,char *y)
{
    char *c=x;
    int num=0;
    while(*c)
    {
        if ((*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z')||(*c>='0'&&*c<='9'))
        {
            *y=*c;
            y++;
            num++;
        }
        c++;
    }
    return num;
}
collection createinit(collection c,char z[MAXSIZE],int n)
{
    collection p=c;
    for(int i=0;i<n;i++)
    {
        collection q=(collection)malloc(sizeof(struct Collection));
        q->c=z[i];
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return c;
}
collection bing(collection b,char x[MAXSIZE],char y[MAXSIZE])
{
    int flag=0;
    createinit(b,x,n1);
    collection p1=b->next;
    for(int i=0;i<n2;i++)
    {
        while(p1!=NULL)
        {
            if (y[i]==p1->c)
            {
                flag=1;
                break;
            }
            p1=p1->next;
        }
        p1=b->next;
        if (flag==0)
        {
            collection q=(collection)malloc(sizeof(struct Collection));
            q->c=y[i];
            if (p1==NULL)
            {
                b->next=q;
                q->next=NULL;
            }
            else
            {
                while (p1!=NULL)
                {
                    if (q->c<p1->c)
                    {
                        q->next=p1;
                        b->next=q;
                        break;
                    }
                    else if (q->c>=p1->c)
                    {
                        if (p1->next!=NULL&&q->c<p1->next->c)
                        {
                            q->next=p1->next;
                            p1->next=q;
                            break;
                        }
                        else if (q->c>=p1->c&&p1->next==NULL)
                        {
                            p1->next=q;
                            p1=q;
                            p1->next=NULL;
                        }
                    }
                    p1=p1->next;
                }
            }
        }
        flag=0;
    }
    return b;
}
collection jiao(collection j,char x[MAXSIZE],char y[MAXSIZE])
{
    collection j1=init(j1),j2=init(j2);
    createinit(j1,x,n1);
    createinit(j2,y,n2);
    collection p=j,p1=j1->next,p2=j2->next;
    while (p1!=NULL)
    {
        while(p2!=NULL)
        {
            if (p1->c==p2->c)
            {
                collection q=(collection)malloc(sizeof(struct Collection));
                q->c=p1->c;
                p->next=q;
                p=q;
            }
            p2=p2->next;
        }
        p1=p1->next;
        p2=j2->next;
    }
    p->next=NULL;
    clear(j1);
    clear(j2);
    return j;
}
collection cha(collection c,char x[MAXSIZE],char y[MAXSIZE])
{
    int flag=0;
    collection c1=init(c1),c2=init(c2);
    createinit(c1,x,n1);
    createinit(c2,y,n2);
    collection p=c,p1=c1->next,p2=c2->next;
    while (p1!=NULL)
    {
        while(p2!=NULL)
        {
            if (p1->c==p2->c)
            {
                flag=1;
                break;
            }
            p2=p2->next;
        }
        if (flag==0)
        {
            collection q=(collection)malloc(sizeof(struct Collection));
            q->c=p1->c;
            p->next=q;
            p=q;
        }
        p1=p1->next;
        p2=c2->next;
        flag=0;
    }
    p->next=NULL;
    clear(c1);
    clear(c2);
    return c;
}
collection huan(collection h,collection j,char x[MAXSIZE],char y[MAXSIZE])
{
    collection h1=init(h1),h2=j->next,p,q,r;
    h1=bing(h1,x,y);
    p=h1;
    q=h1->next;
    while(h2!=NULL)
    {
        while(q!=NULL)
        {
            if (h2->c==q->c)
            {
                r=q;
                q=q->next;
                p->next=q;
                free(r);
                break;
            }
            else
            {
                q=q->next;
                p=p->next;
            }
        }
        h2=h2->next;
    }
    h=h1;
    return h;
}
void output(collection C)
{
    collection head=C->next;
    printf("{");
    while(head!=NULL)
    {
        if (head->next==NULL)
            printf("%c",head->c);
        else
            printf("%c,",head->c);
        head=head->next;
    }
    printf("}");
}
int main()
{
    char a[MAXSIZE],b[MAXSIZE],a1[MAXSIZE],b1[MAXSIZE];
    collection B=init(B),J=init(J),C=init(C),H=init(H);
    scanf("%s",a);
    scanf("%s",b);
    n1=createmember(a,a1);
    n2=createmember(b,b1);
    sort(a1,n1);
    sort(b1,n2);
    B=bing(B,a1,b1);
    J=jiao(J,a1,b1);
    C=cha(C,a1,b1);
    H=huan(H,J,a1,b1);
    output(B);
    printf("\n");
    output(J);
    printf("\n");
    output(C);
    printf("\n");
    output(H);
    clear(B);
    clear(J);
    clear(C);
    clear(H);
    return 0;
}