#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Nombre algoritmo: Pilas- Biblioteca
    D.E: i,Csel,DSel como entero, isnb como TypeIsnb, l como TypeLista, p, node, nxt, frs, fnl como TypeNodo
    D.S: codigo como entero, tar, nombre como cadena
    D.P: i = i + 1
    Autor: Grupo TPSI 5AM
    Fecha de inicio: 20/10/2022   Fin: 25/10/2022
*/

typedef struct Nodo{
    int codigo;
    char tar[30];
    char nombre[30];
    struct nodo *nxt;
}TypeNodo;


typedef struct lista{
    TypeNodo *frs;
    TypeNodo *fnl;
}TypeLista;

char getSelect(){
    char GSSel;
    printf("\n Ingresar: ");
    scanf("%s", &GSSel);
    GSSel = tolower(GSSel);
    return GSSel;
}

TypeLista *crearLista(){
    TypeLista * l = (TypeLista*)malloc(sizeof(struct lista));
    l->frs=NULL;
    return l;
}

int VaciaQ(TypeLista *IELista){
    int i = 0;
    TypeNodo *p = NULL;
    p = IELista -> frs;
    while(p != NULL){
        i ++;
        p = p -> nxt;
    }
    return i;
}

void insertPInicio(TypeLista *IPILista, int iter[]){
    TypeNodo *p = NULL, *node = NULL;
    node = (TypeNodo*)malloc(sizeof(struct Nodo));
    p = (TypeNodo*)malloc(sizeof(struct Nodo));
    printf("\n_____Ingresar___________________________________________________________/\n");
    printf("\n Nombre(max 30 caracteres): ");fflush(stdin);gets(node->nombre);fflush(stdin);
    printf("\n Tramite a realizar(max 30 caracteres): ");fflush(stdin);gets(node->tar);fflush(stdin);
    printf("\n________________________________________________________________________/");
    node->codigo = iter[0] + 1;iter[0]+=1;
    if(VaciaQ(IPILista) == 0){
        IPILista -> frs = node;
    }else{
        p = IPILista -> fnl;
        p -> nxt = node;
    }
    node -> nxt = NULL;
    IPILista -> fnl = node;
}

void deletePInicio(TypeLista *DPILista){
    if(VaciaQ(DPILista) != 0){
        TypeNodo *p = DPILista->frs;
        if(VaciaQ(DPILista) == 1){
            p = NULL;
            DPILista -> frs = NULL;
        }else{
            DPILista -> frs = p -> nxt;
            p = NULL;
        }
        free(p);
    }else{printf("\n ERROR >> La cola esta vacia");}
}

void doSelects(int DSSel, TypeLista *DSLista, int ite[]){
    switch(DSSel){
        case 'a':
            insertPInicio(DSLista, ite);break;
        case 'b':
            printFront(DSLista);break;
        case 'c':
            printList(DSLista);break;
        case 'd':
            FrenteQ(DSLista);break;
        case 'e':
            break;
        default:
            printf("\n ERROR >> Ingresaste una opcion invalida");
    }
}

void menu(){
    printf("\n_____________________________________________________");
    printf("\n|                                                   |");
    printf("\n|  Sistema de atencion al cliente.                  |");
    printf("\n|                                                   |");
    printf("\n|  A. Nuevo Cliente           B. Atender cliente    |");
    printf("\n|  C. Mostrar clientes        D. Mostrar datos del  |");
    printf("\n|                                siguiente cliente  |");
    printf("\n|  E. Salir                                         |");
    printf("\n|___________________________________________________|");
}

void printList(TypeLista *PLLista){
    if(VaciaQ(PLLista) != 0){
       TypeNodo *p = NULL;
        p = PLLista -> frs;
        while(p != NULL){
            printf("\n________________________________________________________/");
            printf("\n Codigo: %i",p -> codigo);
            printf("\n\n Nombre: %s",p -> nombre);
            printf("\n Tramite a realizar: %s",p -> tar);
            p = p -> nxt;
        }printf("\n________________________________________________________/");
    }else{printf("\n ERROR >> La cola esta vacia");}
}

void printFront(TypeLista *PFLista){
    char CSel;
    if(VaciaQ(PFLista) != 0){
        TypeNodo *p = NULL;
        p = PFLista -> frs;
        printf("\n_____Frente_____________________________________________/");
        printf("\n Codigo de atencion: %i",p -> codigo);
        printf("\n\n Nombre: %s",p -> nombre);
        printf("\n Tramite a realizar: %s", p -> tar);
        printf("\n________________________________________________________/");
        printf("\n CONSOLA >> Deseas eliminar el registro del usuario? [\'S\' o \'N\']");CSel = getSelect();
        if(CSel == 's'){
            deletePInicio(PFLista);
            printf("\n CONSOLA >> Registro eliminado con exito");
        }else{printf("\n CONSOLA >> Operacion cancelada");}
    }else{printf("\n ERROR >> La cola esta vacia");}
}

void FrenteQ(TypeLista *PNLista){
    if(VaciaQ(PNLista) > 1){
        TypeNodo *p = NULL;
        p = PNLista -> frs;
        p = p -> nxt;
        printf("\n_____Siguiente__________________________________________/");
        printf("\n Codigo de atencion: %i",p -> codigo);
        printf("\n\n Nombre: %s",p -> nombre);
        printf("\n Tramite a realizar: %s", p -> tar);
        printf("\n________________________________________________________/");
    }else if(VaciaQ(PNLista) == 1){
    printf("\n ERROR >> La cola solo tiene un cliente");}else{printf("\n ERROR >> La cola esta vacia");}
}

void VaciarQ(TypeLista *PLLista){
    if(VaciaQ(PLLista) != 0){
        TypeNodo *p = PLLista->frs;
        while(p != NULL){
            if(VaciaQ(PLLista) == 1){
                p = NULL;
                PLLista -> frs = NULL;
            }else{
                PLLista -> frs = p -> nxt;
                p = NULL;
            }
            free(p);
            p = PLLista->frs;
        }
    }
}

void main(){
    char Sel = 'a';
    int it[1];it[0] = 0;
    TypeLista *Lista;
    Lista = crearLista();
    while(Sel != 'e'){
        menu();
        Sel = getSelect();
        doSelects(Sel, Lista, it);
        printf("\n");
        system("PAUSE");
        system("cls");
    }
    VaciarQ(Lista);
}
