/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2014/2015

 Nombre: entorno.cpp
 Descripción: Implementación del TAD Entorno para el proyecto CuatroenRaya.
 Encargado del manejo de la interfaz del juego.
 Autor:	Profesores de las asignaturas
 Fecha:	25/11/2012
 Fecha última modificaciín: 10/11/2014

 */

#include "entorno.h"
#include <allegro.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "utilidades.h"

using namespace std;

// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------
// Definición de colores que usa el entorno
const int COLOR_BLANCO = 0;
const int COLOR_ROJO = 1;
const int COLOR_NEGRO = 2;
const int COLOR_AMARILLO = 3;
const int COLOR_VERDE = 4;
const int COLOR_AZUL = 5;

//const int COLOR_FONDO	  = COLOR_BLANCO;
const int COLOR_FONDO = COLOR_VERDE;
//const int COLOR_LINEAS	  = COLOR_NEGRO;
const int COLOR_LINEAS = COLOR_BLANCO;

// Tamaño de la ventana del juego
const int ANCHO_VENTANA = 800;
const int ALTO_VENTANA = 600;

// Definicón de constantes para posicionar los números en el tablero
const int DISTANCIA_COLS = 30;  // Distancia entre columnas
const int DISTANCIA_FILAS = 30;  // Distancia entre filas
const int ORIGEN_X = 20;  // Origen de las x antes 20
const int ORIGEN_Y = 20 + 40;  // Origen de las y antes 20+40
int tamReal;
// -------------------------------------------------------------
// Declaración de módulos PRIVADOS
// -------------------------------------------------------------

// define el color en función de los valores makecol - allegro library
int makecolor2(int color);

// Dibuja en la pantalla el borde de un tablero con el ancho indicado
void TEntornoPintarRejilla(int tamanio);

// Invierte fila/columna.  El tablero gráfico (entorno) se dibuja por
// Columnas/Filas, mientras en C++ se trata con matrices en Filas/Columnas.
// Para que sea transparente al uso de matrices se invierte en el entorno
void InvertirFC(int &fila, int &columna);

// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------

int makecolor2(int color) {

	int col;

	switch (color) {
	case COLOR_BLANCO:
		col = makecol(255, 255, 255);
		break;
	case COLOR_ROJO:
		col = makecol(255, 0, 0);
		break;
	case COLOR_NEGRO:
		col = makecol(0, 0, 0);
		break;
	case COLOR_AMARILLO:
		col = makecol(200, 200, 50);
		break;
	case COLOR_VERDE:
		col = makecol(0, 100, 0);
		break;
	case COLOR_AZUL:
		col = makecol(0, 0, 255);
		break;
	default:
		col = makecol(255, 255, 255);
		break; //color blanco
	}

	return col;
}

