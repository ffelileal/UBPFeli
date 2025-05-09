Algoritmo  Parcial2
    Definir nombres Como Cadena
    Definir saldos, apuestasNumero, apuestasMonto, historialSorteos Como Entero
    Definir cantidadJugadores, sorteosRealizados, i, j, numeroGanador, premio, jugadorIndex Como Entero
    Definir nombreBuscar, auxNombre Como Cadena
    Definir hayJugadoresConSaldo Como Logico
	
    
    Dimension nombres[5] 
    Dimension saldos[5] 
    Dimension apuestasNumero[5]
    Dimension apuestasMonto[5] 
    Dimension historialSorteos[10] 
	
    cantidadJugadores <- 0
    sorteosRealizados <- 0
	
    Escribir "=== Registro de jugadores ==="
    Escribir "Cuantos jugadores van a apostar? (max 5): "
    Leer cantidadJugadores
    Si cantidadJugadores > 5 Entonces
        cantidadJugadores <- 5
    FinSi
	
    Para i <- 1 Hasta cantidadJugadores
        Escribir "Nombre del jugador #", i, ": "
        Leer nombres[i]
        saldos[i] <- 1500
    FinPara
	
    Repetir
        Escribir ""
        Escribir "=== Jugadores ==="
        Para i <- 1 Hasta cantidadJugadores
            Escribir nombres[i], " | Saldo: $", saldos[i]
        FinPara
		
        Escribir ""
        Escribir "=== Apuestas ==="
        Para i <- 1 Hasta cantidadJugadores
            Escribir nombres[i], ", elige un numero del 0 al 9: "
            Leer apuestasNumero[i]
            Escribir "Monto a apostar ($): "
            Leer apuestasMonto[i]
			
            Si apuestasMonto[i] > saldos[i] Entonces
                Escribir "No tenés saldo suficiente. Apostás todo lo que tenés ($", saldos[i], ")"
                apuestasMonto[i] <- saldos[i]
            FinSi
        FinPara
		
        numeroGanador <- Aleatorio(0, 9)
        
        
        Si sorteosRealizados < 10 Entonces
            historialSorteos[sorteosRealizados + 1] <- numeroGanador
            sorteosRealizados <- sorteosRealizados + 1
        FinSi
		
        Escribir ""
        Escribir "El numero ganador es: ", numeroGanador
		
        Para i <- 1 Hasta cantidadJugadores
            Si apuestasNumero[i] = numeroGanador Entonces
                premio <- apuestasMonto[i] * 5
                saldos[i] <- saldos[i] + premio
                Escribir nombres[i], " ganó $", premio, "!"
            Sino
                saldos[i] <- saldos[i] - apuestasMonto[i]
            FinSi
        FinPara
		
        Escribir ""
        Escribir "=== Historial de sorteos ==="
        Para i <- 1 Hasta sorteosRealizados
            Escribir "Sorteo #", i, ": ", historialSorteos[i]
        FinPara
		
        hayJugadoresConSaldo <- Falso
        Para i <- 1 Hasta cantidadJugadores
            Si saldos[i] > 0 Entonces
                hayJugadoresConSaldo <- Verdadero
            FinSi
        FinPara
		
    Hasta Que hayJugadoresConSaldo = Falso O sorteosRealizados = 10
	
    Escribir ""
    Escribir "=== Fin del sistema de apuestas ==="
    Para i <- 1 Hasta cantidadJugadores
        Escribir nombres[i], " | Saldo: $", saldos[i]
    FinPara
	
    Escribir ""
    Escribir "=== Historial final de sorteos ==="
    Para i <- 1 Hasta sorteosRealizados
        Escribir "Sorteo #", i, ": ", historialSorteos[i]
    FinPara
	
    Escribir ""
    Escribir "Ingresa el nombre de un jugador para buscar: "
    Leer nombreBuscar
    jugadorIndex <- -1
    Para i <- 1 Hasta cantidadJugadores
        Si nombres[i] = nombreBuscar Entonces
            jugadorIndex <- i
        FinSi
    FinPara
	
    Si jugadorIndex <> -1 Entonces
        Escribir "Jugador ", nombreBuscar, " encontrado. Saldo: $", saldos[jugadorIndex]
    Sino
        Escribir "Jugador no encontrado."
    FinSi
FinAlgoritmo
