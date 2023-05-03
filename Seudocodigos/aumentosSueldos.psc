Algoritmo aumentosSueldos
	Definir SALDO,SLAC,SLPP como real
	Definir SEL como entero
	Definir bol,bol2,bol3 como logico
	bol <- verdadero
	bol2 <- verdadero
	SLAC <- 1850
	Mientras bol = verdadero hacer
		Escribir "Ingresa el numero indice de las opciones del menu"
		Escribir "1. Ingresar dinero"
		Escribir "2. Retirar dinero"
		Escribir "3. Consultar dinero"
		Escribir "4. Retirar targeta (finalizar)"
		Leer SEL
		Segun SEL Hacer
			1:
				Mientras bol2 = verdadero Hacer
					bol3 <- verdadero
					Escribir "Saldo actual: ", SLAC
					Escribir "Escribe el monto a ingresar"
					Leer SALDO
					SLPP <- SLAC + SALDO
					Mientras bol3 = verdadero Hacer
						Escribir "Tu saldo final sera de: ", SLPP " Quieres continuar?"
						Escribir "1. Continuar                             2. Regresar"
						Leer SEL
						Segun SEL hacer
							1:
								SLAC <- SLPP
								Escribir "Operacion exitosa, Saldo final: ", SLAC
								bol3 <- falso
								bol2 <- falso
							2:
								bol3 <- falso
							De Otro Modo:
								Escribir "Ingresa una opcion valida"
						Fin Segun
					Fin Mientras
				Fin Mientras
				bol2 <- verdadero
			2:
				Mientras bol2 = verdadero Hacer
					bol3 <- verdadero
					Escribir "Saldo actual: ", SLAC
					Escribir "Escribe el monto a retirar"
					Leer SALDO
					SLPP <- SLAC - SALDO
					Mientras bol3 = verdadero Hacer
						Escribir "Tu saldo final sera de: ", SLPP " Quieres continuar?"
						Escribir "1. Continuar                             2. Regresar"
						Leer SEL
						Segun SEL hacer
							1:
								SLAC <- SLPP
								Escribir "Operacion exitosa, Saldo final: ", SLAC
								bol3 <- falso
								bol2 <- falso
							2:
								bol3 <- falso
							De Otro Modo:
								Escribir "Ingresa una opcion valida"
						Fin Segun
					Fin Mientras
				Fin Mientras
				bol2 <- verdadero
			3:
				Escribir "Cuentas con un saldo actual de: ", SLAC
			4:
				bol <- falso
			De Otro Modo:
				Escribir "Ingresa una opcion valida"
		Fin Segun
	Fin mientras
FinAlgoritmo