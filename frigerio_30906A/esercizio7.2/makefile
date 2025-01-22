esercizio7.2.x: esercizio7.2.o integrator.o
	g++ esercizio7.2.o integrator.o -o esercizio7.2.x 

esercizio7.2.o: esercizio7.2.C integrator.h fun.h 
	g++ -c esercizio7.2.C 

integrator.o: integrator.C integrator.h fun.h
	g++ -c integrator.C 


clean: 
	rm *.o 

	