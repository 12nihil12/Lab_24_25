LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.o esp.o
	g++  main.o esp.o -o main.x  ${INCS} ${LIBS}

main.o: main.C 
	g++ -c main.C  ${INCS} ${LIBS}

esp.o: esp.C esp.h gen_rand.h
	g++ -c esp.C 

clean: 
	rm *.o
	rm main.x