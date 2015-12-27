/*
 * TADjuego.h
 *
 *  Created on: 23/12/2014
 *      Author: usuario
 */

#ifndef SUDOKU_AMPL_FINAL_SRC_TADJUEGO_H_
#define SUDOKU_AMPL_FINAL_SRC_TADJUEGO_H_

#include "TADtablero.h"
#include "entorno.h"
#include "utilidades.h"

/**
 * 	PRE:
 * 	POST:
 * 	Complejidad:
 */

/**
 *  Módulo inicializar
 * 	PRE:  Tablero esta incializado correctamante
 * 	PRE:  tamanio y aleatorioOFichero esta inicializado correctamente
 * 	PRE:  El archivo de configuración es correcto
 *  POST: Leer el archivo de configuracion
 *  POST: Si hay algun error en el archivo de configuración, muestra un mensaje y se sale del Sudoku
 *  POST: A través de la función de Entorno.h lee el archivo de configuracion, y pinta la cuadricula activa la casilla 00
 *  POST: A través de la función JUinicializartablero almacena en la memoria el tablero con su respectiva configuración
 *  Complejidad = O(1)
 */

tablero JUinicializar (tablero &T , int &tamanio , int &aleatorioOFichero ,
        int &numValores);


/**
 *  Módulo jugar
 * 	PRE: Tablero este inicializado completamante
 * 	PRE: La variable tamanio sea correctas
 * 	POST: Antes de ejecutar cualquier accion borra los posibles de la casilla seleccionada
 * 	POST: Anted de ejecutar cualquier accion limpia la zona de mensajes
 * 	POST: Lee la tecla introducida por el usuario y dependiendo de la eleccion:
 * 	POST: TIzquierda: Selecciona la celda de la izquierda
 * 	POST: TDerecha: Selecciona la celda de la derecha
 * 	POST: TArrriba: Selecciona la celda de arriba
 * 	POST: TAbajo: Seleccioan la celda de abajo
 * 	POST: TUno: Introduce el valor 1 en la casilla seleccionada
 * 	POST: TDos: Introduce el valor 2 en la casilla seleccionada
 * 	POST: TTres: Introduce el valor 3 en la casilla seleccionada
 * 	POST: TCuatro: Introduce el valor 4 en la casilla seleccionada
 * 	POST: TCinco: Introduce el valor 5 en la casilla seleccionada
 * 	POST: TSeis: Introduce el valor 6 en la casilla seleccionada
 * 	POST: TSiete: Introduce el valor 7 en la casilla seleccionada
 * 	POST: TOcho: Introduce el valor 8 en la casilla seleccionada
 * 	POST: TNueve: Introduce el valor 9 en la casilla seleccionada
 * 	POST: TA: Introduce el valor 10 en la casilla seleccionada
 * 	POST: TB: Introduce el valor 11 en la casilla seleccionada
 * 	POST: TC: Introduce el valor 12 en la casilla seleccionada
 * 	POST: TD: Introduce el valor 13 en la casilla seleccionada
 * 	POST: TE: Introduce el valor 14 en la casilla seleccionada
 * 	POST: TF: Introduce el valor 15 en la casilla seleccionada
 * 	POST: TG: Introduce el valor 16 en la casilla seleccionada
 * 	POST: TEliminar: Elimina la casilla seleccionada
 * 	POST: TSalir: Modifica el valor de salir a true
 *  POST: Si el juego esta resuelto o la variable salir esta true ejecutaa el modulo JUtheend
 Complejidad = O(n)
 */

void JUjugar (tablero &T , int tamanio);


#endif /* SUDOKU_AMPL_FINAL_SRC_TADJUEGO_H_ */