void TEntornoPintarRejilla(int tamanio) {
	// Comenzamos en la 0,0
	int i;

	acquire_screen();
	//rectfill( screen, ORIGEN_X+1, ORIGEN_Y+1, ORIGEN_X+columnas*DISTANCIA_COLS-1,ORIGEN_Y+filas*DISTANCIA_FILAS-1 , makecolor2(COLOR_FONDO));
	int columnas = tamanio * tamanio;
	int filas = tamanio * tamanio;

	// horizontales
	for (i = 0; i <= (columnas); i++) {
		if (i % tamanio == 0) {
			line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS,
					ORIGEN_X + columnas * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,

			ORIGEN_Y + i * DISTANCIA_FILAS - 1,
					ORIGEN_X + columnas * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS - 1, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS + 1,
					ORIGEN_X + columnas * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS + 1, makecolor2(COLOR_AZUL));
		} else
			line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS,
					ORIGEN_X + columnas * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS, makecolor2(COLOR_LINEAS));

	}

	//verticales
	for (i = 0; i <= (filas); i++) {
		if (i % tamanio == 0) {
			line(screen, ORIGEN_X + i * DISTANCIA_COLS,
					ORIGEN_Y + 0 * DISTANCIA_FILAS,
					ORIGEN_X + i * DISTANCIA_COLS,
					ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + i * DISTANCIA_COLS - 1,
					ORIGEN_Y + 0 * DISTANCIA_FILAS,
					ORIGEN_X + i * DISTANCIA_COLS - 1,
					ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + i * DISTANCIA_COLS + 1,
					ORIGEN_Y + 0 * DISTANCIA_FILAS,
					ORIGEN_X + i * DISTANCIA_COLS + 1,
					ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
		} else
			line(screen, ORIGEN_X + i * DISTANCIA_COLS,
					ORIGEN_Y + 0 * DISTANCIA_FILAS,
					ORIGEN_X + i * DISTANCIA_COLS,
					ORIGEN_Y + filas * DISTANCIA_FILAS,
					makecolor2(COLOR_LINEAS));
	}

	textout_ex(screen, font, "*** S U D O K U ***", 525, 30,
			makecol(0, 0, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "PROYECTO DE PROGRAMACIÓN", 525, 50,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "TECLAS:", 525, 80, makecol(255, 255, 255),
			makecol(0, 0, 0));
	textout_ex(screen, font, "Arriba: Fecha arriba", 525, 100,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Abajo:  Flecha abajo", 525, 120,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Drcha:  Flecha derecha", 525, 140,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Izqda:  Flecha izquierda", 525, 160,
			makecol(255, 255, 255), makecol(0, 0, 0));

	textout_ex(screen, font, "Salir:  Escape", 525, 180, makecol(255, 255, 255),
			makecol(0, 0, 0));
	textout_ex(screen, font, "Números del 1..9,", 525, 200,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Letras de la  A..G", 525, 220,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Enter:  valores posibles", 525, 240,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Supr:  Borrar casilla", 525, 260,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "X:  Resolver Sudoku", 525, 280,
			makecol(255, 255, 255), makecol(0, 0, 0));
	release_screen();

}

void InvertirFC(int &fila, int &columna) {

	int aux = columna;
	columna = fila;
	fila = aux;

}

// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void TEntornoIniciar(int tam) {

	// Iniciar el entorno
	allegro_init();
	install_keyboard();
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	tamReal=tam;
	// Pintar rejilla
	TEntornoPintarRejilla(tam);

}


bool TEntornoCargarConfiguracion (int   matriz[MAXTAMANIO][MAXTAMANIO],
								  int 	&tamanio,
								  int   &aleatorioOFichero,
								  int   &numValoresAleatorios){



	bool leido;
	ifstream entrada;
	string cadena;  // para recuperar la informacion de las líneas del fichero
	entrada.open("sudoku.cnf");
	if (entrada.is_open()) {
		getline (entrada, cadena);
		tamanio=atoi(cadena.c_str());

		getline (entrada, cadena);
		aleatorioOFichero= atoi(cadena.c_str());

		getline(entrada, cadena);
		numValoresAleatorios=atoi (cadena.c_str());

		for (int i = 0; i < tamanio * tamanio; i++) {
			getline(entrada, cadena);
			for (int j = 0; j < tamanio * tamanio; j++) {
				//t[i][j] = cadena[j] - 48;
				matriz[i][j] = toNumber(cadena[j]);
			}
		}

		leido = true;
		entrada.close();
	} else {
		cout
				<< "Fichero de configuración no encontrado (<proyecto>/sudoku.cnf)."
				<< endl;
		cout << "Formato:" << endl;
		cout << "\t[Tamaño del tablero 1..4]" << endl;
		cout << "\t[Aleatorio(0/se fichero(1))]" << endl;
		cout << "\t[número de valores aleatórios]" << endl;
		cout << "\t[matriz de inicio]" << endl;
		leido = false;
	}

	return leido;
}

