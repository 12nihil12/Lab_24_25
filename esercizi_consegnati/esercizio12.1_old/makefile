LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.o visc.o
	g++ main.o visc.o -o main.x  ${INCS} ${LIBS}

main.o: main.C gen_rand.h visc.h 
	g++ -c main.C  ${INCS} ${LIBS}

visc.o: visc.C visc.h gen_rand.h
	g++ -c visc.C 

clean: 
	rm *.o
	rm main.x