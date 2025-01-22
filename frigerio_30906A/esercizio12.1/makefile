LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio12.1.x: esercizio12.1.o visc.o
	g++ esercizio12.1.o visc.o -o esercizio12.1.x  ${INCS} ${LIBS}

esercizio12.1.o: esercizio12.1.C visc.h
	g++ -c esercizio12.1.C  ${INCS} ${LIBS}

visc.o: visc.C visc.h gen_rand.h
	g++ -c visc.C 

clean: 
	rm *.o
	