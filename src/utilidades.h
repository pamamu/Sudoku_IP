/**
  INTRODUCCION A LA PROGRAMACIÓN/FUNDAMENTOS DE PROGRAMACIÓN
  Curso:       2014/15

  Nombre:      utilidades.h
  Descripción: Especificación de operaciones de conversión necesarias para el proyecto Sudoku

  Autor:       Profesores de las asignaturas
  Fecha de creación:     octubre 2014
  Fecha última revisión:
*/

#ifndef SUDOKU_AMPL_FINAL_SRC_UTILIDADES_H_
#define SUDOKU_AMPL_FINAL_SRC_UTILIDADES_H_

#include <sstream>
#include <string>
using namespace std;

// Funciones de conversión

/*
 * PRE: { numero entero }
 * POST:{ convierte número dado como parámetro de entrada a string (cadena)}
 */
string  toString  (int numero) ;

/*
 * PRE: {caracter in {0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,G}}
 * POST: convierte el caracter en un número del 0 al 16
 */
int     toNumber  (char caracter);

/*
 * PRE: { 1<= tecla <= 16 }
 * POST: {devuelve el caracter correspondiente a la tecla}
 */
string  toChar    (int tecla);

#endif /* SUDOKU_AMPL_FINAL_SRC_UTILIDADES_H_ */
