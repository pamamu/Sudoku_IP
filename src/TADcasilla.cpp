
/*
	Nombre: Proyecto_IP

	Autor: Pablo Macías Muñoz
	

*/

#include <iostream>
#include "TADcasilla.h"

void CAinicasilla (casilla &C)
{

    C.bloqueada = false;     //Bloquea la casilla

    C.valor = 0;     //Introduce el valor 0
//todo cambiado el m�dulo
}

bool CAcasillabloqueada (casilla C)
{

    return ( C.bloqueada );     //Devuelve el estado de bloquea de la casilla

}

void CAbloqcasilla (casilla &C)
{

    C.bloqueada = true;     //Bloquea la casilla

}

bool CAcasillavacia (casilla C)
{

    return ( C.valor == 0 );     //Devuelve si el valor de la casilla es 0

}

void CAwritecasilla (casilla &C , int n)
{

    C.valor = n;     //Introduce el valor n en el valor de la casilla

}

int CAleercasilla (casilla C)
{

    return C.valor;     //Devuelve el valor de la casilla

}

void CAborrarcasilla (casilla &C)
{

    C.valor = 0;     //Introduce el valor 0 en el valor de la casilla

}

//todo borrado el modulo relacionados con posibles
