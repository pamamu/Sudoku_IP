
/*
	Nombre: Proyecto_IP

	Autor: Pablo Macías Muñoz
	

*/

#include "TADtablero.h"
#include <iostream>
#include <cmath>

// i -> filas
// j -> columnas

tablero TAiniciartablero (int tam)
{

    tablero T;     //Decalra un tablero T

    if ( tam < 5 && tam > 0 ) {

        T.tamanio = tam;     //Introduce el tamaño(2/3/4) en la variable de tamanio

        T.tamreal = tam * tam;     //Introduce tam*tam(Tamaño real) en la variable tamreal

        T.numerosrestantes = T.tamreal * T.tamreal;     //Introduce tamreal*tamreal(casillas en el tablero) en la variable numerosrestantes

        for ( int i = 0 ; i < T.tamreal ; i++ ) {

            for ( int j = 0 ; j < T.tamreal ; j++ ) {

                CAinicasilla ( T.casillas[i][j] );     //Inicialliza todas las casillas dentro del tamaño dado

            }

        }

    }

    return T;     //Deveulve el tablero inicializado

}

bool TAcheckcoord (tablero T , int i , int j)
{

    return i >= 0 && j >= 0 && i < T.tamreal && j < T.tamreal;     //Devuelve si las coordenadas se encuentran entre 0(incluido) y el tamaño real

}

bool TAcheckvalor (tablero T , int valor)
{

    return valor > 0 && valor <= T.tamreal;     //Devuelve si el valor esta entre 0 y el tamaño real(incluido)

}

bool TAchecknumero (tablero T , int i , int j , int valor)
{

    return CAleercasilla ( T.casillas[i][j] ) == valor;     //Devuelve si el valor es igual al valor en la casilla[i][j]

}

bool TAescribirnumeroinicial (tablero &T , int i , int j , int valor)
{

    if ( TAcheckcoord ( T , i , j ) && TAcheckvalor ( T , valor ) ) {     //Comprueba que el valor y las coordenadas son correctas

        CAwritecasilla ( T.casillas[i][j] , valor );     //Escribe el el valor en la casilla[i][j]

        CAbloqcasilla ( T.casillas[i][j] );     //Bloquea la casilla[i][j]

        T.numerosrestantes--;     //Disminuye en 1 los numeros restantes

        return true;     //Devuelve true si los parametros iniciales son correctos

    }

    return false;     //Devuelve false si los parametros no son correctos

}

bool TAescribirnumero (tablero &T , int i , int j , int valor)
{

    if ( !CAcasillabloqueada ( T.casillas[i][j] )     //Comprueba si la casilla[i][j] no esta bloqueada
    		&& TAcheckcoord ( T , i , j ) && TAcheckvalor ( T , valor )     //Comprueba que el valor y las coordenadas son correctas
            && TAposible ( T , i , j , valor ) ) {     //Comprueba que en la casilla[i][j] el valor es posible

        CAwritecasilla ( T.casillas[i][j] , valor );     //Introduce el valor en la casilla[i][j]

        T.numerosrestantes--;     //Disminuye en 1 los numeros restantes

        return true;     //Devuelve true si los parametros iniciales son correctos

    }

    return false;     //Devuelve false si los parámetros iniciales no son correctos

}

bool TAeliminarnumero (tablero &T , int i , int j)
{

    if ( CAcasillavacia ( T.casillas[i][j] ) )     //Comprueba que la casilla[i][j] esta vacia

        return true;     //Devuelve true si se cumple el parametro inicial(casilla vacia)

    if ( !CAcasillabloqueada ( T.casillas[i][j] )
            && TAcheckcoord ( T , i , j ) ) {     //Comprueba eu la casilla no esta bloqueada y que las coordenadas son correctas

        CAborrarcasilla ( T.casillas[i][j] );     //Borra el contenido de la casilla[i][j]

        T.numerosrestantes++;     //Aumenta en 1 los numeros restantes

        return true;     //Devuelve true si los parametos iniciales son correctos

    }

    return false;     //Devuelve false si los parametros inciales no son correctos

}

bool TAcomprobarcolumna (tablero T , int col , int valor)
{

    for ( int i = 0 ; i < T.tamreal ; i++ ) {     //Recorre desde 0 hasta el tamaño real

        if ( TAchecknumero ( T , i , col , valor ) ) {     //Comprueba si el valor es igual al valor de la casilla[i][columna]

            return false;     //Devuelve false si se cumplen las condiciones

        }

    }

    return true;     //Devuelve true si no se cumple la condicion para ninguno de las casillas

}

bool TAcomprobarfila (tablero T , int fila , int valor)
{

    for ( int j = 0 ; j < T.tamreal ; j++ ) {     //Recorre desde 0 hasta el tamaño real

        if ( TAchecknumero ( T , fila , j , valor ) ) {     //Comprueba si el valor es igual al valor de la casilla[fila][j]

            return false;     //Devuelve false si se cumplen las condiciones
        }
    }
    return true;     //Devuelve true si no se cumple la condicion para ninguno de las casillas
}

bool TAcomprobarcuadrante (tablero T , int i , int j , int valor)
{

    int fila , colum;

    fila = ( i / T.tamanio );     //Calcula la fila del cuadrante de la casilla[i][j]

    colum = ( j / T.tamanio );     //Calcula la columna del cuadrante de la casilla[i][j]

    for ( int ii /*fila de la casilla del cuadrante*/= fila * T.tamanio ;
            ii < ( fila * T.tamanio ) + T.tamanio ; ii++ ) {     //Recorre filas(tantas como el tamaño) desde la fila inicial del cuadrante

        for ( int jj /*columna de la casilla del cuadrante*/= colum
                * T.tamanio ; jj < ( colum * T.tamanio ) + T.tamanio ; jj++ ) {     //Recorre columnas(tantas como el tamaño) desde la columa inicial del cuadrante

            if ( TAchecknumero ( T , ii , jj , valor ) ) {     //Comprueba si el valor es igual al valor de la casilla[fila][j]

                return false;;     //Devuelve false si se cumplen las condiciones

            }

        }

    }

    return true;     //Devuelve true si no se cumple la condicion para ninguno de las casillas

}

bool TAposible (tablero T , int i , int j , int valor) //todo cambiado el nombre a TAcomprobar
{

    return 	TAcomprobarfila ( T , i , valor )
            	&& TAcomprobarcolumna ( T , j , valor )
				&& TAcomprobarcuadrante ( T , i , j , valor );     //Devuelve si el valor es posible en la fila, en la columna y en el cuadrante de la casilla[i][j]

}

bool TAbuscarcero (tablero &T , int &i , int &j)
{

    for ( i = 0; i < T.tamreal ; i++ ) {     //Recorre desde el 0 hasta el tamaño real => fila

        for ( j = 0; j < T.tamreal ; j++ ) {     //Recorre desde el 0 hasta el tamaño real => columna

            if ( CAcasillavacia ( T.casillas[i][j] ) ) {     //Comprueba si la casilla[i][j] está vacia

                return true;     //Devuelve true si se cumplen las condiciones
            }
        }
    }
    return false;     //Devuelve true si no se cumple la condicion para ninguna de las casillas
}
