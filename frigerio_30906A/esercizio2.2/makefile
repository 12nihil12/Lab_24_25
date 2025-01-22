esercizio2.2.x: esercizio2.2.o functions.o vec_doub.o
	g++ esercizio2.2.o functions.o vec_doub.o -o esercizio2.2.x

vec_doub.o: vec_doub.h vec_doub.C 
	g++ vec_doub.C -c 

functions.o: functions.h functions.C
	g++ functions.C -c 

esercizio2.2.o: esercizio2.2.C functions.h vec_doub.h
	g++ esercizio2.2.C -c 

clean: 
	rm *.o
	rm *.txt
