#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*     Ingresar una factura.
       Mostrar las facturas del mes.
       Imprimir todas las facturas.
       Ordenar por numero de factura
       Ordenar por nombre del cliente
       Salir.                                */
typedef struct fecha_struct{
    int day;
    int mth;
    int year;
}Tfecha;

typedef struct domicilio_struct{
    char calle[30];
    char Cty[30];
    char Cp[5];
    int NExt;
    int NInt;
}Tdomicilio;

typedef struct factura_struct{
    int noFac;
    float STotal;
    char nombre[50];
    char rfc[13];
    Tfecha CFecha;
    Tdomicilio domicilio;
}Tfactura;

void fillDb(Tfactura FDbStruct[], int FDbMetaData[]){
    Tfactura ts[2];
    int fac = FDbMetaData[0];int MaxFacs = FDbMetaData[1];int i = fac;int bol;int ADia,AMes;
    int intArray[5];char charArray[5];
    char sl;char TRFC[13];
    if(fac <= MaxFacs){
        fflush(stdin);
        printf("\n_______________________________________________________/\n\n Factura en base de datos numero: %i", i);
        printf("\n\n Numero de la factura: ");scanf("%i", &FDbStruct[i].noFac);
        printf("\n A%co: ", 164);scanf("%i", &FDbStruct[i].CFecha.year);fflush(stdin);
        bol=1;while(bol == 1){printf("\n Mes: ");scanf("%i", &ts[1].CFecha.mth);bol = getErrors(1, ts);};FDbStruct[i].CFecha.mth = ts[1].CFecha.mth;
        bol=1;while(bol == 1){printf("\n Dia: ");scanf("%i", &ts[1].CFecha.day);bol = getErrors(2, ts);};FDbStruct[i].CFecha.day = ts[1].CFecha.day;
        fflush(stdin);printf("\n\n Nombre: ");gets(FDbStruct[i].nombre);
        bol=1;while(bol == 1){printf("\n RFC: ");gets(ts[1].rfc);bol = getErrors(3, ts);};strcpy(FDbStruct[i].rfc, ts[1].rfc);
        printf("\n\n Calle: ");gets(FDbStruct[i].domicilio.calle);fflush(stdin);
        printf("\n No. Exterior: ");scanf("%i", &FDbStruct[i].domicilio.NExt);fflush(stdin);
        printf("\n Cuenta con numero interior?['Y' / 'N']: ");scanf("%s", &sl);fflush(stdin);
        if(sl == 'Y'){
            printf("\n No. Interior: ");scanf("%i", &FDbStruct[i].domicilio.NInt);fflush(stdin);
        }else{FDbStruct[i].domicilio.NInt = 0;}
        bol=1;while(bol == 1){printf("\n Codigo postal: ");gets(ts[1].domicilio.Cp);bol = getErrors(4, ts);};strcpy(FDbStruct[i].domicilio.Cp, ts[1].domicilio.Cp);
        printf("\n Ciudad: ");gets(FDbStruct[i].domicilio.Cty);fflush(stdin);
        printf("\n\n Subtotal: ");scanf("%f", &FDbStruct[i].STotal);fflush(stdin);
        printf("\n_______________________________________________________/");
        FDbMetaData[0] += 1;
    }else{
        printf("\n ERROR: Ya ingresaste mas facturas de las permitidas.");
        printf("\n Limite de facturas: 500");
    }
}

void menu(){
    printf("\n_______________________________________________________/\n|");
    printf("\n| Base de datos de facturas.\n|\n|");
    printf("\n| Ingresa el numero indice de la opcion a elegir.\n|\n|");
    printf("\n| 1. Ingresar una factura\n|");
    printf("\n| 2. Mostrar las facturas del mes\n|");
    printf("\n| 3. Imprimir todas las facturas\n|");
    printf("\n| 4. Ordenar por numero de factura\n|");
    printf("\n| 5. Ordenar por nombre del cliente\n|");
    printf("\n| 6. Salir");
    printf("\n|______________________________________________________/");
}

