//============================================================================
// Name        : SudokuEntorno.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "entorno.h"
#include "TADjuego.h"

using namespace std;

int main() {
	tablero T;

	int tamanio;   //número de subtableros de Sudoku por fila
				   //o columna, valores posibles 1, 2, 3 o 4

	int aleatorioOFichero, numValores;

	T=JUinicializar(T, tamanio, aleatorioOFichero, numValores);
	JUjugar(T, tamanio);



	return 0;
}
