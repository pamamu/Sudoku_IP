/**
  INTRODUCCION A LA PROGRAMACIÓN/FUNDAMENTOS DE PROGRAMACIÓN
  Curso:       2014/15

  Nombre:      utilidades.cpp
  Descripción: Implementación de las operaciones de conversión necesarias para el proyecto Sudoku

  Autor:       Profesores de las asignaturas
  Fecha de creación:     octubre 2014
  Fecha última revisión:
*/

#include "utilidades.h"


string toString(int numero) {
	stringstream  flujo;
	string cadena;

	flujo << numero;
	flujo >> cadena;

	return cadena;
}

int toNumber(char caracter){
	int valor;
	// valor =caracter -48;
	switch (caracter){
	case '0':
		valor=0;
		break;
	case '1':
		valor=1;
		break;
	case '2':
		valor=2;
		break;
	case '3':
		valor=3;
		break;
	case '4':
		valor=4;
		break;
	case '5':
		valor=5;
		break;
	case '6':
		valor=6;
		break;
	case '7':
		valor=7;
		break;
	case '8':
		valor=8;
		break;
	case '9':
		valor=9;
		break;
	case 'A':
		valor=10;
		break;
	case 'B':
		valor=11;
		break;
	case 'C':
		valor=12;
		break;
	case 'D':
		valor=13;
		break;
	case 'E':
		valor=14;
		break;
	case 'F':
		valor=15;
		break;
	case 'G':
		valor=16;
		break;

	}
	return valor;
}

string  toChar(int tecla){
	string valor;
	switch (tecla){
	case 1:
		valor='1';
		break;
	case 2:
		valor='2';
		break;
	case 3:
		valor='3';
		break;
	case 4:
		valor='4';
		break;
	case 5:
		valor='5';
		break;
	case 6:
		valor='6';
		break;
	case 7:
		valor='7';
		break;
	case 8:
		valor='8';
		break;
	case 9:
		valor='9';
		break;
	case 10:
		valor='A';
		break;
	case 11:
		valor='B';
		break;
	case 12:
		valor='C';
		break;
	case 13:
		valor='D';
		break;
	case 14:
		valor='E';
		break;
	case 15:
		valor='F';
		break;
	case 16:
		valor='G';
		break;

	}
	return valor;
}