int getSelection(){
    int seleccion;
    printf("\n\n Ingresar: ");
    scanf("%i", &seleccion);
    return seleccion;
}

int getErrors(int tipo,  Tfactura GTTS[]){
    int valorMes = GTTS[1].CFecha.mth;int valorDia = GTTS[1].CFecha.day;int valorRFC = GTTS[1].rfc;
    int valorCp[5];strcpy(valorCp, GTTS[1].domicilio.Cp);
    if(tipo == 1){
        if(valorMes < 13 && valorMes > 0){
            return 0;
        }else{
            printf("\n ERROR: Ingresa un mes valido");
            return 1;
        }
    }else if(tipo == 2){
        if(valorMes == 2){
            if(valorDia > 28){
                printf("\n ERROR: El dia que ingresaste es mayor al numero de dias del mes");
                return 1;
            }else{return 0;}
        }else if(valorMes == 1 || valorMes == 3 || valorMes == 5 || valorMes == 7 || valorMes == 8 || valorMes == 10 || valorMes == 12){
            if(valorDia > 31){
                printf("\n ERROR: El dia que ingresaste es mayor al numero de dias del mes");
                return 1;
            }else{return 0;}
        }else if(valorMes == 4 || valorMes == 6 || valorMes == 9 || valorMes == 11){
            if(valorDia > 30){
                printf("\n ERROR: El dia que ingresaste es mayor al numero de dias del mes");
                return 1;
            }else{return 0;}
        }
    }else if(tipo == 3){
        if(strlen(valorRFC) <= 13 && strlen(valorRFC) >= 12 ){
            return 0;
        }else{
            printf("\n ERROR: El RFC debe de constar de 13 dijitos maximo y 12 minimo");
            return 1;
        }
    }else if(tipo == 4){
        if(strlen(valorCp) == 5){return 0;}
        else{printf("\n EEROR: El codigo postal consta de 5 digitos.");return 1;}
    }
}

void arraycpy(Tfactura a[], Tfactura b[], int c){
    for(int i = 1; i < c + 1 + 1; i++){
        a[i] = b[i];
    }
}

void searchDb(Tfactura SDbStruc[], int SDbMetaData[]){
    Tfactura temp[11];arraycpy(temp, SDbStruc, SDbMetaData[0]);
    ordPMth(temp, SDbMetaData);
    int idc = 1;
    int Fnl = SDbMetaData[0] - 1;
    int M,Mf;
    printf("\n Ingresa el mes que quieres buscar.");
    int VaB = getSelection();
    while(1 == 1){
        M = floor((idc + Fnl) / 2);
        if(VaB > temp[M].CFecha.mth){
            idc = M + 1;
        }else if(VaB < temp[M].CFecha.mth){
            Fnl = M - 1;
        }else if(VaB == temp[M].CFecha.mth){
            Mf = M;
            while(temp[Mf + 1].CFecha.mth == VaB){
                Mf += 1;
            }
            while(temp[M - 1].CFecha.mth == VaB){
                M -= 1;
            }
            showDb(M,Mf,temp,SDbMetaData);
            return;
        }
        if(M == 0 || M == SDbMetaData[0] - 1){
            printf("\n ERROR: El mes que ingresaste no se encuentra en la base de datos");
            return;
        }
    }    
}

void doSelects(int DsSEL, Tfactura DsCliente[], int DsMetaData[]){
    switch (DsSEL){
        case 1:
            fillDb(DsCliente, DsMetaData);break;
        case 2:
            searchDb(DsCliente, DsMetaData);break;
        case 3:
            showDb(1, DsMetaData[0] - 1,DsCliente, DsMetaData);break;
        case 4:
            ordPFac(DsCliente, DsMetaData);break;
        case 5:
            ordPName(DsCliente, DsMetaData);break;
        case 6:
            break;
        default:
            printf("\n ERROR: Ingresa una opcion valida.");
    }
}



