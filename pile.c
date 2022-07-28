#include <stdio.h>

//lista
voi init (struct pila *p)
{
    p->tail=NULL;
    p->head=NULL;
}
struct nodo
{
    int elem;
    struct nodo *next;
    struct nodo *prev;
}
struct pila
{
    struct node *tail;
    struct node *head;
}
int push (struct pila *p, int elem)
{
    struct nodo *n;
    n=malloc(sizeof(struct nodo));
    n->elem=elem;
    n->next=NULL;
    p->head->next=n;
    p->head=n;
    if(p->tail==NULL){p->tail=n;}
    if(n==NULL){return 1;}
    return 0;
}


int main(int argc, const char * argv[]) {
    
    
    
    
    
}
