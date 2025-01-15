
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.o fun_vet_base.o
	g++ main.o fun_vet_base.o -o main.x  ${INCS} ${LIBS} -std=c++17 -lstdc++fs

main.o: main.C vector_operation.h eq_diff.h 
	g++ -c main.C  ${INCS} ${LIBS} -std=c++17 -lstdc++fs



fun_vet_base.o: fun_vet_base.C vector_operation.h fun_vet_base.h eq_diff.h
	g++ -c fun_vet_base.C

clean: 
	rm main.x
	rm *.o
	rm -r graph
	