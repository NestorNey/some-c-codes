#include <stdio.h>
#include <string.h>

typedef struct nodo{
    char name[15];
    int code;
    float alt;
    struct nodo *nxt;
}TypeNodo;


typedef struct lista{
    TypeNodo *frst;
}TypeLista;


TypeLista *crearLista(){
    TypeLista * l = (TypeLista*)malloc(sizeof(struct lista));
    l->frst=NULL;
    return l;
}

void inserNode(char nmb[], TypeLista *list){
    char string[15];strcpy(string, nmb);
    TypeNodo *node=NULL;
    node=(TypeNodo*)malloc(sizeof(struct nodo));
    strcpy(node->name, string);
    node->nxt=list->frst;
    list->frst=node;
}


void main(){
    TypeLista *LaLista;
    char xd[15] = "JAJAJ xd";
    LaLista = crearLista();
    inserNode(xd, LaLista);
}