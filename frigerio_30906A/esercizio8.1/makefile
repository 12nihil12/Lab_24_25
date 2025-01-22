
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio8.1.x: esercizio8.1.o fun_vet_base.o
	g++ esercizio8.1.o fun_vet_base.o -o esercizio8.1.x  ${INCS} ${LIBS} -std=c++17 -lstdc++fs

esercizio8.1.o: esercizio8.1.C vector_operation.h eq_diff.h fun_vet_base.h
	g++ -c esercizio8.1.C  ${INCS} ${LIBS} -std=c++17 -lstdc++fs

fun_vet_base.o: fun_vet_base.C vector_operation.h fun_vet_base.h
	g++ -c fun_vet_base.C

clean: 
	rm *.o
	rm -r graph
	