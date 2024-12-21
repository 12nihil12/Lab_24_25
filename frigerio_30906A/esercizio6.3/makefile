main.x: main.o solver.o
	g++ main.o solver.o -o main.x

main.o: main.C fun.h solver.h
	g++ -c main.C 

solver.o: solver.C solver.h fun.h
	g++ -c solver.C 

clean: 
	rm *.o 
	rm main.x