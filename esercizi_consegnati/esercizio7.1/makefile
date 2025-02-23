LIBS:=`root-config --libs`
INCS:=`root-config --cflags`


esercizio7.1.x: esercizio7.1.o integrator.o
	g++ esercizio7.1.o integrator.o -o esercizio7.1.x ${INCS} ${LIBS}

esercizio7.1.o: esercizio7.1.C fun.h integrator.h
	g++ -c esercizio7.1.C ${INCS} ${LIBS}

integrator.o: integrator.C integrator.h fun.h
	g++ -c integrator.C 

clean: 
	rm *.o 
	rm *.txt
	