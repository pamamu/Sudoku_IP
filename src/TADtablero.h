
/*
	Nombre: Proyecto_IP

	Autor: Pablo Macías Muñoz
	

*/

#ifndef SUDOKU_AMPL_FINAL_SRC_TADTABLERO_H_
#define SUDOKU_AMPL_FINAL_SRC_TADTABLERO_H_

#include "TADcasilla.h"

const int MAXTAM = 16; //Variable que indica el tamaño maximo del tablero(ancho y alto)

struct tablero
{
        casilla casillas[MAXTAM][MAXTAM];
        int tamanio;
        int tamreal;
        int numerosrestantes;
};


/**
 *  Módulo iniciartablero
 * 	PRE:  0 < tam <= 4,
 *  POST: Tablero esta incializado correctamente
 *  POST: Almacena el tamaño(1/2/3/4) en la variable de tamanio del TAD
 *  POST: ALmacena tamaño*tamaño en la varibel de tamreal del TAD
 *  POST: Inicializa todas las casillas en el tama�o dado
 *  Complejidad = O(n^2)
 */
tablero TAiniciartablero (int tam);


/**
 *  Módulo checkcoord
 * 	PRE:  0 <= i < T.tamreal,
 *  PRE:  0 <= j < T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si las coordenadas son correctas en el tamaño inicializado
 *  POST: Devuelve false si las coordenadas no son correctas en el tamaño inicializado
 *  Complejidad = O(1)
 */

bool TAcheckcoord (tablero T , int i , int j);


/**
 *  Módulo checkvalor
 * 	PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si el valor es correcto en el tablero en el tamaño inicializado
 *  POST: Devuelve false si el valor no es correcto en el tablero en el tamaño inicializado
 *  Complejidad = O(1)
 */

bool TAcheckvalor (tablero T , int valor);


/**
 *  Módulo checknumero
 * 	PRE:  0 <= i < T.tamreal,
 *  PRE:  0 <= j < T.tamreal,
 *  PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si el valor dado es igual al valor almacenado en la casilla dada del tablero
 *  POST: Devuelve false si el valor dado es distinto al valor almacenado en la casilla dada del tablero
 *  Complejidad = O(1)
 */

bool TAchecknumero (tablero T , int i , int j , int valor);


/**
 *  Módulo escribirnumeroinicial
 * 	PRE:  0 <= i < T.tamreal,
 *  PRE:  0 <= j < T.tamreal,
 *  PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si el n�mero se ha copiado correctamente  y ha bloqueado la casilla y disminuye en 1 los restantes
 *  POST: Devuelve false si no se ha copiado y bloqueado correctamente por no cumplir una PREcondici�n
 *  Complejidad = O(1)
 */

bool TAescribirnumeroinicial (tablero &T , int i , int j , int valor);


/**
 *  Módulo escribirnumero
 * 	PRE:  0 <= i < T.tamreal,
 *  PRE:  0 <= j < T.tamreal,
 *  PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  PRE: La celda no este bloqueada(valor inicial)
 *  PRE: El valor sea posible dentro de la casilla
 *  POST: Devuelve true si el n�mero se ha copiado correctamente y disminuye en 1 los restantes
 *  POST: Devuelve false si el n�mero no se ha copiado correctamente por no cumplir una PREcondici�n
 *  Complejidad = O(1)
 */

bool TAescribirnumero (tablero &T , int i , int j , int valor);


/**
 *  Módulo eliminarnumero
 * 	PRE:  0 <= i < T.tamreal,
 *  PRE:  0 <= j < T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  PRE: La celda no este bloqueada(valor inicial)
 *  POST: Devuelve true si el n�mero se ha eliminado correctamente(suma 1 a los restantes) o si la celda estaba vacia
 *  POST: Devuelve false si el n�mero no se ha eliminado correctamente por no cumplir una PREcondici�n
 *  Complejidad = O(1)
 */

bool TAeliminarnumero (tablero &T , int i , int j);


/**
 *  Módulo comprobarcolumna
 * 	PRE:  0 <= columna < T.tamreal,
 *  PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si el valor es posible en la columna seleccionada
 *  POST: Devuelve false si el valor no es posible en la columna seleccionada
 *  Complejidad = O(n)
 */

bool TAcomprobarcolumna (tablero T , int col , int valor);


/**
 *  Módulo comprobarfila
 * 	PRE:  0 <= fila < T.tamreal,
 *  PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si el valor es posible en la fila seleccionada
 *  POST: Devuelve false si el valor no es posible en la fila seleccionada
 *  Complejidad = O(n)
 */

bool TAcomprobarfila (tablero T , int fila , int valor);


/**
 *  Módulo comprobarcuadrante
 * 	PRE:  0 <= i < T.tamreal,
 *  PRE:  0 <= j < T.tamreal,
 *  PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si el valor es posible en el cuadrante de la casilla seleccionada
 *  POST: Devuelve false si el valor no es posible en el cuadrante de la casilla seleccionada
 *  Complejidad = O(n²)
 */

bool TAcomprobarcuadrante (tablero T , int i , int j , int valor);


/**
 *  Módulo comprobar
 * 	PRE:  0 <= i < T.tamreal,
 *  PRE:  0 <= j < T.tamreal,
 *  PRE:  0 < valor <= T.tamreal,
 *  PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si el valor es posible en el la casilla despues de comprobar en la fila, columna y cuadrante
 *  POST: Devuelve false si el valor no es posible en la casilla despues de comprobar en la fila, columna y cuadrante
 *  Complejidad = O(1)
 */

bool TAposible (tablero T , int i , int j , int valor);


/**
 * 	PRE: Tablero esta incializado correctamente
 *  POST: Devuelve true si encuentra una casilla en el tablero cuyo valor sea 0, y además modifica el valor de i y de j
 *  POST: Devuelve false si no encuentra una casilla en el tablero cuyo valor sea 0 y no modifica el valor de i y de j
 *  Complejidad = O(n²)
 */

bool TAbuscarcero (tablero &T , int &i , int &j);

#endif
