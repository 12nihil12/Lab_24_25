LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.C in_out.h stat.h
	g++ main.C in_out.h stat.h -o main.x  ${INCS} ${LIBS} -std=c++17 -lstdc++fs


clean:
	rm *.pdf
	rm Risultati.txt
	rm main.x
	rm -r graph