void TEntornoActivarCasilla(int fila, int columna) {

	int color = COLOR_ROJO;

	InvertirFC(fila, columna);

	// Pinta de trazo distinto la celda
	acquire_screen();

	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS,
			makecolor2(color));
	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS + 1,
			ORIGEN_Y + columna * DISTANCIA_COLS + 1,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 1,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS - 1,
			makecolor2(color));
	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS + 2,
			ORIGEN_Y + columna * DISTANCIA_COLS + 2,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 2,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS - 2,
			makecolor2(color));
	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS + 3,
			ORIGEN_Y + columna * DISTANCIA_COLS + 3,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 3,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS - 3,
			makecolor2(color));

	release_screen();
}

void TEntornoDesactivarCasilla(int fila, int columna) {

	int color1 = COLOR_LINEAS;
	int color2 = COLOR_NEGRO;
	InvertirFC(fila, columna);

	// Pinta de trazo distinto la celda
	acquire_screen();

	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS,
			makecolor2(color1));
	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS + 1,
			ORIGEN_Y + columna * DISTANCIA_COLS + 1,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 1,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS - 1,
			makecolor2(color2));
	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS + 2,
			ORIGEN_Y + columna * DISTANCIA_COLS + 2,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 2,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS - 2,
			makecolor2(color2));
	rect(screen, ORIGEN_X + fila * DISTANCIA_FILAS + 3,
			ORIGEN_Y + columna * DISTANCIA_COLS + 3,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 3,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS - 3,
			makecolor2(color2));

	int columnas = tamReal * tamReal;
	int filas = tamReal * tamReal;
	int i;
	// horizontales
	for (i = 0; i <= (columnas); i++) {
		if (i % tamReal == 0) {
			line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS,
					ORIGEN_X + columnas * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,
			ORIGEN_Y + i * DISTANCIA_FILAS - 1,
					ORIGEN_X + columnas * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS - 1, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS + 1,
					ORIGEN_X + columnas * DISTANCIA_COLS,
					ORIGEN_Y + i * DISTANCIA_FILAS + 1, makecolor2(COLOR_AZUL));

		}
	}
	//verticales
	for (i = 0; i <= (filas); i++) {
		if (i % tamReal == 0) {
			line(screen, ORIGEN_X + i * DISTANCIA_COLS,
					ORIGEN_Y + 0 * DISTANCIA_FILAS,
					ORIGEN_X + i * DISTANCIA_COLS,
					ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + i * DISTANCIA_COLS - 1,
					ORIGEN_Y + 0 * DISTANCIA_FILAS,
					ORIGEN_X + i * DISTANCIA_COLS - 1,
					ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
			line(screen, ORIGEN_X + i * DISTANCIA_COLS + 1,
					ORIGEN_Y + 0 * DISTANCIA_FILAS,
					ORIGEN_X + i * DISTANCIA_COLS + 1,
					ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_AZUL));
		}
	}
	release_screen();
}

void TEntornoPonerNumero(int fila, int columna, int valor) {

	int pos1, pos2;

	pos1 = ORIGEN_X + columna * DISTANCIA_COLS + 10;
	pos2 = ORIGEN_Y + fila * DISTANCIA_FILAS + 10;

	acquire_screen();
	textout_ex(screen, font, toChar(valor).c_str(), pos1, pos2,
			makecolor2(COLOR_VERDE),makecol(0, 0, 0));
	release_screen();
}




void TEntornoPonerNumeroInicial(int fila, int columna, int valor) {

	int pos1, pos2;
	pos1 = ORIGEN_X + columna * DISTANCIA_COLS + 10;
	pos2 = ORIGEN_Y + fila * DISTANCIA_FILAS + 10;

	acquire_screen();
	textout_ex(screen, font, toChar(valor).c_str(), pos1, pos2, makecolor2(COLOR_AMARILLO),makecol(0, 0, 0));
	release_screen();

}


