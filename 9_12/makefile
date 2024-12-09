LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: main.x graph.x

main.x: main.o prisma.o
	g++ main.o prisma.o -o main.x  ${INCS} ${LIBS}

main.o: main.C gen_rand.h prisma.h 
	g++ -c main.C  ${INCS} ${LIBS}




prisma.o: prisma.C prisma.h gen_rand.h
	g++ -c prisma.C 