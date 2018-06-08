main:main.o student.o studentOperation.o
	g++  main.o student.o studentOperation.o -o main
main.o student.o studentOperation.o:student.h
main.o studentOperation.o:studentOperation.h

clean:
	-rm main *.o
.PHONY:
	clean


