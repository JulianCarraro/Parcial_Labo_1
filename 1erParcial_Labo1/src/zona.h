/*
 * zona.h
 *
 *  Created on: 15 may. 2022
 *      Author: carra
 */

#ifndef ZONA_H_
#define ZONA_H_

#include "censista.h"

typedef struct {
	int idZona;
	int calle[4];
	int localidad;
	int inSitu;
	int virtual;
	int ausentes;
	int estado;
	int idCensista;
	int isEmpty;
} eZona;

int incrementarIdZona();

int inicializarZonas(eZona lista[], int len);

int cargarZonas(eZona array[], int len);

void mostrarLocalidades();

int buscarIndexZonaPorIsEmpty(eZona array[], int len);

void mostrarZona(eZona unaZona);

int mostrarZonas(eZona array[], int len);

int asignarZona(eZona array[], int len, int idZona, eCensista arrayCensistas[], int lenCensistas);

int cargarDatos(eZona array[], int len, int idZona, eCensista censistas[], int lenCensistas);

//int buscarZonaPorId(eZona array[], int len, int idZona);

int buscarZonaPendientePorId(eZona array[], int len, int idZona);

//int buscarZonaPendientePorId(eZona array[], int len, int idZona, eCensista arrayDos[]);

int mostrarZonasCompleto(eZona array[], int len, eCensista censistas[], int lenCensistas);

//void mostrarZonaPendientes(eZona unaZona);

int mostrarZonasPendientes(eZona array[], int len);

int hayZonaPendiente(eZona array[], int len);

int hayZonaCargada(eZona array[], int len);

int cargaForzadaZonas(eZona array[], int len);

#endif /* ZONA_H_ */
