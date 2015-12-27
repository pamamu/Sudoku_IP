/**

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2014/2015

	Nombre: entorno.h
	Descripción: Especificación del TAD Entorno para el proyecto sudoku.
	     	 	 Encargado del manejo de la interfaz del juego.
	Autor:	Profesores de las asignaturas
	Fecha:  25/10/2014

*/


#ifndef SUDOKU_AMPL_FINAL_SRC_ENTORNO_H_
#define SUDOKU_AMPL_FINAL_SRC_ENTORNO_H_

#include <string>
using namespace std;
// -------------------------------------------------------------
// Definicion de constantes públicas
// -------------------------------------------------------------


// Dimensiones máximas  del tablero

const int MAXTAMANIO	= 16;


// -------------------------------------------------------------
// Definicion de tipos
// -------------------------------------------------------------

/**
 *   Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
 *   de los cursores o teclas válidas que se ha pulsado
 */
enum TipoTecla {TCero,TUno, TDos, TTres, TCuatro, TCinco, TSeis, TSiete, TOcho, TNueve,
	TA, TB, TC, TD, TE, TF, TG, TEliminar,TNada,TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TSalir,  TX};

// Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
// de los cursores que se ha pulsado


/**
 *   Zonas en el entorno para imprimir mensajes. Existen 3 zonas delimitadas para imprimir un
 *   mensaje en la pantalla del entorno. Se pueden usar para imprimir mensajes de estado de
 *   diferentes tipos
 */
enum TipoZona {Zona1, Zona2, Zona3};


// -------------------------------------------------------------
// Declaración de interfaz (módulos) PÚBLICA
// -------------------------------------------------------------


/**

	PRE:  1 <= tam <= MAXTAMANIO/4,
	POST: Inicia la pantalla de juego, incluyendo una rejilla cuadrada de filas*columnas
*/
void TEntornoIniciar (int tam);


/**
	PRE: Archivo sudoku.cnf correcto y en la carpeta raíz del proyecto
	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
	POST: Devuelve:
	         TRUE:  si se carga correctamente la configuración del juego,
		     FALSE: en caso contrario.
    PARÁMETROS:
		Si la configuración se lee de forma correcta se devolverá:
		   matriz:              matriz cuadrada de tamanioxtamanio con los valores leidos de ficheros
		                        correspondientes al patrón de inicio.
		   tamanio:             número de regiones del sudoku 1= 1x1., 2= 2x2, 3=3x3, 4=4x4
		   alearorioOFichero:   0 si el patrón de inicio se genera aleatoriamente y 1 si se lee de fichero
		   NumValoresAlearorio: número de valores aleatorios a generar

		Por defecto, el archivo sudoku.cnf se encuentra en el directorio  del proyecto
 */
bool TEntornoCargarConfiguracion (int   matriz[MAXTAMANIO][MAXTAMANIO],
								  int 	&tamanio,
								  int   &aleatorioOFichero,
								  int   &numValoresAleatorios);


/**
	PRE:  fila y columna son coordenadas válidas en el entorno.
	PRE:  0 <= fila <= MAXTAMANIO,
	PRE:  0 <= columna <= MAXTAMANIO,
	POST: Enmarca una casilla con coordenadas fila, columna en un rectángulo azul.
*/
void TEntornoActivarCasilla(int fila, int columna);



/**
 *  PRE:  0 <= fila <= MAXTAMANIO,
	PRE:  0 <= columna <= MAXTAMANIO,
    PRE: fila y columna son coordenadas válidas en el entorno.
	POST: Enmarca una casilla con coordenadas fila, columna en un rectángulo blanco
*/
void TEntornoDesactivarCasilla(int fila, int columna);


/**
	PRE:  { 0 <= fila < MAXTAMANIO }
	PRE:  { 0 <= columna < MAXTAMANIO}
    PRE:  fila y columna son coordenadas válidas en el entorno.
    PRE:  { 1 <=  valor <= MAXTAMANIO}
	POST: Coloca en una casilla el "valor"
*/
void TEntornoPonerNumero(int fila, int columna, int valor);

/**
	PRE:  { 0 <= fila < MAXTAMANIO }
	PRE:  { 0 <= columna < MAXTAMANIO}
    PRE:  fila y columna son coordenadas válidas en el entorno.
    PRE:  { 1 <=  valor <=MAXTAMANIO}
	POST: Coloca en una casilla el  "valor" con el color de casilla inicial
*/

void TEntornoPonerNumeroInicial(int fila, int columna, int valor) ;

/**
 * 	PRE:  0 <= fila < MAXTAMANIO,
	PRE:  0 <= columna < MAXTAMANIO,
	PRE: fila y columna son coordenadas válidas en el tablero
	POST: Elimina del entorno el valor que existe en la casilla cuyas coordenadas son fila, columna.
*/
void TEntornoEliminarCasilla(int fila, int columna);

/**
   PRE: El módulo recibe la zona en la que imprimir el mensaje (TipoZona) y una cadena de caracteres.
        {zona in {Zona1,Zona2,Zona3}}
   POST:Escribe el mensaje pasado por parámetro en el entorno, concretamente, en la zona especificada.
*/
void TEntornoMostrarMensaje (TipoZona zona, string msg);


/**
    PRE:  cad es una cadena de caracteres a mostrar
    POST: Muestra un mensaje en el centro de la rejilla para indicar que ha finalizado el juego
*/
void TEntornoMostrarMensajeFin (string cad);

/**
    PRE:  { 1 <= valor <= MAXTAMANIO  1 <= pos <= MAXTAMANIO}
    PARAM:
    	Entrada: valor: valor posible para la posición donde me encuentre
    	pos: indica la columna de la pantalla donde pintar el valor
    POST: Muestra un valor posible en una posición
*/
void TEntornoMostrarValoresPosibles( int valor, int pos);

/**
    PRE:  {}
    POST: Limpia la zona donde se muestran los valores posibles
*/
void TEntornoLimpiarValoresPosibles( );

/**
    PRE:
    POST:Devuelve un valor enumerado de TipoTecla con la tecla que se ha pulsado
*/
TipoTecla TEntornoLeerTecla();


/*
 * PRE: pausa: Tiempo en milisegundos que dura una pausa (100000)
 * POST: lleva a cabo una pausa en la ejecución del juego para ralentizar el cambio de las fichas
 * la duración de la pausa depende de una constante (PAUSA) definida previamente
 * */

void TEntornoPausa (int pausa);




#endif

