LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio12.0.x: esercizio12.0.o prisma.o
	g++  esercizio12.0.o prisma.o -o esercizio12.0.x  ${INCS} ${LIBS}

esercizio12.0.o: esercizio12.0.C prisma.h
	g++ -c esercizio12.0.C  ${INCS} ${LIBS}

prisma.o: prisma.C prisma.h gen_rand.h
	g++ -c prisma.C 

clean: 
	rm *.o
	