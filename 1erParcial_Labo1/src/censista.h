/*
 * censista.h
 *
 *  Created on: 15 may. 2022
 *      Author: carra
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

typedef struct {
	int anioNacimiento;
	int mesNacimiento;
	int diaNacimiento;
} fechaDeNacimiento;

typedef struct {
	int calle;
	int numeroDeCasa;
} eDireccion;

typedef struct {
	int idCensista;
	char nombre[51];
	char apellido[51];
	fechaDeNacimiento fecha;
	int edad;
	eDireccion direccion;
	int estado;
	int isEmpty;
} eCensista;

int incrementarId();

int inicializarCensistas(eCensista * lista, int len);

int cargarCensista(eCensista array[], int len);

int edadCensista(int anioNacimiento, int mesNacimiento);

int buscarIndexPorIsEmpty(eCensista array[], int len);

int modificarCensista(eCensista array[], int len, int idCensista);

void mostrarCensista(eCensista unCensista);

void printTitle();

int mostrarCensistas(eCensista array[], int len);

int buscarCensistaPorId(eCensista array[], int len, int idCensista);

int bajaCensista(eCensista array[], int len, int idCensista);

int hayAlgoCargado(eCensista array[], int len);

int buscarCensistaLiberadoPorId(eCensista array[], int len, int idCensista);

int hayCensistaLibreCargado(eCensista array[], int len);

void mostrarCensistaLiberado(eCensista unCensista);

int mostrarCensistasLiberados(eCensista array[], int len);

int cargaForzadaCensistas(eCensista array[], int len);

int menuModificaciones(int * opcionMenu);

int subMenuFechaNacimiento(int * opcionMenu);

int subMenuDireccion(int * opcionMenu);

int pedirDiaConMesValidado(int * mesNacimiento, int * diaNacimiento);

int pedirFechaNacimiento(int * anioNacimiento, int * mesNacimiento, int * diaNacimiento, int * edad);

#endif /* CENSISTA_H_ */
