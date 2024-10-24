main.x: main.o posizione.o particella.o campo_vett.o punto_mat.o
	g++ main.o posizione.o particella.o campo_vett.o punto_mat.o -o main.x

posizione.o: posizione.C posizione.h
	g++ posizione.C -c 

particella.o: particella.C particella.h
	g++ particella.C -c 


campo_vett.o: campo_vett.C campo_vett.h
	g++ campo_vett.C -c 

punto_mat.o: punto_mat.C punto_mat.h
	g++ punto_mat.C -c 


main.o: main.C posizione.h particella.h campo_vett.h punto_mat.h
	g++ main.C -c 