LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.o prisma.o
	g++  main.o prisma.o -o main.x  ${INCS} ${LIBS}

main.o: main.C prisma.h
	g++ -c main.C  ${INCS} ${LIBS}

prisma.o: prisma.C prisma.h gen_rand.h
	g++ -c prisma.C 

clean: 
	rm *.o
	rm main.x