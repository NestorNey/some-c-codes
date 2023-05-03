#include <stdio.h>
/*
    Nombre algoritmo: Categorias de promedios
    D.E: SEL (Selección) como entero, SLAC (Salario actual) como real, bol = verdadero como lógico
    D.S: SLAC (Salario actual), CANT_AUMN (Cantidad a aumentar), SLBR (Salario bruto) como real
    D.P: CANT_AUMN <- SLAC * 0.15 
         CANT_AUMN <- SLAC * 0.10
         SLBR <- SLAC + CANT_AUMN

    Autor: Grupo TPSI 5AM
    Fecha de inicio: 9092022   Fin: 10092022
*/
float SLAC,CANT_AUMN,SLBR;
int SEL,bol;
bol = 1;
void main(){
    while(bol == 1){
        printf("\n\nIngresa el numero indice de la opcion del menu a elegir");
        printf("\n1. Ingresar sueldo de un empleado\n2. Salir\n\nIngresar: ");
        scanf("%i", &SEL);
        switch(SEL){
            case 1:
                printf("\n\nIngresa el sueldo actual del empleado: ");
                scanf("%f", &SLAC);
                if(SLAC < 1000){
                    CANT_AUMN = SLAC * 0.15;
                    SLBR = SLAC + CANT_AUMN;
                    printf("El salario actual es: %f", SLAC);
                    printf("\nLa cantidad a aumentar es: %f", CANT_AUMN);
                    printf("\nEl salario bruto es: %f", SLBR);
                }else if(SLAC > 1000){
                    CANT_AUMN = SLAC * 0.10;
                    SLBR = SLAC + CANT_AUMN;
                    printf("El salario actual es: %f", SLAC);
                    printf("\nLa cantidad a aumentar es: %f", CANT_AUMN);
                    printf("\nEl salario bruto es: %f", SLBR);
                }
                break;
            case 2:
                bol = 0;
                break;
            default:
                printf("Ingresa una opcion valida");
        }
    }
}
