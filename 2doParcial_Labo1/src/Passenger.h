/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Linkedlist.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char * price, char * apellidoStr, char* tipoPasajeroStr, char * codigoVuelostr, char * estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int * estadoVuelo);

int Passenger_getAll(Passenger* this, int * id, char * nombre, char * apellido, float * precio, int * tipoPasajero, char * codigoVuelo, int * estadoDeVuelo);

void printTitle();
void Passenger_printOne(Passenger * this);

Passenger* requestPassengerData(char * id);
//int Passenger_edit(Passenger * this, char id);
int Passenger_edit(Passenger * this);

int Passenger_compareId(void * firstPassenger, void * secondPassenger);
int Passenger_compareName(void * firstPassenger, void * secondPassenger);
int Passenger_compareLastName(void * firstPassenger, void * secondPassenger);
int Passenger_comparePrice(void * firstPassenger, void * secondPassenger);
int Passenger_compareFlyCode(void * firstPassenger, void * secondPassenger);
int Passenger_compareTypePassenger(void * firstPassenger, void * secondPassenger);
int Passenger_compareStatusFlight(void * firstPassenger, void * secondPassenger);

int Passenger_findLastId(char * path, char * id);
int Passenger_increaseId(char * id);
int Passenger_writeNewId(char * path, char * id);
int Passenger_findPassengerById(LinkedList* pArrayListPassenger, int idABuscar);
int convertTypePassengerToInt(char typePassenger[], int * typePassengerInt);
int convertFlightStatusToInt(char flightStatus[], int * flightStatusInt);

int convertTypePassengerToChar(int typePassengerInt,char typePassenger[]);
int convertStatusFlightToChar(int flightStatusInt, char flightStatus[]);

int buscarStatusFlightByFlyCode(LinkedList* pArrayListPassenger, char flyCode[]);

#endif /* PASSENGER_H_ */
