main.x: main.o functions.o
	g++ main.o functions.o -o main.x

functions.o: functions.h functions.C
	g++ functions.C -c 

main.o: main.C
	g++ main.C -c 

clean: 
	rm main.x
	rm *.o
	rm *.txt


