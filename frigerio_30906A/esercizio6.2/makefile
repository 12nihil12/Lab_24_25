esercizio6.2.x: esercizio6.2.o solver.o
	g++ esercizio6.2.o solver.o -o esercizio6.2.x 

esercizio6.2.o: esercizio6.2.C fun.h solver.h
	g++ -c esercizio6.2.C 

solver.o: solver.C solver.h fun.h
	g++ -c solver.C 

clean: 
	rm *.o
