/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaUtn.h"

/// @brief --> Esta funcion reserva espacio de memoria a un pasajero
///
/// @return --> Esta funcion retorna el puntero al espacio de memoria
Passenger* Passenger_new()
{
	Passenger *espacioEnMemoria;

	espacioEnMemoria = (Passenger*) malloc(sizeof(Passenger));

	return espacioEnMemoria;
}

/// @brief --> Esta funcion setea todos los datos ingresados
///
/// @param --> idStr Toma el id y lo retorna por referencia
/// @param --> nombreStr Toma el nombre y lo retorna por referencia
/// @param --> apellidoStr Toma el apellido y lo retorna por referencia
/// @param --> price Toma el precio y lo retorna por referencia
/// @param --> tipoPasajeroStr Toma el tipo de pasajero y lo retorna por referencia
/// @param --> codigoVuelostr Toma el codigo de vuelo y lo retorna por referencia
/// @param --> statusFlight Toma el estado de vuelo y lo retorna por referencia
/// @return --> Esta funcion retorna el puntero al pasajero
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char * apellidoStr, char * price, char* tipoPasajeroStr, char * codigoVuelostr, char * statusFlight)
{
	Passenger *puntPassenger;
	int auxTypePassenger;
	int auxFlightStatus;

	puntPassenger = Passenger_new();

	if(puntPassenger != NULL && nombreStr != NULL && apellidoStr != NULL && price != NULL
			&& tipoPasajeroStr != NULL && codigoVuelostr != NULL && statusFlight != NULL)
	{

		if(convertTypePassengerToInt(tipoPasajeroStr, &auxTypePassenger)==-1)
		{
			auxTypePassenger = atoi(tipoPasajeroStr);
		}
		if(convertFlightStatusToInt(statusFlight, &auxFlightStatus)==-1)
		{
			auxFlightStatus = atoi(statusFlight);
		}

		if(Passenger_setId(puntPassenger, atoi(idStr))==-1 || Passenger_setNombre(puntPassenger, nombreStr)==-1 ||
				Passenger_setApellido(puntPassenger, apellidoStr)==-1 || Passenger_setPrecio(puntPassenger, atof(price))==-1
		|| Passenger_setTipoPasajero(puntPassenger, auxTypePassenger)==-1 || Passenger_setCodigoVuelo(puntPassenger, codigoVuelostr)==-1
		|| Passenger_setEstadoVuelo(puntPassenger, auxFlightStatus) == -1)
		{
			Passenger_delete(puntPassenger);
		}

	}

	return puntPassenger;
}

