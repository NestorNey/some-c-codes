#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    Nombre algoritmo: Pilas- Biblioteca
    D.E: i,Csel,DSel como entero, isnb como TypeIsnb, l como TypeLista, p, node, nxt, frs, fnl como TypeNodo
    D.S: pEan,cp,ce,ndl,ddc,codigo como entero, nombre, autor, editorial, pais, adf como cadena
    D.P: i = i + 1
    Autor: Grupo TPSI 5AM
    Fecha de inicio: 20/10/2022   Fin: 25/10/2022
*/

typedef struct ISNB{
    int pEan;
    int cp;
    int ce;
    int ndl;
    int ddc;
}TypeIsnb;


typedef struct Nodo{
    int codigo;
    char nombre[30];
    char autor[30];
    char editorial[30];
    char pais[30];
    char adf[30];
    TypeIsnb isnb;
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

int PilaVacia(TypeLista *PVLista){
    int i = 0;
    TypeNodo *p = NULL;
    p = PVLista -> frs;
    while(p != NULL){
        i ++;
        p = p -> nxt;
    }
    return i;
}

void insertPInicio(TypeLista *IPILista, int iter[]){
    TypeNodo *node = NULL;
    node=(TypeNodo*)malloc(sizeof(struct Nodo));
    printf("\n_____Libro a ingresar___________________________________________________/\n");
    printf("\n NOTA: Los strings son de maximo 30 caracteres\n\n");
    printf("\n Nombre: ");fflush(stdin);gets(node->nombre);fflush(stdin);
    printf("\n Autor: ");fflush(stdin);gets(node->autor);fflush(stdin);
    printf("\n Editorial: ");fflush(stdin);gets(node->editorial);fflush(stdin);
    printf("\n Pais: ");fflush(stdin);gets(node->pais);fflush(stdin);
    printf("\n Area de formacion: ");fflush(stdin);gets(node->adf);fflush(stdin);
    printf("\n\n ISNB\n");
    printf("\n Prefijo EAN: ");scanf("%i", &node->isnb.pEan);
    printf("\n Codigo de pais: ");scanf("%i", &node->isnb.cp);
    printf("\n Codigo editorial: ");scanf("%i", &node->isnb.ce);
    printf("\n Numero de libro: ");scanf("%i", &node->isnb.ndl);
    printf("\n Digito de control: ");scanf("%i", &node->isnb.ddc);
    printf("\n________________________________________________________________________/");
    node->codigo = iter[0] + 1;iter[0] ++;
    node -> nxt = IPILista -> frs;
    IPILista -> frs = node;
}

void cima(TypeLista *CLista){
    if(PilaVacia(CLista) != 0){
        TypeNodo *p = NULL;
        p = CLista -> frs;
        printf("\n_____Cima_______________________________________________/");
        printf("\n Codigo: %i",p -> codigo);
        printf("\n\n Nombre: %s",p -> nombre);
        printf("\n Autor: %s",p -> autor);
        printf("\n Editorial: %s", p -> editorial);
        printf("\n Pais: %s",p -> pais);
        printf("\n Area de formacion: %s",p -> adf);
        printf("\n\n ISNB: %i-%i-%i-%i-%i", p -> isnb.pEan, p -> isnb.cp, p -> isnb.ce, p -> isnb.ndl, p -> isnb.ddc);
        printf("\n________________________________________________________/");
    }else{printf("\n ERROR >> La pila esta vacia");}
}

void deletePInicio(TypeLista *DPILista){
    char CSel;
    if(PilaVacia(DPILista) != 0){
        cima(DPILista);
        printf("\n CONSOLA >> Deseas eliminar el registro del libro? [\'S\' o \'N\']");CSel = getSelect();
        if(CSel == 's'){
            TypeNodo *p = DPILista -> frs;
            DPILista -> frs = p -> nxt;
            p -> nxt = NULL;
            free(p);
            printf("\n CONSOLA >> Registro eliminado con exito");
        }else{printf("\n CONSOLA >> Operacion cancelada");}
    }else{printf("\n ERROR >> La pila esta vacia");}
}

void printList(TypeLista *PLLista){
    if(PilaVacia(PLLista) != 0){
        TypeNodo *p = NULL;
        p = PLLista -> frs;
        while(p != NULL){
            printf("\n________________________________________________________/");
            printf("\n Codigo: %i",p -> codigo);
            printf("\n\n Nombre: %s",p -> nombre);
            printf("\n Autor: %s",p -> autor);
            printf("\n Editorial: %s", p -> editorial);
            printf("\n Pais: %s",p -> pais);
            printf("\n Area de formacion: %s",p -> adf);
            printf("\n\n ISNB: %i-%i-%i-%i-%i", p -> isnb.pEan, p -> isnb.cp, p -> isnb.ce, p -> isnb.ndl, p -> isnb.ddc);
            p = p -> nxt;
        }printf("\n________________________________________________________/");
    }else{printf("\n ERROR >> La pila esta vacia");}
}

void doSelects(int DSSel, TypeLista *DSLista, int ite[]){
    switch(DSSel){
        case 'a':
            insertPInicio(DSLista, ite);break;
        case 'b':
            printList(DSLista);break;
        case 'c':
            deletePInicio(DSLista);break;
        case 'd':
            searchPCodigo(DSLista);break;
        case 'e':
            break;
        default:
            printf("\n ERROR >> Ingresaste una opcion invalida");
    }
}

void menu(){
    printf("\n_______________________________________________________________");
    printf("\n|                                                             |");
    printf("\n|  Base de datos biblioteca.                                  |");
    printf("\n|                                                             |");
    printf("\n|  A. Ingresar nuevos libros   B. Ver todos los libros        |");
    printf("\n|  C. Bajas de libros          D. Buscar un libro por codigo  |");
    printf("\n|  E. Salir                                                   |");
    printf("\n|_____________________________________________________________|");
}

void searchPCodigo(TypeLista *SPCLista){
    if(PilaVacia(SPCLista) != 0){
        TypeNodo *p = NULL;
        int refe, bol = 1;
        printf("\n CONSOLA >> Ingresa el codigo de referencia: ");scanf("%i", &refe);
        p = SPCLista -> frs;
        while(p != NULL){
            if(p -> codigo == refe){
                bol = 0;
                printf("\n_____Busqueda___________________________________________/");
                printf("\n Codigo: %i",p -> codigo);
                printf("\n\n Nombre: %s",p -> nombre);
                printf("\n Autor: %s",p -> autor);
                printf("\n Editorial: %s", p -> editorial);
                printf("\n Pais: %s",p -> pais);
                printf("\n Area de formacion: %s",p -> adf);
                printf("\n\n ISNB: %i-%i-%i-%i-%i", p -> isnb.pEan, p -> isnb.cp, p -> isnb.ce, p -> isnb.ndl, p -> isnb.ddc);
                printf("\n________________________________________________________/");
            }
            p = p -> nxt;
        }
        if(bol == 1){printf("\n ERROR >> El codigo de referencia no se econtro.");}
    }else{printf("\n ERROR >> La pila esta vacia");}
}

void LimpiarPila(TypeLista *PLLista){
    if(PilaVacia(PLLista) != 0){
        TypeNodo *p = PLLista->frs;
        while(p != NULL){
            PLLista -> frs = p -> nxt;
            p = NULL;
            free(p);
            p = PLLista->frs;
        }
    }
}

void main(){
    char Sel = 'A';
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
    LimpiarPila(Lista);
}
