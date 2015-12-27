
/*
	Nombre: Proyecto_IP

	Autor: Pablo Macías Muñoz
	

*/

#ifndef SUDOKU_AMPL_FINAL_SRC_TADCASILLA_H_
#define SUDOKU_AMPL_FINAL_SRC_TADCASILLA_H_

const int MAX = 17; //Constante  que indica el tamaño máximo de numeros posibles en cada casilla

struct casilla
{
        bool bloqueada;
        int valor;
};


/**
 *  Módulo inicasilla
 *  PRE:  {}
 *  POST: {tipocasilla está inicializado correctamente}
 *  POST: {La casilla esta bloqueada}
 *  POST: {El valor de la celda es 0}
 *  POST: {Todos los valores son posibles(true) dentro de esta casilla}
 *  Complejidad = O(1)
 */

void CAinicasilla (casilla &C);


/**
 *  Módulo casillabloqueada
 *  PRE:{tipocasilla está inicializado correctamente}
 *  POST:{devuelve true si la casilla esta bloqueada}
 *  POST: {devuelve false si la casilla no esta bloqueada}
 *  Complejidad = O(1)
 */

bool CAcasillabloqueada (casilla C);


/**
 *  Módulo bloqcasilla
 *  PRE:  {tipocasilla está inicializado correctamente}
 *  POST: {Bloquea la casilla}
 *  Complejidad = O(1)
 */

void CAbloqcasilla (casilla &C);


/**
 *  Módulo casillavacia
 *  PRE:  {tipocasilla está inicializado correctamente}
 *  POST: {Devuelve true si la casilla está vacía}
 *  POST: {Devuelve false si la casilla no esta vacia}
 *  Complejidad = O(1)
 */
bool CAcasillavacia (casilla C);


/**
 *  Módulo writecasilla
 *  PRE:  {tipocasilla está inicializado correctamente}
 *  POST: {En la casilla C se pone el valor n }
 *  Complejidad = O(1)
 */

void CAwritecasilla (casilla &C , int n);


/**
 *  Módulo leercasilla
 *  PRE: {tipocasilla está inicializado correctamente y la casilla no este vacia}
 *  POST:{Devuelve el valor que hay en la casilla}
 *  Complejidad = O(1)
 */

int CAleercasilla (casilla C);


/**
 *  Módulo borrarcasilla
 *  PRE:{tipocasilla está inicializado correctamente, la casilla no este bloqueada(tenga un valor inicial)}
 *  POST:{borra el valor que contenía la casilla}
 *  Complejidad = O(1)
 */

void CAborrarcasilla (casilla &C);


#endif
