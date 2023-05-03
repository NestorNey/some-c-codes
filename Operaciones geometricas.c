#include <stdio.h>
#include <stdlib.h>
int bol;
bol = 1;

void showRes(float res){
    printf("\nResultado: %f\n", res);
}

int printThirdMenu(){
    int select;
    printf("\n\nIngresa el numero indice del prisma a elegir");
    printf("\n1. Cuadrado  2. Rectangulo  3. Triangulo  4. Circulo  5. Trapecio");
    printf("\nIngresar: ");
    scanf("%i", &select);
    return select;
}

void printSecondMenu(){
    printf("\n\nIngresa el numero indice de la figura a elegir");
    printf("\n1. Cuadrado  2. Rectangulo  3. Triangulo  4. Circulo  5. Trapecio");
}

int getSEL(){
    int select;
    printf("\nIngresar: ");
    scanf("%i", &select);
    return select;
}

float getLado(){
    float L;
    printf("\nIngresa la medida de un lado: ");
    scanf("%f", &L);
    return L;
}

float getBase(){
    float BS;
    printf("\nIngresa la medida la base: ");
    scanf("%f", &BS);
    return BS;
}

float getAltura(){
    float AL;
    printf("\nIngresa la medida la altura: ");
    scanf("%f", &AL);
    return AL;
}

float getRadio(){
    float RD;
    printf("\nIngresa la medida del radio: ");
    scanf("%f", &RD);
    return RD;
}
float getBaseMayor(){
    float BS;
    printf("\nIngresa la medida la base mayor: ");
    scanf("%f", &BS);
    return BS;
}
float getBaseMenor(){
    float BS;
    printf("\nIngresa la medida la base menor: ");
    scanf("%f", &BS);
    return BS;
}

float getPerimLados(int n){
    float result,L;
    for(int i = 1; i < n; i++){
        printf("\nIngresa la medida del lado %i: ", i);
        scanf("%f", &L);
        result += L;
    }
    return result;
}

float cuadradoPerim(){
    float lado,result;
    lado = getLado();
    result = lado * 4;
    return result;
}

float rectanguloPerim(){
    float result,base,altura;
    base = getBase();
    altura = getAltura();
    result = (base * 2) + (altura * 2);
    return result;
}

float trianguloPerim(){
    float result;
    result = getPerimLados(4);
    return result;
}

float circuloPerim(){
    float radio, result;
    radio = getRadio();
    result = 3.14 * (radio * 2);
    return result;
}

float trapecioPerim(){
    float result;
    result = getPerimLados(5);
    return result;
}

float cuadradoArea(){
    float lado,result;
    lado = getLado();
    result = lado * lado;
    return result;
}

float rectanguloArea(){
    float base,altura,result;
    base = getBase();
    altura = getAltura();
    result = base * altura;
    return result;
}

float trianguloArea(){
    float base,altura,result;
    base = getBase();
    altura = getAltura();
    result = (base * altura) / 2;
    return result;
}

float circuloArea(){
    float radio,result;
    radio = getRadio();
    result = 3.14 * (radio * radio);
    return result;
}

float trapecioArea(){
    float base_mayor,base_menor,altura,result;
    base_mayor = getBaseMayor();
    base_menor = getBaseMenor();
    altura = getAltura();
    result = ((base_mayor + base_menor) / 2) * altura;
    return result;
}

float doArea(){
    float select,result;
    while(bol == 1){
        printSecondMenu();
        select = (float)getSEL();
        if(select == 1){
            result = cuadradoArea();
            bol = 0;
        }else if (select == 2){
            result = rectanguloArea();
            bol = 0;
        }else if (select == 3){
            result = trianguloArea();
            bol = 0;
        }else if (select == 4){
            result = circuloArea();
            bol = 0;
        }else if (select == 5){
            result = trapecioArea();
            bol = 0;
        }else{
            printf("\nERROR: No ingresaste una opcion valida");}}
    return result;
}

float doPerim(){
    float select,result;
    while(bol == 1){
        printSecondMenu();
        select = (float)getSEL();
        if(select == 1){
            result = cuadradoPerim();
            bol = 0;
        }else if (select == 2){
            result = rectanguloPerim();
            bol = 0;
        }else if (select == 3){
            result = trianguloPerim();
            bol = 0;
        }else if (select == 4){
            result = circuloPerim();
            bol = 0;
        }else if (select == 5){
            result = trapecioPerim();
            bol = 0;
        }else{
            printf("\nERROR: No ingresaste una opcion valida");}}
    return result;
}

float doVolum(){
    float result,AB,AP;
    int select;
    select = printThirdMenu();
    while(bol == 1){
        if(select <=0 && select >=6){
            printf("\nERROR: No ingresaste una opcion valida");
        }else{
            printf("\nIngrese el area de la base del prisma: ");
            scanf("%f", &AB);
            printf("\nIngrese la altura del prisma: ");
            scanf("%f", &AP);
            result = AB*AP;
            bol = 0;
        }
    }
    return result;
}

float doOP(int SEL){
    float result;
    if(SEL == 1){
        result = doArea();
        showRes(result);
    }else if(SEL == 2){
        result = doPerim();
        showRes(result);
    }else if(SEL == 3){
        result = doVolum();
        showRes(result);
    }else if(SEL == 4){
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
    printf("\n|  1. Areas      2. Perimetros  |");
    printf("\n|  3. Volumen    4. Salir       |");
    printf("\n|-------------------------------|");
}

void main(){
    int SEL;
    float res;
    SEL = 1;
    while(SEL != 4){
        printFirstMenu();
        SEL = getSEL();
        res = doOP(SEL);
        bol = 1;
        system("pause");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}