/// @brief --> Esta funcion libera el espacio de memoria
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @return --> Esta funcion no retorna nada
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/// @brief --> Esta funcion setea el id
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> id Recibe el id
/// @return --> Esta funcion retorna 0 si se seteo correctamente o -1 si no fue asi
int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene el id
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> id Retorna el id por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion setea el nombre
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> nombre Retorna el nombre por referencia
/// @return --> Esta funcion retorna 0 si se seteo correctamente o -1 si no fue asi
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, sizeof(this->nombre));
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene el nombre
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> nombre Retorna el nombre por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion setea el apellido
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> apellido Retorna el apellido por referencia
/// @return --> Esta funcion retorna 0 si se seteo correctamente o -1 si no fue asi
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if (this != NULL && apellido != NULL)
	{
		strncpy(this->apellido, apellido, sizeof(this->apellido));
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene el apellido
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> apellido Retorna el apellido por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion setea el codigo de vuelo
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> codigoVuelo Retorna el codigo de vuelo por referencia
/// @return --> Esta funcion retorna 0 si se seteo correctamente o -1 si no fue asi
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if (this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo, codigoVuelo, sizeof(this->codigoVuelo));
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene el codigo de vuelo
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> codigoVuelo Retorna el codigo de vuelo por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion setea el tipo de pasajero
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> tipoPasajero Recibe el tipo de pasajero
/// @return --> Esta funcion retorna 0 si se seteo correctamente o -1 si no fue asi
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if (this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene el tipo de pasajero
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> tipoPasajero Retorna el tipo de pasajero por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion setea el precio
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> precio Recibe el precio
/// @return --> Esta funcion retorna 0 si se seteo correctamente o -1 si no fue asi
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if (this != NULL)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene el precio
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> precio Retorna el precio por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion setea el estado del vuelo
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> estadoVuelo Recibe el estado del vuelo
/// @return --> Esta funcion retorna 0 si se seteo correctamente o -1 si no fue asi
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int retorno = -1;

	if (this != NULL)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene el estado del vuelo
///
/// @param --> this Toma el pasajero y lo retorna por referencia
/// @param --> estadoVuelo Retorna el estado de vuelo por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getEstadoVuelo(Passenger* this,int * estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion obtiene todos los datos del pasajero
///
/// @param --> this Retorna el pasajero por referencia
/// @param --> id Retorna el id por referencia
/// @param --> nombre Retorna el nombre por referencia
/// @param --> apellido Retorna el apellido por referencia
/// @param --> precio Retorna el precio por referencia
/// @param --> tipoPasajero Retorna el tipo de pasajero por referencia
/// @param --> codigoVuelo Retorna el codigo de vuelo por referencia
/// @param --> estadoDeVuelo Retorna el estado de vuelo por referencia
/// @return --> Esta funcion retorna 0 si se obtuvo correctamente o -1 si no fue asi
int Passenger_getAll(Passenger* this, int * id, char * nombre, char * apellido, float * precio, int * tipoPasajero, char * codigoVuelo, int * estadoDeVuelo)
{
	int retorno = -1;

	if(this != NULL && id != NULL && nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && codigoVuelo != NULL && estadoDeVuelo != NULL)
	{
		if(Passenger_getId(this, id)==0 && Passenger_getNombre(this, nombre)==0 &&
				Passenger_getApellido(this, apellido)==0 && Passenger_getPrecio(this, precio)==0 &&
				Passenger_getTipoPasajero(this, tipoPasajero)==0 && Passenger_getCodigoVuelo(this, codigoVuelo)==0
				&& Passenger_getEstadoVuelo(this, estadoDeVuelo)==0)
		{
			retorno = 0;
		}

	}

	return retorno;
}

/// @brief --> Esta funcion muestra el titulo
///
/// @return --> Esta funcion no retorna nada
void printTitle()
{
	printf("+--------------------------------------------------------------------------------------------------------+");
	printf("\n|%4s |%15s |%15s |%12s |%13s |%15s |%15s|\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTADO DE VUELO");
	printf("+-----+----------------+----------------+-------------+----------------+-----------------+---------------+\n");
}

/// @brief --> Esta funcion muestra un pasajero
///
/// @param --> this Retorna el pasajero por referencia
/// @return --> Esta funcion no retorna nada
void Passenger_printOne(Passenger * this)
{
	int id;
	char nombre[256];
	char apellido[256];
	float precio;
	int tipoPasajero;
	char codigoVuelo[256];
	int estadoDeVuelo;
	char auxTipoPasajero[256];
	char auxEstadoDeVuelo[256];

	if(this != NULL)
	{
		if(Passenger_getAll(this, &id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo, &estadoDeVuelo)==0)
		{
			convertTypePassengerToChar(tipoPasajero,auxTipoPasajero);
			convertStatusFlightToChar(estadoDeVuelo,auxEstadoDeVuelo);
			printf("|%4d |%15s |%15s |%12.2f |%15s |%16s |%15s|\n", id, nombre, apellido, precio, codigoVuelo, auxTipoPasajero, auxEstadoDeVuelo);
		}
	}
}

/// @brief --> Esta funcion muestra un pasajero
///
/// @param --> id Retorna el id por referencia
/// @return --> Esta funcion retorna el puntero al pasajero
Passenger* requestPassengerData(char * id)
{
	Passenger* puntPassenger;
	char auxName[256];
	char auxLastName[256];
	char auxPrice[256];
	char auxTypePassenger[256];
	char auxFlyCode[256];
	char auxStatusFlight[256];

	puntPassenger = NULL;

	if(id != NULL)
	{
		if(getChars(auxName, sizeof(auxName), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
				3)==0 && getChars(auxLastName, sizeof(auxLastName), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
						3)==0 && getFloatInText(auxPrice, "Ingrese el precio del vuelo ($5000 - $1000000): $", "ERROR. Ingreso un precio invalido\n\n",
								1000000, 5000, 3)==0 && getIntInText(auxTypePassenger, "\nTipo de Pasajero\n\n1. FirstClass \n2. ExecutiveClass\n3. EconomyClass\n"
										"Ingrese una opcion: ", "ERROR. Ingreso una opcion incorrecta.\n\n",
										3, 1, 3)==0 && getCodeChar(auxFlyCode, sizeof(auxFlyCode),
												"\nIngrese el codigo de vuelo (max 10 caracteres): ", "ERROR. Ingreso un codigo de vuelo invalido\n\n" , 3)==0
				&& getIntInText(auxStatusFlight, "\nEstado del vuelo\n1. ATERRIZADO \n2. EN HORARIO\n3. EN VUELO\n4. DEMORADO\n"
						"Ingrese una opcion: ", "ERROR. Ingreso una opcion incorrecta.\n",
						4, 1, 3)==0)
		{
			puntPassenger = Passenger_newParametros(id, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlyCode, auxStatusFlight);
		}
	}

	return puntPassenger;
}

/// @brief --> Esta funcion muestra un pasajero
///
/// @param --> this Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 0 si se edito correctamente o -1 si no fue asi
int Passenger_edit(Passenger * this)
{
	int retorno = -1;
	int opcionMenu;
	char auxName[256];
	char auxLastName[256];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[256];
	int auxStatusFlight;
	char respuesta;

	if(this != NULL)
	{
		do
		{
			printTitle();
			Passenger_printOne(this);
			if(menuModificaciones(&opcionMenu)==0)
			{
				switch(opcionMenu)
				{
					case 1:
						if(getChars(auxName, sizeof(auxName), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
								3)==0)
						{
							Passenger_setNombre(this, auxName);
						}
						break;
					case 2:
						if(getChars(auxLastName, sizeof(auxLastName), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
								3)==0)
						{
							Passenger_setApellido(this, auxLastName);
						}
						break;
					case 3:
						if(getFloat(&auxPrice, "Ingrese el precio del vuelo ($5000 - $1000000): $ ", "ERROR. Ingreso un precio invalido\n\n",
											1000000, 5000, 3)==0)
						{
							Passenger_setPrecio(this, auxPrice);
						}
						break;
					case 4:
						if(getCodeChar(auxFlyCode, sizeof(auxFlyCode), "\nIngrese el codigo de vuelo (max 10 caracteres): ",
								"ERROR. Ingreso un codigo de vuelo invalido\n\n" , 3)==0)
						{
							Passenger_setCodigoVuelo(this, auxFlyCode);
						}
						break;
					case 5:
						if(getInt(&auxTypePassenger, "\nTipo de Pasajero\n\n1. FirstClass \n2. ExecutiveClass\n3. EconomyClass\n"
										"Ingrese una opcion: ", "ERROR. Ingreso una opcion incorrecta.\n\n",
										3, 1, 3)==0)
						{
							Passenger_setTipoPasajero(this, auxTypePassenger);
						}
						break;
					case 6:
						if(getInt(&auxStatusFlight, "\nEstado del vuelo\n1. ATERRIZADO \n2. EN HORARIO\n3. EN VUELO\n4. DEMORADO\n"
						"Ingrese una opcion: ", "ERROR. Ingreso una opcion incorrecta.\n",
						4, 1, 3)==0)
						{
							Passenger_setEstadoVuelo(this, auxStatusFlight);
						}
						break;
					case 7:
						if(getChars(&respuesta, sizeof(respuesta), "\n¿Desea volver al menu principal? s(si) o n(no): ",
								"Ingreso un caracter invalido\n", 3)==0)
						{
							retorno = 0;
						}
						break;
				}
			}
		}while(respuesta != 's');

	}

	return retorno;
}

/// @brief --> Esta funcion compara los id de dos pasajeros
///
/// @param --> firstPassenger Retorna el pasajero por referencia
/// @param --> secondPassenger Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 1 si el primer pasajero es mayor, 0 si son iguales o -1 si el segundo pasajero es mayor
int Passenger_compareId(void * firstPassenger, void * secondPassenger)
{
	int retorno = -1;
	int auxIdUno;
	int auxIdDos;

	if(firstPassenger != NULL && secondPassenger != NULL)
	{
		Passenger_getId((Passenger*)firstPassenger, &auxIdUno);
		Passenger_getId((Passenger*)secondPassenger, &auxIdDos);

		if(auxIdUno > auxIdDos)
		{
			retorno = 1;
		}
		else if(auxIdUno == auxIdDos)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion compara los nombres de dos pasajeros
///
/// @param --> firstPassenger Retorna el pasajero por referencia
/// @param --> secondPassenger Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 1 si el primer pasajero es mayor, 0 si son iguales o -1 si el segundo pasajero es mayor
int Passenger_compareName(void * firstPassenger, void * secondPassenger)
{
	int retorno = -1;
	char auxNameUno[50];
	char auxNameDos[50];

	if(firstPassenger != NULL && secondPassenger != NULL)
	{
		Passenger_getNombre((Passenger*)firstPassenger, auxNameUno);
		Passenger_getNombre((Passenger*)secondPassenger, auxNameDos);

		if(stricmp(auxNameUno, auxNameDos) > 0)
		{
			retorno = 1;
		}
		else if(stricmp(auxNameUno, auxNameDos) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/// @brief --> Esta funcion compara los apellidos de dos pasajeros
///
/// @param --> firstPassenger Retorna el pasajero por referencia
/// @param --> secondPassenger Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 1 si el primer pasajero es mayor, 0 si son iguales o -1 si el segundo pasajero es mayor
int Passenger_compareLastName(void * firstPassenger, void * secondPassenger)
{
	int retorno = -1;
	char auxLastNameUno[50];
	char auxLastNameDos[50];

	if(firstPassenger != NULL && secondPassenger != NULL)
	{
		Passenger_getApellido((Passenger*)firstPassenger, auxLastNameUno);
		Passenger_getApellido((Passenger*)secondPassenger, auxLastNameDos);

		if(stricmp(auxLastNameUno, auxLastNameDos) > 0)
		{
			retorno = 1;
		}
		else if(stricmp(auxLastNameUno, auxLastNameDos) == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion compara los precios de dos pasajeros
///
/// @param --> firstPassenger Retorna el pasajero por referencia
/// @param --> secondPassenger Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 1 si el primer pasajero es mayor, 0 si son iguales o -1 si el segundo pasajero es mayor
int Passenger_comparePrice(void * firstPassenger, void * secondPassenger)
{
	int retorno = -1;
	float auxPriceUno;
	float auxPriceDos;

	if(firstPassenger != NULL && secondPassenger != NULL)
	{
		Passenger_getPrecio((Passenger*)firstPassenger, &auxPriceUno);
		Passenger_getPrecio((Passenger*)secondPassenger, &auxPriceDos);

		if(auxPriceUno > auxPriceDos)
		{
			retorno = 1;
		}
		else if(auxPriceUno == auxPriceDos)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion compara los codigos de vuelo de dos pasajeros
///
/// @param --> firstPassenger Retorna el pasajero por referencia
/// @param --> secondPassenger Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 1 si el primer pasajero es mayor, 0 si son iguales o -1 si el segundo pasajero es mayor
int Passenger_compareFlyCode(void * firstPassenger, void * secondPassenger)
{
	int retorno = -1;
	char auxFlyCodeUno[10];
	char auxFlyCodeDos[10];

	if(firstPassenger != NULL && secondPassenger != NULL)
	{
		Passenger_getCodigoVuelo((Passenger*)firstPassenger, auxFlyCodeUno);
		Passenger_getCodigoVuelo((Passenger*)secondPassenger, auxFlyCodeDos);

		if(stricmp(auxFlyCodeUno, auxFlyCodeDos) > 0)
		{
			retorno = 1;
		}
		else if(stricmp(auxFlyCodeUno, auxFlyCodeDos) == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion compara los tipos de dos pasajeros
///
/// @param --> firstPassenger Retorna el pasajero por referencia
/// @param --> secondPassenger Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 1 si el primer pasajero es mayor, 0 si son iguales o -1 si el segundo pasajero es mayor
int Passenger_compareTypePassenger(void * firstPassenger, void * secondPassenger)
{
	int retorno = -1;
	int auxTypePassengerUno;
	int auxTypePassengerDos;

	if(firstPassenger != NULL && secondPassenger != NULL)
	{
		Passenger_getTipoPasajero((Passenger*)firstPassenger, &auxTypePassengerUno);
		Passenger_getTipoPasajero((Passenger*)secondPassenger, &auxTypePassengerDos);

		if(auxTypePassengerUno > auxTypePassengerDos)
		{
			retorno = 1;
		}
		else if(auxTypePassengerUno == auxTypePassengerDos)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion compara los estados de vuelo de dos pasajeros
///
/// @param --> firstPassenger Retorna el pasajero por referencia
/// @param --> secondPassenger Retorna el pasajero por referencia
/// @return --> Esta funcion retorna 1 si el primer pasajero es mayor, 0 si son iguales o -1 si el segundo pasajero es mayor
int Passenger_compareStatusFlight(void * firstPassenger, void * secondPassenger)
{
	int retorno = -1;
	int auxStatusFlightUno;
	int auxStatusFlightDos;

	if(firstPassenger != NULL && secondPassenger != NULL)
	{
		Passenger_getEstadoVuelo((Passenger*)firstPassenger, &auxStatusFlightUno);
		Passenger_getEstadoVuelo((Passenger*)secondPassenger, &auxStatusFlightDos);

		if(auxStatusFlightUno > auxStatusFlightDos)
		{
			retorno = 1;
		}
		else if(auxStatusFlightUno == auxStatusFlightDos)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion convierte el tipo de pasajero en un entero
///
/// @param --> typePassenger Recibe el tipo de pasajero a convertir
/// @param --> typePassengerInt Retorna el tipo de pasajero convertido
/// @return --> Esta funcion retorna 0 si se convirtio correctamente o -1 si no fue asi
int convertTypePassengerToInt(char typePassenger[], int * typePassengerInt)
{
	int auxTypePassenger;
	int retorno = -1;

	if(typePassenger != NULL && typePassengerInt != NULL)
	{
		if(stricmp(typePassenger, "FirstClass") == 0)
		{
			auxTypePassenger = 1;
			*typePassengerInt = auxTypePassenger;
			retorno = 0;
		}
		else
		{
			if(stricmp(typePassenger, "ExecutiveClass") == 0)
			{
				auxTypePassenger = 2;
				*typePassengerInt = auxTypePassenger;
				retorno = 0;
			}
			else
			{
				if(stricmp(typePassenger, "EconomyClass") == 0)
				{
					auxTypePassenger = 3;
					*typePassengerInt = auxTypePassenger;
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/// @brief --> Esta funcion convierte los estados de vuelo en un entero
///
/// @param --> flightStatus Recibe el estado de vuelo a convertir
/// @param --> flightStatusInt Retorna el estado de vuelo convertido
/// @return --> Esta funcion retorna 0 si se convirtio correctamente o -1 si no fue asi
int convertFlightStatusToInt(char flightStatus[], int * flightStatusInt)
{
	int auxFlightStatus;
	int retorno = -1;

	if(flightStatus != NULL && flightStatusInt != NULL)
	{
		if(stricmp(flightStatus, "ATERRIZADO") == 0)
		{
			auxFlightStatus = 1;
			*flightStatusInt = auxFlightStatus;
			retorno = 0;
		}
		else
		{
			if(stricmp(flightStatus, "EN HORARIO") == 0)
			{
				auxFlightStatus = 2;
				*flightStatusInt = auxFlightStatus;
				retorno = 0;
			}
			else
			{
				if(stricmp(flightStatus, "EN VUELO") == 0)
				{
					auxFlightStatus = 3;
					*flightStatusInt = auxFlightStatus;
					retorno = 0;
				}
				else
				{
					if(stricmp(flightStatus, "DEMORADO") == 0)
					{
						auxFlightStatus = 4;
						*flightStatusInt = auxFlightStatus;
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

/// @brief --> Esta funcion convierte tipos de pasajero en una cadena de caracteres
///
/// @param --> typePassengerInt Recibe el tipo de pasajero a convertir
/// @param --> typePassenger Retorna el tipo de pasajero convertido
/// @return --> Esta funcion retorna 0 si se convirtio correctamente o -1 si no fue asi
int convertTypePassengerToChar(int typePassengerInt,char typePassenger[])
{
	int retorno = -1;

	if(typePassenger != NULL)
	{
		switch(typePassengerInt)
		{
			case 1:
				strcpy(typePassenger, "FirstClass");
				retorno = 0;
				break;
			case 2:
				strcpy(typePassenger, "ExecutiveClass");
				retorno = 0;
				break;
			case 3:
				strcpy(typePassenger, "EconomyClass");
				retorno = 0;
				break;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion convierte tipos de pasajero en una cadena de caracteres
///
/// @param --> flightStatusInt Recibe el estado de vuelo a convertir
/// @param --> flightStatus Retorna el estado de vuelo convertido
/// @return --> Esta funcion retorna 0 si se convirtio correctamente o -1 si no fue asi
int convertStatusFlightToChar(int flightStatusInt, char flightStatus[])
{
	int retorno = -1;

	if(flightStatus != NULL)
	{
		switch(flightStatusInt)
		{
			case 1:
				strcpy(flightStatus, "ATERRIZADO");
				retorno = 0;
				break;
			case 2:
				strcpy(flightStatus, "EN HORARIO");
				retorno = 0;
				break;
			case 3:
				strcpy(flightStatus, "EN VUELO");
				retorno = 0;
				break;
			case 4:
				strcpy(flightStatus, "DEMORADO");
				retorno = 0;
				break;
		}
	}

	return retorno;
}

/// @brief --> Esta funcion busca el ultimo id en el archivo
///
/// @param --> path Recibe el archivo a leer
/// @param --> id Retorna el id leido
/// @return --> Esta funcion retorna 0 si se leyo correctamente o -1 si no fue asi
int Passenger_findLastId(char * path, char * id)
{
	int retorno = -1;
	char auxId[10];
	FILE * pFile;

	pFile = NULL;

	if(id != NULL && path != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(fscanf(pFile, "%[^\n]\n", auxId)==1)
			{
				strcpy(id, auxId);
				retorno = 0;
			}
		}
	}

	fclose(pFile);
	return retorno;
}

/// @brief --> Esta funcion busca el ultimo id en el archivo
///
/// @param --> id Retorna el id incrementado
/// @return --> Esta funcion retorna 0 si se leyo correctamente o -1 si no fue asi
int Passenger_increaseId(char * id)
{
	int auxId;
	int retorno = -1;

	if(id != NULL)
	{
		auxId = atoi(id);
		auxId++;
		itoa(auxId, id, 10);
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion busca el ultimo id en el archivo
///
/// @param --> path Recibe el archivo a escribir
/// @param --> id Retorna el id nuevo escrito
/// @return --> Esta funcion retorna 0 si se escribio correctamente o -1 si no fue asi
int Passenger_writeNewId(char * path, char * id)
{
	int retorno = -1;
	FILE * pFile;

	pFile = NULL;

	if(id != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			fprintf(pFile, "%s", id);
			retorno = 0;
		}
	}

	fclose(pFile);
	return retorno;
}

/// @brief --> Esta funcion busca el pasajero por el ID
///
/// @param --> pArrayListPassenger Recibe la lista donde buscara el id
/// @param --> idABuscar Recibe el id a buscar
/// @return --> Esta funcion retorna el indice del pasajero
int Passenger_findPassengerById(LinkedList* pArrayListPassenger, int idABuscar)
{
	int retorno = -1;
	int tamanioLista;
	int auxId;
	Passenger * auxPassenger;

	if(pArrayListPassenger != NULL && idABuscar > 0)
	{
		tamanioLista = ll_len(pArrayListPassenger);
		for (int i = 0; i < tamanioLista; i++)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			if(Passenger_getId(auxPassenger,&auxId) == 0 && auxId == idABuscar)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

