#include <stdio.h>
#include <stdlib.h>
int bol;
bol = 1;

void showRes(float result){
    printf("Resultado: %f", result);
}

void printSubYenMenu(){
    printf("\n\n|-------------------------------|");
    printf("\n|  Ingresa el numero indice de  |");
    printf("\n|  operacion a hacer.           |");
    printf("\n|                               |");
    printf("\n|  1. Dolar           2. Euro   |");
    printf("\n|  3. Peso                      |");
    printf("\n|                               |");
    printf("\n|-------------------------------|");
}

void printSubPesoMenu(){
    printf("\n\n|-------------------------------|");
    printf("\n|  Ingresa el numero indice de  |");
    printf("\n|  operacion a hacer.           |");
    printf("\n|                               |");
    printf("\n|  1. Dolar           2. Euro   |");
    printf("\n|  3. Yen                       |");
    printf("\n|                               |");
    printf("\n|-------------------------------|");
}

void printSubEuroMenu(){
    printf("\n\n|-------------------------------|");
    printf("\n|  Ingresa el numero indice de  |");
    printf("\n|  operacion a hacer.           |");
    printf("\n|                               |");
    printf("\n|  1. Dolar           2. Peso   |");
    printf("\n|  3. Yen                       |");
    printf("\n|                               |");
    printf("\n|-------------------------------|");
}

void printSubDolarMenu(){
    printf("\n\n|-------------------------------|");
    printf("\n|  Ingresa el numero indice de  |");
    printf("\n|  operacion a hacer.           |");
    printf("\n|                               |");
    printf("\n|  1. Euro            2. Peso   |");
    printf("\n|  3. Yen                       |");
    printf("\n|                               |");
    printf("\n|-------------------------------|");
}

int getSEL(){
    int select;
    printf("\nIngresar: ");
    scanf("%i", &select);
    return select;
}

float yenConv(int i, float i2){
    float result;
    while(bol == 1){
        if(i == 1){
            result = i2 * 0.0071;
            bol = 0;
        }else if(i==2){
            result = i2 * 0.0072;
            bol = 0;
        }else if(i==3){
            result = i2 * 0.0019;
            bol = 0;
        }else{
            printf("ERROR: Elejiste una opcion invalida");
            i = getSEL();
        }
    }
    return result;
}

float doYen(){
    int SEL;
    float result,xd;
    printf("\nIngresa la cantidad de dinero: ");
    scanf("%f", &xd);
    printSubYenMenu();
    SEL = getSEL();
    result = yenConv(SEL, xd);
    return result;
}

float pesoConv(int i, float i2){
    float result;
    while(bol == 1){
        if(i == 1){
            result = i2 * 0.050;
            bol = 0;
        }else if(i==2){
            result = i2 * 0.051;
            bol = 0;
        }else if(i==3){
            result = i2 * 7.11;
            bol = 0;
        }else{
            printf("ERROR: Elejiste una opcion invalida");
            i = getSEL();
        }
    }
    return result;
}

float doPeso(){
    int SEL;
    float result,xd;
    printf("\nIngresa la cantidad de dinero: ");
    scanf("%f", &xd);
    printSubPesoMenu();
    SEL = getSEL();
    result = pesoConv(SEL, xd);
    return result;
}

float euroConv(int i, float i2){
    float result;
    while(bol == 1){
        if(i == 1){
            result = i2 * 0.99;
            bol = 0;
        }else if(i==2){
            result = i2 * 19.63;
            bol = 0;
        }else if(i==3){
            result = i2 * 139.59;
            bol = 0;
        }else{
            printf("ERROR: Elejiste una opcion invalida");
            i = getSEL();
        }
    }
    return result;
}

float doEuro(){
    int SEL;
    float result,xd;
    printf("\nIngresa la cantidad de dinero: ");
    scanf("%f", &xd);
    printSubEuroMenu();
    SEL = getSEL();
    result = euroConv(SEL, xd);
    return result;
}

float dolarConv(int i, float i2){
    float result;
    while(bol == 1){
        if(i == 1){
            result = i2 * 1.01;
            bol = 0;
        }else if(i==2){
            result = i2 * 19.89;
            bol = 0;
        }else if(i==3){
            result = i2 * 141.35;
            bol = 0;
        }else{
            printf("ERROR: Elejiste una opcion invalida");
            i = getSEL();
        }
    }
    return result;
}

float doDolar(){
    int SEL;
    float result,xd;
    printf("\nIngresa la cantidad de dinero: ");
    scanf("%f", &xd);
    printSubDolarMenu();
    SEL = getSEL();
    result = dolarConv(SEL, xd);
    return result;
}

float doSelects(int SEL){
    float result;
    if(SEL == 1){
        result = doDolar();
    }else if(SEL == 2){
        result = doEuro();
    }else if(SEL == 3){
        result = doPeso();
    }else if(SEL == 4){
        result = doYen();
    }else if(SEL == 5){
    }else{
        result = 0;
        printf("ERROR: No ingresaste una opcion valida\n");
    }
    return result;
}

void printFirstMenu(){
    printf("\n\n|-------------------------------|");
    printf("\n|  Ingresa el numero indice de  |");
    printf("\n|  operacion a hacer.           |");
    printf("\n|                               |");
    printf("\n|  1. Dolar            2. Peso  |");
    printf("\n|  3. Euro             4. Yen   |");
    printf("\n|  5. Salir                     |");
    printf("\n|-------------------------------|");
}

void main(){
    int SEL;
    float res;
    SEL = 1;
    while(SEL != 5){
        printFirstMenu();
        SEL = getSEL();
        res = doSelects(SEL);
        bol = 1;
        if(SEL < 6 && SEL >0){showRes(res);}
        printf("\n");
        system("pause");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}
