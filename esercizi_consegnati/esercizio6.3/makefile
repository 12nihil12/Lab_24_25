esercizio6.3.x: esercizio6.3.o solver.o
	g++ esercizio6.3.o solver.o -o esercizio6.3.x

esercizio6.3.o: esercizio6.3.C fun.h solver.h
	g++ -c esercizio6.3.C 

solver.o: solver.C solver.h fun.h
	g++ -c solver.C 

clean: 
	rm *.o 