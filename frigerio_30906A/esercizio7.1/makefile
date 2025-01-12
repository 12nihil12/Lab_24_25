LIBS:=`root-config --libs`
INCS:=`root-config --cflags`


main.x: main.o integrator.o
	g++ main.o integrator.o -o main.x ${INCS} ${LIBS}

main.o: main.C fun.h 
	g++ -c main.C ${INCS} ${LIBS}

integrator.o: integrator.C integrator.h fun.h
	g++ -c integrator.C 

clean: 
	rm *.o 
	rm main.x
	