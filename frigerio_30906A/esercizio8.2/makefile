
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.o 
	g++ main.o -o main.x  ${INCS} ${LIBS} -std=c++17 -lstdc++fs

main.o: main.C fun_vet_base.h vector_operation.h eq_diff.h 
	g++ -c main.C  ${INCS} ${LIBS} -std=c++17 -lstdc++fs


clean: 
	rm main.x
	rm *.o
	rm -r graph
	