void showDb(int A, int B, Tfactura SoDbStruc[], int SoDbMetaData[]){
    int FcAc = SoDbMetaData[0];float total,des,stotal;
    printf("\n_______________________________________________________/\n|");
    for(int i = A; i < B + 1; i++){
        printf("\n| Factura numero: %i", SoDbStruc[i].noFac);
        printf("\n| Fecha(AA,MM,DD): %i / %i / %i", SoDbStruc[i].CFecha.year, SoDbStruc[i].CFecha.mth, SoDbStruc[i].CFecha.day);
        printf("\n|\n| Datos personales");
        printf("\n|\n|  Nombre: %s", SoDbStruc[i].nombre);
        printf("\n|  RFC: %s", SoDbStruc[i].rfc);
        printf("\n|\n|  Domicilio");
        printf("\n|\n|  Calle: %s", SoDbStruc[i].domicilio.calle);
        printf("\n|  No. Exterior: %i", SoDbStruc[i].domicilio.NExt);
        if(SoDbStruc[i].domicilio.NInt != 0){printf("\n|  No. Interior: %i", SoDbStruc[i].domicilio.NInt);}
        printf("\n|  Codigo postal: %s", SoDbStruc[i].domicilio.Cp);
        printf("\n|  Ciudad: %s", SoDbStruc[i].domicilio.Cty);
        printf("\n|\n|  Compra");
        printf("\n|\n|  Subtotal: %f", SoDbStruc[i].STotal);
        printf("\n_______________________________________________________/\n");
        stotal += SoDbStruc[i].STotal;
    }
    des = stotal * 0.16;
    total = stotal - des;
    printf("\n| Subtotal: %f", stotal);
    printf("\n| Total con iva: %f", total);
    printf("\n| Descuento restado(IVA 16%%): %f", des);
    printf("\n_______________________________________________________/\n");
}

void ordPMth(Tfactura OPcStruc[], int OPcMetaData[]){
    Tfactura temp_struc[1];int FcAc = OPcMetaData[0];
    for(int i = FcAc; i > 1; i--){
        for(int j = 1; j < i; j++){
            if(OPcStruc[j].CFecha.mth > OPcStruc[j + 1].CFecha.mth){
                temp_struc[0] = OPcStruc[j];
                OPcStruc[j] = OPcStruc[j + 1];
                OPcStruc[j + 1] = temp_struc[0];
            }
        }
    }
}

void ordPFac(Tfactura OPcStruc[], int OPcMetaData[]){
    Tfactura temp_struc[1];int FcAc = OPcMetaData[0];
    for(int i = 1; i < FcAc; i++){
        for(int j = FcAc; j >= i; j--){
            if(OPcStruc[j - 1].noFac > OPcStruc[j].noFac){
                temp_struc[0] = OPcStruc[j - 1];
                OPcStruc[j - 1] = OPcStruc[j];
                OPcStruc[j] = temp_struc[0];
            }
        }
    }
    printf("\n Base de datos ordenada por numero de factura");
}

void ordPName(Tfactura OPcStruc[], int OPcMetaData[]){
    Tfactura temp_struc[1];int FcAc = OPcMetaData[0];
    for(int i = FcAc - 1; i > 0; i--){
        for(int j = 1; j < i; j++){
            if(strcmp(OPcStruc[j].nombre, OPcStruc[j + 1].nombre) > 0){
                temp_struc[0] = OPcStruc[j];
                OPcStruc[j] = OPcStruc[j + 1];
                OPcStruc[j + 1] = temp_struc[0];
            }
        }
    }
    printf("\n Base de datos ordenada por nombre.");
}

void main(){
    Tfactura cliente[11];
    int a = 2;
    int b = a%2;
    printf("%i", b);
    int SEL = 1;
    int MetaData[2];MetaData[0] = 1;MetaData[1] = 10;

    while(SEL != 6){
        menu();
        SEL = getSelection();
        doSelects(SEL, cliente, MetaData);
        printf("\n");
        system("pause");
    }
}