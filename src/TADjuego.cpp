/*
 * TADjuego.cpp
 *
 *  Created on: 23/12/2014
 *      Author: usuario
 */

#include "TADjuego.h"

#include "entorno.h"
#include "TADcasilla.h"
#include "TADtablero.h"

tablero JUinicializartablero (int t[MAXTAMANIO][MAXTAMANIO] , int tamanio)
{

    //Crea un tablero y lo inicia con el tama�o dado

    tablero T;

    T = TAiniciartablero ( tamanio );

    //Recorre la matriz t

    for ( int i = 0 ; i < tamanio * tamanio ; i++ )

        for ( int j = 0 ; j < tamanio * tamanio ; j++ ) {

            //Si el valor es mayor que 0 lo almacena en el tablero T y lo escribe en pantalla

            if ( t[i][j] > 0 ) {

                if ( !TAescribirnumeroinicial ( T , i , j , t[i][j] ) )     //Si hay algun fallo al introducir un número inicial

                    TEntornoMostrarMensaje ( Zona3 ,
                            "Error en inicialización" );     //Muestra mensaje de error

                TEntornoPonerNumeroInicial ( i , j , T.casillas[i][j].valor );

            }

        }

    //Devuelve el tablero incializado

    return T;

}

tablero JUinicializar (tablero &T , int &tamanio , int &aleatorioOFichero ,
        int &numValores)
{

    int tab[MAXTAMANIO][MAXTAMANIO];     //Matriz temporal

    int tiempoPausa = 500000;     //Duracion tiempo de pausa final

    //Carga configuracion

    if ( TEntornoCargarConfiguracion ( tab , tamanio , aleatorioOFichero ,
            numValores ) ) {

        //Pinta la rejilla

        TEntornoIniciar ( tamanio );

        //Inicializa el tablero de 1/2/3/4 de tama�o a trav�s de los valores en tab

        T = JUinicializartablero ( tab , tamanio );

        TEntornoActivarCasilla ( 0 , 0 );     // Coordenadas iniciales de movimientos

        TEntornoMostrarMensaje ( Zona3 , "by PABLO MACIAS" );

    }

    else {

        TEntornoMostrarMensajeFin ( "  ¡¡¡¡ERROR CARGANDO!!!!" );

        TEntornoPausa ( tiempoPausa );

    }

    return T;

}

bool JUwrite (tablero &T , int fila , int columna , int valor)
{

    if ( TAescribirnumero ( T , fila , columna , valor ) ) {

        TEntornoPonerNumero ( fila , columna , valor );

        TEntornoMostrarMensaje ( Zona1 , "Valor Correcto" );

        return true;

    }

    TEntornoMostrarMensaje ( Zona1 , "Valor Incorrecto" );

    return false;

}

bool JUdelete (tablero &T , int fila , int columna)
{

    if ( TAeliminarnumero ( T , fila , columna ) ) {

        TEntornoEliminarCasilla ( fila , columna );

        return true;

    }

    TEntornoMostrarMensaje ( Zona1 , "Casilla Bloqueada" );

    return false;

}

void JUmostrarposibles (tablero &T , int i , int j)
{

    int pos = 1;

    for ( int n = 1 ; n <= T.tamreal ; n++ ) {

        if ( TAposible ( T , i , j , n ) ) {

            TEntornoMostrarValoresPosibles ( n , pos );

            pos++;

        }

    }

}

bool JUcheck (tablero T)
{

    return !T.numerosrestantes;     //Devuelve si la variable T.numerosrestantes es 0=NULL=FALSE devuelve true

}

bool JUsolve (tablero &T)
{

    int fila , columna;     //Variables que controlan la fila y la columa de la casilla seleccionada

    int tiempoPausa = 100000;

    TEntornoMostrarMensaje ( Zona2 , "Resolviendo....." );

    if ( !TAbuscarcero ( T , fila , columna ) ) {

        return true;
    }

    for ( int valor = 1 ; valor <= T.tamreal ; valor++ ) {

        if ( TAposible ( T , fila , columna , valor ) ) {     //Comprueba si el valor esta disponible en la casilla seleccionada

            JUwrite ( T , fila , columna , valor );     //Escribe el valor en la casilla[fila][columna]

            TEntornoPausa ( tiempoPausa );     //Pausa el proceso

            if ( JUsolve ( T ) )     //Vuelve a llamar al modulo para seguir resolviendo el resto del sudoku

                return true;

            else

                //Si en el siguiente paso por el modulo no hay valores posibles elimina el valor
                JUdelete ( T , fila , columna );

        }

    }

    return false;

}

void JUtheend (bool check)
{

    TEntornoLeerTecla ( );

    if ( !check ) {

        TEntornoMostrarMensajeFin ( "         ¡¡¡¡PERDEDOR!!!!" );     //Si no esta resuelto muestra el mensaje

    }

    else {     //Si esta resuelto muestra el siguiente mensaje

        TEntornoMostrarMensajeFin ( " ¡¡¡¡EL JUEGO HA TERMINADO!!!!" );

    }

    TEntornoLeerTecla ( );

}

