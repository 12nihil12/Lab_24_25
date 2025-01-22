esercizio1.3.x: esercizio1.3.o functions.o
	g++ esercizio1.3.o functions.o -o esercizio1.3.x

functions.o: functions.h functions.C
	g++ functions.C -c 

esercizio1.3.o: esercizio1.3.C functions.h
	g++ esercizio1.3.C -c 

clean: 
	rm *.o
	rm *.txt


