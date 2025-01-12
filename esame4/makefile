LIBS:=`root-config --libs`
INCS:=`root-config --cflags`


main.x: main.o integrator.o solver.o
	g++ main.o integrator.o solver.o -o main.x ${INCS} ${LIBS}

main.o: main.C fun.h int_fun.h 
	g++ -c main.C ${INCS} ${LIBS}

solver.o: solver.C solver.h int_fun.h fun.h
	g++ -c solver.C 

integrator.o: integrator.C integrator.h fun.h
	g++ -c integrator.C 