void TEntornoEliminarCasilla(int fila, int columna) {
	int color = COLOR_NEGRO;
	rectfill(screen, ORIGEN_X + columna * DISTANCIA_COLS + 1,
			ORIGEN_Y + fila * DISTANCIA_FILAS + 1,
			ORIGEN_X + columna * DISTANCIA_COLS + DISTANCIA_COLS - 1,
			ORIGEN_Y + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 1,
			makecolor2(color));
}

void TEntornoMostrarMensaje(TipoZona zona, string msg) {

	int fila;

	switch (zona) {

	case Zona1:
		fila = 520;
		break;
	case Zona2:
		fila = 540;
		break;
	case Zona3:
		fila = 560;
		break;

	default:
		return;

	}

	textout_ex(screen, font, "                                        ", 525,
			fila, makecol(255, 0, 0), makecol(0, 0, 0));
	textout_ex(screen, font, msg.c_str(), 525, fila, makecol(255, 255, 0),
			makecol(0, 0, 0));

}

void TEntornoMostrarValoresPosibles( int valor, int pos){
	int fila=400;
	int col=525+(pos*10);
	textout_ex(screen, font, "Valores posibles:                               ", 525,
				fila-15, makecol(255, 0, 0), makecol(0, 0, 0));
	textout_ex(screen, font, toChar(valor).c_str(), col, fila, makecol(255, 0, 0),
				makecol(0, 0, 0));

}
void TEntornoLimpiarValoresPosibles(){
	int fila= 400;
	rectfill(screen, fila+120, fila-20, fila+375, fila+35 , makecol(0, 0, 0));


}

void TEntornoMostrarMensajeFin(string cad) {

	int i, j;

	// Borrar un rectangulo
	rectfill(screen, 200, 200, 620, 440, makecol(0, 0, 0));

	// Efecto
	for (i = 0, j = 0; i < 40 && j < 40; i += 4, j += 4) {
		rect(screen, i + 220, j + 240, 600 - i, 400 - j, makecol(255, 0, 0));
		rect(screen, i + 222, j + 242, 598 - i, 398 - j,
				makecol(255, 255, 255));
		usleep(25000); // 25 milisegundos
	}

	// Mensaje
	textout_ex(screen, font, cad.c_str(), 280, 320, makecol(255, 255, 0),
			makecol(0, 0, 0));

}

TipoTecla TEntornoLeerTecla() {

	TipoTecla tecla = TNada;
	utoupper(readkey());

	if (key[KEY_UP])
		tecla = TArriba;
	else if (key[KEY_DOWN])
		tecla = TAbajo;
	else if (key[KEY_RIGHT])
		tecla = TDerecha;
	else if (key[KEY_LEFT])
		tecla = TIzquierda;
	else if (key[KEY_ESC])
		tecla = TSalir;
	else if (key[KEY_ENTER])
		tecla = TEnter;
	else if (key[KEY_DEL])
		tecla=TEliminar;
	else if (key[KEY_X])
		tecla = TX;
	else if (key[KEY_0])
		tecla = TCero;
	else if (key[KEY_1])
		tecla = TUno;
	else if (key[KEY_2])
		tecla = TDos;
	else if (key[KEY_3])
		tecla = TTres;
	else if (key[KEY_4])
		tecla = TCuatro;
	else if (key[KEY_5])
		tecla = TCinco;
	else if (key[KEY_6])
		tecla = TSeis;
	else if (key[KEY_7])
		tecla = TSiete;
	else if (key[KEY_8])
		tecla = TOcho;
	else if (key[KEY_9])
		tecla = TNueve;
	else if (key[KEY_A])
		tecla = TA;
	else if (key[KEY_B])
		tecla = TB;
	else if (key[KEY_C])
		tecla = TC;
	else if (key[KEY_D])
		tecla = TD;
	else if (key[KEY_E])
		tecla = TE;
	else if (key[KEY_F])
		tecla = TF;
	else if (key[KEY_G])
			tecla = TG;

	clear_keybuf();

	return tecla;

}

void TEntornoPausa(int pausa) {
	usleep(pausa);
}
