LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main.x: main.C in_out.h 
	g++ main.C in_out.h -o main.x  ${INCS} ${LIBS}

clean: 
	rm main.x