LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: main.x graph.x

main.x: main.o integrator.o
	g++ main.o integrator.o -o main.x  

main.o: main.C fun.h 
	g++ -c main.C  


integrator.o: integrator.C fun.h integrator.h gen_rand.h
	g++ -c integrator.C


graph.x: graph.C
	g++ graph.C -o graph.x  ${INCS} ${LIBS}s 