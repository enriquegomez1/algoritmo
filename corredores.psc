Algoritmo corredores
	Escribir "velocidad de los corredores en la carrera de 1500 metros."
	escribir "¿cuantos corredores son?"
	leer corredor
	para i<-1 hasta corredor hacer
		escribir "ingrese el tiempo de cada corredor en segundos:"
		leer seg
		velocidad <- 1500/seg
		escribir "la velocidad en m/s de los corredores es: ",velocidad
	FinPara
FinAlgoritmo
