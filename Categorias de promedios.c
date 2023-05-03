#include <stdio.h>
/*
    Nombre algoritmo: Categorias de promedios
    D.E: CALF (Calificación del alumno) como real
    D.S: REP(Reprobados), APR(Aprobados), NOTA(Notables), SOBR(Sobresalientes), EXC(Excelentes) como entero
    D.P: REP = REP + 1
         APR = APR + 1
         NOTA = NOTA + 1
         SOBR = SOBR + 1
         EXC = EXC + 1
    Autor: Grupo TPSI 5AM
    Fecha de inicio: 9092022   Fin: 10092022
*/
float CALF;
int REP,APR,NOTA,SOBR,EXC;

void main(){
    for(int i = 1; i < 41; i++){
        printf("\n\nIngresa la calificacion del alumno numero %i: ", i);
        scanf("%f", &CALF);
        if(CALF > 0 && CALF < 5){
            REP += 1;
            printf("La categoria del alumno es: Reprobado");
        }else if(CALF >= 5 && CALF < 6.5){
            APR += 1;
            printf("La categoria del alumno es: Aprobado");
        }else if(CALF >= 6.5 && CALF < 8.5){
            NOTA += 1;
            printf("La categoria del alumno es: Notable");
        }else if(CALF >= 8.5 && CALF < 10){
            SOBR += 1;
            printf("La categoria del alumno es: Sobresaliente");
        }else if(CALF == 10){
            EXC += 1;
            printf("La categoria del alumno es: Aprobado");
        }
    }
    printf("\n\n\nLista de categorias");
    printf("\n\nReprobados: %i\n\nAprobados: %i\n\nNotables: %i\n\nSobresalientes: %i\n\nExcelentes: %i\n\n"
           , REP, APR, NOTA, SOBR, EXC);
}
