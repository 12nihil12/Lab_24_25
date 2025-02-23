
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio8.2.x: esercizio8.2.C fun_vet_base.h vector_operation.h eq_diff.h 
	g++ esercizio8.2.C  ${INCS} ${LIBS} -std=c++17 -lstdc++fs -o esercizio8.2.x 


clean: 
	rm -r graph
	