void JUjugar (tablero &T , int tamanio)

{
    bool salir = false; 	//Variable que indica si el juego ha terminado

    bool done = false;     //Variable que indica si el juego esta resuelto

    int fila = 0 , columna = 0;     //Variables que indican la posición inicial

    while ( !salir && !done ) {

        TipoTecla tecla = TNada;

        tecla = TEntornoLeerTecla ( );     //almacena la tecla pulsada

        //Limpia las zonas donde se muestran los mensajes de aviso

        TEntornoLimpiarValoresPosibles ( );

        TEntornoMostrarMensaje ( Zona1 , "" );

        TEntornoMostrarMensaje ( Zona2 , "" );

        switch ( tecla ) {

            case TIzquierda:     //Selecciona la celda de la izquierda

                TEntornoDesactivarCasilla ( fila , columna );

                if ( columna > 0 )

                    columna--;

                TEntornoActivarCasilla ( fila , columna );

                break;

            case TDerecha:     //Selecciona la celda de la derecha

                TEntornoDesactivarCasilla ( fila , columna );

                if ( columna < ( tamanio * tamanio ) - 1 )

                    columna++;

                TEntornoActivarCasilla ( fila , columna );

                break;

            case TArriba:     //Selecciona la celda de arriba

                TEntornoDesactivarCasilla ( fila , columna );

                if ( fila > 0 )

                    fila--;

                TEntornoActivarCasilla ( fila , columna );

                break;

            case TAbajo:     //Selecciona la celda de abajo

                TEntornoDesactivarCasilla ( fila , columna );

                if ( fila < ( tamanio * tamanio ) - 1 )

                    fila++;

                TEntornoActivarCasilla ( fila , columna );

                break;

            case TSalir:     //Cambia la variable de "salir" para salor del bucle

                salir = true;

                break;

            case TX:     //Ejecuta el modulo que soluciona el sudoku, en el caso de que no halla solución lo muestra por pantalla

                if ( !JUsolve ( T ) ) {

                    TEntornoMostrarMensaje ( Zona2 , "NO HAY SOLUCIÓN" );

                }
                else

                    TEntornoMostrarMensaje ( Zona2 , "SOLUCIÓN ENCONTRADA" );

                break;

            case TEnter:     //Muestra los posibles valor en la celda seleccionada

                JUmostrarposibles ( T , fila , columna );

                break;

            case TEliminar:     //Elimina el valor de la casilla seleccionada

                JUdelete ( T , fila , columna );

                break;

            case TUno:     //Introduce el valor 1 en la casilla seleccionada

                JUwrite ( T , fila , columna , 1 );

                break;

            case TDos:     //Introduce el valor 2 en la casilla seleccionada

                JUwrite ( T , fila , columna , 2 );

                break;

            case TTres:     //Introduce el valor 3 en la casilla seleccionada

                JUwrite ( T , fila , columna , 3 );

                break;

            case TCuatro:     //Introduce el valor 4 en la casilla seleccionada

                JUwrite ( T , fila , columna , 4 );

                break;

            case TCinco:     //Introduce el valor 5 en la casilla seleccionada

                JUwrite ( T , fila , columna , 5 );

                break;

            case TSeis:     //Introduce el valor 6 en la casilla seleccionada

                JUwrite ( T , fila , columna , 6 );

                break;

            case TSiete:     //Introduce el valor 7 en la casilla seleccionada

                JUwrite ( T , fila , columna , 7 );

                break;

            case TOcho:     //Introduce el valor 8 en la casilla seleccionada

                JUwrite ( T , fila , columna , 8 );

                break;

            case TNueve:     //Introduce el valor 9 en la casilla seleccionada

                JUwrite ( T , fila , columna , 9 );

                break;

            case TA:     //Introduce el valor 10 en la casilla seleccionada

                JUwrite ( T , fila , columna , 10 );

                break;

            case TB:     //Introduce el valor 11 en la casilla seleccionada

                JUwrite ( T , fila , columna , 11 );

                break;

            case TC:     //Introduce el valor 12 en la casilla seleccionada

                JUwrite ( T , fila , columna , 12 );

                break;

            case TD:     //Introduce el valor 13 en la casilla seleccionada

                JUwrite ( T , fila , columna , 13 );

                break;

            case TE:     //Introduce el valor 14 en la casilla seleccionada

                JUwrite ( T , fila , columna , 14 );

                break;

            case TF:     //Introduce el valor 15 en la casilla seleccionada

                JUwrite ( T , fila , columna , 15 );

                break;

            case TG:     //Introduce el valor 16 en la casilla seleccionada

                JUwrite ( T , fila , columna , 16 );

                break;

            default:

                break;

        }     // fin switch

        if ( JUcheck ( T ) )     //Modifica la variable salir si el sudoku esta resuelto

            done = true;     //Cambia la variable done a true

    }     //fin while

    JUtheend ( done );     //Finaliza el juego

}

