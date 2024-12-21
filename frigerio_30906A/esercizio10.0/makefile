
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.o 
	g++ main.o -o main.x  ${INCS} ${LIBS}

main.o: main.C gen_rand.h
	g++ -c main.C  ${INCS} ${LIBS}

clean: 
	rm *.o 
	rm main.x