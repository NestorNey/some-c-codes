Algoritmo promediosGrupos
	Definir CALF  Como Real
	Definir REP,APR,NOTA,SOBR,EXC como entero
	Para i<-1 Hasta 40 Con Paso 1 Hacer
		Escribir "Ingresa la calificacion (promedio del 1 al 10) del alumno numero ", i, ": "
		Leer CALF
		Si CALF > 0 y CALF < 5 Entonces
			REP <- REP + 1
			Escribir "Categoria del alumno: Reprobado"
		FinSi
		Si CALF >= 5 y CALF < 6.5 Entonces
			APR <- APR + 1
			Escribir "Categoria del alumno: Aprobado"
		FinSi
		Si CALF >= 6.5 y CALF < 8.5 Entonces
			NOTA <- NOTA + 1
			Escribir "Categoria del alumno: Notable"
		FinSi
		Si CALF >= 8.5 y CALF < 10 Entonces
			SOBR <- SOBR + 1
			Escribir "Categoria del alumno: Sobresaliente"
		FinSi
		Si CALF = 10 Entonces
			EXC <- EXC + 1
			Escribir "Categoria del alumno: Excelente"
		FinSi
	Fin Para
	Escribir "Lista de categorias"
	Escribir "Reprobados: ", REP
	Escribir "Aprobados: ", APR
	Escribir "Notables: ", NOTA
	Escribir "Sobresalientes: ", SOBR
	Escribir "Excelentes: ", EXC
FinAlgoritmo