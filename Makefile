all: HomoVectors

OBJ=HomoVectors.o Matrices.o Scheme.o

HomoVectors: $(OBJ)
	g++ -o HomoVectors $(OBJ) -lgmpxx -lgmp

HomoVectors.o: HomoVectors.cpp Scheme.h params.h Matrix.h
	g++ -c HomoVectors.cpp

Scheme.o: Scheme.cpp Scheme.h Matrix.h
	g++ -c Scheme.cpp

Matrices.o: Matrices.cpp Matrix.h
	g++ -c Matrices.cpp

clean:
	rm -f HomoVectors $(OBJ)

