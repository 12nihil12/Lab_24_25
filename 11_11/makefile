
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

rand.x: rand.o lib_random.o
	g++ rand.o lib_random.o -o rand.x  ${INCS} ${LIBS}

rand.o: rand.C lib_random.h 
	g++ -c rand.C  ${INCS} ${LIBS}


lib_random.o: lib_random.C lib_random.h
	g++ -c lib_random.C
