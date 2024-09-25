functions.o: functions.h functions.C
	g++ functions.C -c 

esercizio1.3.o: esercizio1.3.C
	g++ esercizio1.3.C -c 

esercizio1.3.x: esercizio1.3.o functions.o
	g++ esercizio1.3.o functions.o -o esercizio1.3.x

esegui: esercizio1.3.x
	./esercizio1.3.x 365 1941.dat

