LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: main.x graph.x

main.x: main.o integrator.o
	g++ main.o integrator.o -o main.x  -std=c++17 -lstdc++fs

main.o: main.C fun.h 
	g++ -c main.C  -std=c++17 -lstdc++fs


integrator.o: integrator.C fun.h integrator.h gen_rand.h
	g++ -c integrator.C 


graph.x: graph.C
	g++ graph.C -o graph.x  ${INCS} ${LIBS}

clean: 
	rm *.o *.x 
	rm  -r int_values-