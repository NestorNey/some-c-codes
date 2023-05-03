#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Autor: Nestor Emmanuel Ascencio Sacnhez

//    Model's -------------------------------------------------------->

typedef struct ModeloFechas{
    int dn;
    int an;
    int mn;
}ModeloFecha;

typedef struct ModeloNombres{
    char nombre[30];
    char aPaterno[30];
    char aMaterno[30];
}ModeloNombre;

//    Node's -------------------------------------------------------->

typedef struct NodoUsuarios{
    int nr; 
    int edad;
    char sexo[15];
    char hr[15];
    char caq[50];
    ModeloFecha fen;
    ModeloNombre nombre;
    struct ModeloNodo *nxt, *ant;
}NodoUsuario;

//    List's  ----------------------------------------------------->

typedef struct ListaRegistros{
    NodoUsuario *frs;
    NodoUsuario *fnl;
    int ite;
}ListaRegistro;

//    Program -------------------------------------------------------------------->

char getSelect(){
    char GSSel;
    printf("\n Ingresar: ");
    scanf("%s", &GSSel);
    GSSel = tolower(GSSel);
    return GSSel;
}

void VaciarQ(ListaRegistro *PLLista){
    if(isEmpty(PLLista) != 0){
        NodoUsuario *p = PLLista->frs;
        while(p != NULL){
            if(isEmpty(PLLista) == 1){
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

int isEmpty(ListaRegistro *IErgs){
    NodoUsuario *p = NULL;
    int it = 0;
    p = IErgs -> frs;
    while(p != NULL){
        it ++;
        p = p -> nxt;
    }return it;
}

ListaRegistro *crearLista(){
    ListaRegistro * l = (ListaRegistro*)malloc(sizeof(struct ListaRegistros));
    l->frs=NULL;
    return l;
}

NodoUsuario *copyData(NodoUsuario *n1,NodoUsuario *n2){
    n1->edad = n2->edad;n1->nr = n2->nr;
    strcpy(n1->sexo, n2->sexo);strcpy(n1->hr, n2->hr);
    strcpy(n1->caq, n2->caq);n1->fen = n2->fen;
    n1->nombre = n2->nombre;
    return n1;
}

void ordenar(ListaRegistro *l){
    NodoUsuario *p = NULL, *s = NULL, *aux = NULL;
    aux = (NodoUsuario*)malloc(sizeof(struct NodoUsuarios));
    int edad = 0;
    p = l->frs;
    while(p->nxt != NULL){
        s = p -> nxt;
        while(s != NULL){
            if(p->edad > s -> edad){
                aux->nxt=s->nxt;aux->ant=s->ant;
                aux = copyData(aux,p);
                p = copyData(p,s);
                s = copyData(s,aux);
            }
            s = s-> nxt;
        }
        p = p->nxt;
        s = p->nxt;
    }
    printf("\n\n CONSOLA >> Cola ordenada");
    printList(l);
}

NodoUsuario *getFN(NodoUsuario *p){
    int bol = 1;
    printf("\n\n Fecha de nacimiento");
    while(bol == 1){printf("\n A%co: ", 164);scanf("%i", &p->fen.an); bol = getErrors(p, 3);}
    bol = 1;while(bol == 1){printf(" Mes: ");scanf("%i", &p->fen.mn); bol = getErrors(p, 1);}
    bol = 1;while(bol == 1){printf(" Dia: ");scanf("%i", &p->fen.dn); bol = getErrors(p, 2);}
    p->edad = getAge(p);
    return p;
}

int getAge(NodoUsuario *pt){
    int gte = 2022 - pt->fen.an;
    if((10-pt->fen.mn) <= 0 && (29-pt->fen.dn) <= 0){
        gte -= 1;
        return gte;
    }else{return gte;}
}

int getErrors(NodoUsuario *pt, int tipo){
    int valorMes = pt->fen.mn;int valorDia = pt->fen.dn;
    if(tipo == 1){
        if(valorMes < 13 && valorMes > 0){
            if(pt->fen.an == 2022){
                if(valorMes > 10){
                    printf("\n\n ERROR >> Ingresa un mes valido");
                    return 1;
                }else{return 0;}
            }else{return 0;}
        }else{
            printf("\n\n ERROR >> Ingresa un mes valido");
            return 1;
        }
    }else if(tipo == 3){
        if(pt->fen.an < 2023 && pt->fen.an > 0){
            return 0;
        }else{
            printf("\n\n ERROR >> Ingresa un a%co valido", 164);
            return 1;}
    }else if(tipo == 2){
        if(pt->fen.an == 2022){
            if(valorDia > 29){
                printf("\n\n ERROR >> Ingresa un dia valido");
                return 1;
            }
        }
        if(valorMes == 2){if(valorDia > 28){
                printf("\n\n ERROR >> Ingresa un dia valido");
                return 1;}else{return 0;}
        }else if(valorMes == 1 || valorMes == 3 || valorMes == 5 || valorMes == 7 || valorMes == 8 || valorMes == 10 || valorMes == 12){
            if(valorDia > 31){
                printf("\n\n ERROR >> Ingresa un dia valido");
                return 1;
            }else{return 0;}
        }else if(valorMes == 4 || valorMes == 6 || valorMes == 9 || valorMes == 11){
            if(valorDia > 30){
                printf("\n\n ERROR >> Ingresa un dia valido");
                return 1;
            }else{return 0;}
        }
    }else{return 0;}
}

void insertNode(ListaRegistro *INrgs){
    NodoUsuario *p = NULL, *node = NULL;
    INrgs->ite ++;
    node=(NodoUsuario*)malloc(sizeof(struct NodoUsuarios));
    printf("\n------------------------------------------------------------------>");
    printf("\n\n Ingresar paciente con numero de registro: %i", INrgs->ite);fflush(stdin);
    printf("\n\n Nombre: ");gets(node->nombre.nombre);
    printf("\n Apellido paterno: ");gets(node->nombre.aPaterno);
    printf("\n Apellido materno: ");gets(node->nombre.aMaterno);
    printf("\n Sexo: ");gets(node->sexo);fflush(stdin);
    getFN(node);fflush(stdin);
    printf("\n\n Consultorio al que asiste: ");gets(node->caq);
    printf("\n Horario: ");gets(node->hr);fflush(stdin);
    printf("\n------------------------------------------------------------------>");
    node->nr = INrgs->ite;

    if(isEmpty(INrgs) == 0){
        INrgs -> frs = node;
        node -> ant = NULL;
    }else{
        p = INrgs -> fnl;
        p -> nxt = node;
        node -> ant = p;
    }
    node -> nxt = NULL;
    INrgs -> fnl = node;

    printf("\n\n CONSOLA >> Usuario ingresado con exito");
}

void deleteNode(ListaRegistro *DNrgs){
    if(isEmpty(DNrgs) != 0){
        NodoUsuario *p = DNrgs->frs, *node = NULL;
        char dnsel;
        printf("\n|-------------------------------------------------------------->");
        printf("\n| Paciente con numero de registro: %i", p->nr);
        printf("\n|");
        printf("\n| Nombre: %s %s %s", p->nombre.nombre, p->nombre.aPaterno,p->nombre.aMaterno);
        printf("\n| Genero: %s", p->sexo);
        printf("\n|");
        printf("\n| Fecha de nacimiento[dd/mm/aa]: %i / %i / %i", p->fen.dn, p->fen.mn, p->fen.an);
        printf("\n| Edad: %i", p->edad);
        printf("\n|");
        printf("\n| Consultorio al que asiste: %s", p->caq);
        printf("\n| Horario: %s", p->hr);
        printf("\n|-------------------------------------------------------------->");
        printf("\n Quieres eliminar al paciente?[\'S\' o \'N\']: ");scanf("%s", &dnsel);
        dnsel = tolower(dnsel);
        if(dnsel == 's'){
            if(isEmpty(DNrgs) == 1){
                p = NULL;
                DNrgs -> frs = NULL;
            }else{
                DNrgs -> frs = p -> nxt;
                node  = p -> nxt;
                node -> ant = NULL;
                p = NULL;
            }
            free(p);
            printf("\n\n CONSOLA >> Paciente eliminado con exito");
        }else{printf("\n\n CONSOLA >> Operacion cancelada con exito");}
    }else{printf("\n\n ERROR >> La cola esta vacia");}
}

void reporte(ListaRegistro *SPCLista){
    if(isEmpty(SPCLista) != 0){
        NodoUsuario *p = NULL;
        int ite = 0,bol = 1;char refe[50];
        printf("\n\n CONSOLA >> Ingresa el consultorio de referencia: ");fflush(stdin);gets(refe);
        p = SPCLista -> frs;
        while(p != NULL){
            if(strcmp(refe, p->caq) == 0){
                bol = 0;
                ite ++;
            }
            p = p -> nxt;
        }
        if(bol == 1){printf("\n\n ERROR >> El consultorio de referencia no se econtro.");}
        else{printf("\n\n El numero de pacientes que el consultorio recibio es: %i", ite);} 
    }else{printf("\n\n ERROR >> La cola esta vacia");}
}

void searchPConsult(ListaRegistro *SPCLista){
    if(isEmpty(SPCLista) != 0){
        NodoUsuario *p = NULL;
        int bol = 1;char refe[50];
        printf("\n\n CONSOLA >> Ingresa el consultorio de referencia: ");fflush(stdin);gets(refe);
        p = SPCLista -> frs;
        while(p != NULL){
            if(strcmp(refe, p->caq) == 0){
                bol = 0;
                printf("\n|-------------------------------------------------------------->");
                printf("\n| Paciente con numero de registro: %i", p->nr);
                printf("\n|");
                printf("\n| Nombre: %s %s %s", p->nombre.nombre, p->nombre.aPaterno,p->nombre.aMaterno);
                printf("\n| Genero: %s", p->sexo);
                printf("\n|");
                printf("\n| Fecha de nacimiento[dd/mm/aa]: %i / %i / %i", p->fen.dn, p->fen.mn, p->fen.an);
                printf("\n|");
                printf("\n| Consultorio al que asiste: %s", p->caq);
                printf("\n| Horario: %s", p->hr);
                printf("\n|-------------------------------------------------------------->");
            }
            p = p -> nxt;
        }
        if(bol == 1){printf("\n\n ERROR >> El consultorio de referencia no se econtro.");}
    }else{printf("\n\n ERROR >> La cola esta vacia");}
}

void searchPID(ListaRegistro *SPCLista){
    if(isEmpty(SPCLista) != 0){
        NodoUsuario *p = NULL;
        int bol = 1, refe;
        printf("\n\n CONSOLA >> Ingresa el ID de referencia: ");scanf("%i", &refe);
        p = SPCLista -> frs;
        while(p != NULL){
            if(refe == p->nr){
                bol = 0;
                printf("\n------------------------------------------------------------------>");
                printf("\n\n Modificar paciente con numero de registro: %i", p->nr);fflush(stdin);
                printf("\n\n Nombre: ");gets(p->nombre.nombre);
                printf("\n Apellido paterno: ");gets(p->nombre.aPaterno);
                printf("\n Apellido materno: ");gets(p->nombre.aMaterno);
                printf("\n Sexo: ");gets(p->sexo);fflush(stdin);
                getFN(p);fflush(stdin);
                printf("\n\n Consultorio al que asiste: ");gets(p->caq);
                printf("\n Horario: ");gets(p->hr);fflush(stdin);
                printf("\n------------------------------------------------------------------>");
            }
            p = p -> nxt;
        }
        if(bol == 1){printf("\n ERROR >> El ID de referencia no se econtro.");}
    }else{printf("\n\n ERROR >> La cola esta vacia");}
}

void printList(ListaRegistro *PLLista){
    if(isEmpty(PLLista) != 0){
        NodoUsuario *p = NULL;
        p = PLLista -> frs;
        while(p != NULL){
                printf("\n|-------------------------------------------------------------->");
                printf("\n| Paciente con numero de registro: %i", p->nr);
                printf("\n|");
                printf("\n| Nombre: %s %s %s", p->nombre.nombre, p->nombre.aPaterno,p->nombre.aMaterno);
                printf("\n| Genero: %s", p->sexo);
                printf("\n|");
                printf("\n| Fecha de nacimiento[dd/mm/aa]: %i / %i / %i", p->fen.dn, p->fen.mn, p->fen.an);
                printf("\n|");
                printf("\n| Consultorio al que asiste: %s", p->caq);
                printf("\n| Horario: %s", p->hr);
            p = p -> nxt;
        }printf("\n|-------------------------------------------------------------->");
    }else{printf("\n\n ERROR >> La cola esta vacia");}
}

void doSelects(char DSSel, ListaRegistro *DSrgs){
    switch(DSSel){
        case 'a':
            insertNode(DSrgs);break;
        case 'b':
            deleteNode(DSrgs);break;
        case 'c':
            searchPConsult(DSrgs);break;
        case 'd':
            ordenar(DSrgs);break;
        case 'e':
            searchPID(DSrgs);break;
        case 'f':
            reporte(DSrgs);break;
        case 'g':
            break;
        default:
            printf("\n\n ERROR >> Ingresa una opcion valida");
    }
}

void menu(){
    printf("\n_________________________________________________________");
    printf("\n|                                                       |");
    printf("\n|  Base de datos, pacientes                             |");
    printf("\n|                                                       |");
    printf("\n|  A. Altas                       B. Bajas              |");
    printf("\n|  C. Mostrar por consultorio     D. Ordenar por edad   |");
    printf("\n|  E. Modificar                   F. Reporte            |");
    printf("\n|  G. Salir                                             |");
    printf("\n|_______________________________________________________|");
}

void main(){
    char Sel;
    Sel = 'a';
    ListaRegistro *rgs;

    rgs = crearLista();
    rgs->ite = 0;

    while(Sel != 'g'){
        menu();
        Sel = getSelect();
        system("cls");
        doSelects(Sel, rgs);
        printf("\n");
        system("PAUSE");
        system("cls");
    }
    VaciarQ(rgs);
}
