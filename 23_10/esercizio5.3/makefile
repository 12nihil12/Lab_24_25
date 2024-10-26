LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio5.3.x: esercizio5.3.o posizione.o particella.o campo_vett.o punto_mat.o
	g++ esercizio5.3.o posizione.o particella.o campo_vett.o punto_mat.o  ${INCS} ${LIBS} -o esercizio5.3.x  


posizione.o: posizione.C posizione.h
	g++  -c posizione.C -o posizione.o

particella.o: particella.C particella.h
	g++  -c particella.C -o particella.o


campo_vett.o: campo_vett.C campo_vett.h
	g++ campo_vett.C -c 

punto_mat.o: punto_mat.C punto_mat.h
	g++ punto_mat.C -c 


esercizio5.3.o: esercizio5.3.C posizione.h particella.h campo_vett.h punto_mat.h
	g++ -c esercizio5.3.C -o esercizio5.3.o ${INCS} ${LIBS}

clean: 
	rm *.o 
	rm *.x
	clear