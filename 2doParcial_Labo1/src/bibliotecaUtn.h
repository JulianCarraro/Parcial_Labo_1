/*
 * bibliotecaUtn.h
 *
 *  Created on: 21 abr. 2022
 *      Author: carra
 */

#ifndef BIBLIOTECAUTN_H_
#define BIBLIOTECAUTN_H_

int mostrarArrayChar(char array[], int len);

int ordenarArray(int pArray[], int len);

int mostrarArrayInt(int array[], int len);

int validarNumero(char cadena[]);

int validarRangoDeNumero(char * numeroIngresado, int minimo, int maximo);

int getIntInText(char *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int getFloatInText(char *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int menuPrincipal(int * opcionMenu);

int getArrayChar(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int getChars(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int getNumero(int * pResultado);

int getNumeroFlotante(float * pResultado);

int validarNumeroFlotante(char * cadena);

int myGets(char* cadena, int len);

int buscarCharEnArray(char array[], int len, char charABuscar[]);

int validarLetras(char cadena[]);

int validarFlyCode(char flyCode[]);

int getCodeChar(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int getFloat(float *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int menuModificaciones(int * opcionMenu);

int menuOrdenamiento(int * opcionMenu);


#endif /* BIBLIOTECAUTN_H_ */
