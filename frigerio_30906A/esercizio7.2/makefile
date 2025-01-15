main.x: main.o integrator.o
	g++ main.o integrator.o -o main.x 

main.o: main.C fun.h 
	g++ -c main.C 

integrator.o: integrator.C integrator.h fun.h
	g++ -c integrator.C 


clean: 
	rm *.o 
	rm main.x
	