
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.o fun_vet_base.o
	g++ main.o fun_vet_base.o -o main.x  ${INCS} ${LIBS}

main.o: main.C fun_vet_base.h vector_operation.h eq_diff.h gen_rand.h
	g++ -c main.C  ${INCS} ${LIBS}


fun_vet_base.o: fun_vet_base.C vector_operation.h fun_vet_base.h eq_diff.h
	g++ -c fun_vet_base.C

clean: 
	rm main.x
	rm *.o
	rm -r graph
	