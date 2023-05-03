#include <stdio.h>
#include <windows.h>
/*
    Nombre algoritmo: Categorias de promedios
    D.E: SEL (Selección) como entero, SALDO como real, bol = verdadero, bol2 = verdadero (Booleanos) como lógicos
    D.S: SLAC (Saldo actual o final), SLPP (Saldo para operación) como real.
    D.P: SLPP = SLAC + SALDO
    Autor: Grupo TPSI 5AM
    Fecha de inicio: 9092022   Fin: 10092022
*/
float SALDO,SLPP;
int SEL, i, i2,SEL2;
int bol = 1;
int bol2 = 1;
float SLAC = 1850;
void main(){
    void dibujarMenu(){
        //Intento de dibujar un menu :_C
        char t[200] = "Bienvendio al cajero.Ingresa el numero indice de las operacionesque aparecen en el menu.1. Ingresar saldo2. Retirar saldo3. Consultar saldo4. Retirar targeta (salir)";
        for(int i = 1; i < 14; i++){printf("\n");
            if(i==1|i==13){for(i2=2;i2<50;i2++){printf("-");if(i2==49|i2==1){printf(">");}}}if(i==2|i==4|i==7|i==12){printf("|");}
            if(i==3|i==5|i==6|i==8|i==9|i==10|i==11){for(i2=0;i2<50;i2++){if(i2==0){printf("|  ");}switch(i){case 3:
            for(i2;i2<=20;i2++){printf("%c", t[i2]);}break;case 5:for(i2=21;i2<=63;i2++){printf("%c", t[i2]);}break;case 6:
            for(i2=64;i2<=87;i2++){printf("%c", t[i2]);}break;case 8:for(i2=88;i2<=104;i2++){printf("%c", t[i2]);}break;case 9:
            for(i2=105;i2<=120;i2++){printf("%c", t[i2]);}break;case 10:for(i2=121;i2<=138;i2++){printf("%c", t[i2]);}break;
            case 11:for(i2=139;i2<=168;i2++){printf("%c", t[i2]);}break;}}}
        }
    }
    int checkErrors(float n1, float n2, char ch){
        if(ch == 's'){
            if(n1 < 0){
                return 0;
            }
        }
        if(ch == 'r'){
            if(n1 < 0){
                return 0;
            }
            if(n1 > n2){
                return 0;
            }
        }
        return 1;
    }
    while(bol == 1){
        dibujarMenu();
        printf("\nIngresar: ");
        scanf("%i", &SEL);
        bol2 = 1;
        switch(SEL){
            case 1:
                while(bol2 == 1){
                    printf("\n--------------------------------------------------->");
                    printf("\n|");
                    printf("\n|  Saldo actual: $%f", SLAC);
                    printf("\n|");
                    printf("\n|  Escribe la cantidad a ingresar: $");
                    scanf("%f", &SALDO);
                    if(checkErrors(SALDO,SLAC,'s')==1){
                        SLPP = SLAC + SALDO;
                        printf("\n|");
                        printf("\n|");
                        printf("\n|  Tu saldo final sera de: %f", SLPP);
                        printf("\n|");
                        printf("\n|  1. Continuar                  2. Regresar al menu");
                        printf("\n|");
                        printf("\n|  Ingresar: ");
                        scanf("%i", &SEL);
                        switch(SEL){
                            case 1:
                                SLAC = SLPP;
                                bol2 = 0;
                                printf("\n|  Operacion exitosa, saldo actual: $%f", SLAC);
                                printf("\n--------------------------------------------------->\n\n");
                                system("pause");
                                break;
                            case 2:
                                printf("\n|  Operacion Cancelada...   ");
                                printf("\n--------------------------------------------------->\n\n");
                                system("pause");
                                bol2 = 0;
                                break;
                        }
                    }else{
                        printf("\n|  No puedes ingresar un numero negativo.");
                        printf("\n|  Operacion Cancelada...   ");
                        printf("\n--------------------------------------------------->\n\n");
                        system("pause");
                        bol2 = 0;
                    }
                }
                break;
            case 2:
                while(bol2 == 1){
                    printf("\n--------------------------------------------------->");
                    printf("\n|");
                    printf("\n|  Saldo actual: $%f", SLAC);
                    printf("\n|");
                    printf("\n|  Escribe la cantidad a retirar: $");
                    scanf("%f", &SALDO);
                    if(checkErrors(SALDO,SLAC,'r')==1){
                        SLPP = SLAC - SALDO;
                        printf("\n|");
                        printf("\n|");
                        printf("\n|  Tu saldo final sera de: %f", SLPP);
                        printf("\n|");
                        printf("\n|  1. Continuar                  2. Regresar al menu");
                        printf("\n|");
                        printf("\n|  Ingresar: ");
                        scanf("%i", &SEL);
                        switch(SEL){
                            case 1:
                                SLAC = SLPP;
                                bol2 = 0;
                                printf("\n|  Operacion exitosa, saldo actual: $%f", SLAC);
                                printf("\n--------------------------------------------------->\n\n");
                                system("pause");
                                break;
                            case 2:
                                printf("\n|  Operacion Cancelada...   ");
                                printf("\n--------------------------------------------------->\n\n");
                                system("pause");
                                bol2 = 0;
                                break;
                        }
                    }else{
                        printf("\n|  No puedes ingresar un numero negativo o mas\n|  grande que el de tu saldo actual.");
                        printf("\n|  Operacion Cancelada...   ");
                        printf("\n--------------------------------------------------->\n\n");
                        system("pause");
                        bol2 = 0;
                    }
                }
                break;
            case 3:
                printf("\n--------------------------------------------------->");
                printf("\n|");
                printf("\n|  Saldo actual: $%f", SLAC);
                printf("\n|");
                printf("\n--------------------------------------------------->\n\n");
                system("pause");
                break;
            case 4:
                bol = 0;
                printf("\nPrograma terminado\n\n");
                break;
            default:
                printf("Elige una opcion valida");
        }
    }
}
