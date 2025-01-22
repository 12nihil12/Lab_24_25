LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio4.0.x: esercizio4.0.C in_out.h stat.h
	g++ esercizio4.0.C in_out.h stat.h -o esercizio4.0.x  ${INCS} ${LIBS} -std=c++17 -lstdc++fs


clean:
	rm *.pdf
	rm Risultati.txt
	rm -r graph