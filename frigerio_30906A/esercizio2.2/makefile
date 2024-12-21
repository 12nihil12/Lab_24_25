main.x: main.o functions.o vec_doub.o
	g++ main.o functions.o vec_doub.o -o main.x

vec_doub.o: vec_doub.h vec_doub.C 
	g++ vec_doub.C -c 

functions.o: functions.h functions.C
	g++ functions.C -c 

main.o: main.C
	g++ main.C -c 

clean: 
	rm main.x
	rm *.o
	rm *.txt
