/*
 * zona.c
 *
 *  Created on: 15 may. 2022
 *      Author: carra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaUtn.h"
#include "censista.h"
#include "zona.h"

#define OCUPADO 0
#define VACIO 1
#define LIBERADO 1
#define ACTIVO 2
#define INACTIVO 3
#define PENDIENTE 1
#define FINALIZADO 2
#define LEN_ZONAS 15
#define LEN_LOCALIDADES 5

int incrementarIdZona()
{
    static int id = 4000;
    id++;
    return id;
}

/// @brief --> Esta funcion inicializa el array de censistas
///
/// @param --> list Puntero al espacio de memoria donde se inicializara los datos
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int inicializarZonas(eZona lista[], int len)
{
	int retorno = -1;
	if (lista != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			lista[i].isEmpty = VACIO;
			retorno = 0;
		}
	}

	return retorno;
}

int cargarZonas(eZona array[], int len)
{
	int retorno = -1;
	int indexLibre;
	int i;
	int auxcalles[4];
	int auxLocalidad;

	if (array != NULL && len > 0)
	{
		indexLibre = buscarIndexZonaPorIsEmpty(array, len);

		if(indexLibre != -1)
		{
			for(i = 0; i < 4; i++)
			{
				if(getInt(&auxcalles[i], "Ingrese una calle de la manzana: ",
						"ERROR. Ingreso una calle invalido\n\n", 999, 1, 3)==0)
				{
					array[indexLibre].calle[i] = auxcalles[i];
				}
			}

			mostrarLocalidades();

			if(getInt(&auxLocalidad, "Ingrese una opcion: ",
					"ERROR. Ingreso una opcion incorrecta\n\n", 999, 1, 3)==0)
			{
				array[indexLibre].localidad = auxLocalidad;
				array[indexLibre].idZona = incrementarIdZona();
				array[indexLibre].estado = PENDIENTE;
				array[indexLibre].isEmpty = OCUPADO;
				mostrarZona(array[indexLibre]);
				retorno = 0;
			}
		}

	}
	return retorno;
}

void mostrarLocalidades()
{
	printf("\nLOCALIDADES\n\n");
	printf("1) HUDSON\n");
	printf("2) RANELAGH\n");
	printf("3) PLATANOS\n");
	printf("4) SOURIGUES\n");
	printf("5) GUTIERREZ\n");
}

/// @brief --> Esta funcion busca un espacio libre en el array
///
/// @param --> list Puntero al espacio de memoria donde se buscara el lugar libre
/// @param --> len Define el tamanio de la cadena
/// @return --> Esta funcion retorna un index libre
int buscarIndexZonaPorIsEmpty(eZona array[], int len)
{
	int retorno = -1;

	if(array != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(array[i].isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/// @brief --> Esta funcion muestra un censista
///
/// @param --> unPassenger Puntero al espacio de memoria donde se buscara el censista a mostrar
/// @return --> Esta funcion no retorna nada
void mostrarZona(eZona unaZona)
{
	char localidades[6][51] = {"", "Hudson", "Ranelagh", "Platanos", "Sourigues", "Gutierrez"};

	if(unaZona.isEmpty == 0)
	{
		printf("\n+-----------------------------------------------------------------------------------------------+");
		printf("\nID Zona: %d | Calle 1: %d | Calle 2: %d | Calle 3: %d | Calle 4: %d | Localidad: %s", unaZona.idZona,
				unaZona.calle[0], unaZona.calle[1], unaZona.calle[2], unaZona.calle[3], localidades[unaZona.localidad]);
//		printf("\n+-----------------------------------------------------------------------------------------------+");
	}
}

/// @brief --> Esta funcion muestra un censista
///
/// @param --> unPassenger Puntero al espacio de memoria donde se buscara el censista a mostrar
/// @return --> Esta funcion no retorna nada
int mostrarZonas(eZona array[], int len)
{
	int retorno = -1;

	if(array != NULL && len >0)
	{

		for(int i = 0; i < LEN_ZONAS; i++)
		{
			mostrarZona(array[i]);
		}
		printf("\n+-----------------------------------------------------------------------------------------------+\n");
		retorno = 0;
	}

	return retorno;
}


int asignarZona(eZona array[], int len, int idZona, eCensista arrayCensistas[], int lenCensistas)
{
	int retorno = -1;
	int auxIdCensista;
	int index;
	int indexCensista;

	if(array != NULL && len > 0 && arrayCensistas != NULL && lenCensistas > 0)
	{
		index = buscarZonaPendientePorId(array, len, idZona);

		if(index != -1)
		{
			mostrarCensistasLiberados(arrayCensistas, len);
			if(getInt(&auxIdCensista, "Ingrese el id del censista que desea ubicar en la zona: ",
						"ERROR. Ingreso un id incorrecto\n\n", 3000, 1000, 3)==0)
			{
				indexCensista = buscarCensistaLiberadoPorId(arrayCensistas, lenCensistas, auxIdCensista);
				if(indexCensista != -1)
				{
					array[index].idCensista = auxIdCensista;
					arrayCensistas[indexCensista].estado = ACTIVO;
					array[index].estado = PENDIENTE;
					retorno = 0;
				}
				else
				{
					printf("No hay censista liberado con ese ID");
				}
			}

		}
		else
		{
			printf("No hay zonas pendientes con ese ID");
		}
	}


	return retorno;
}

int cargarDatos(eZona array[], int len, int idZona, eCensista censistas[], int lenCensistas)
{
	int retorno = -1;
	int index;
	int auxInSitu;
	int auxVirtual;
	int auxAusentes;
	int flag;

	flag = 0;

	if(array != NULL && len > 0 && censistas != NULL && lenCensistas > 0)
	{
		index = buscarZonaPendientePorId(array, len, idZona);

		if(index != -1)
		{
			if(getInt(&auxInSitu, "Ingrese la cantidad de censados In Situ: ",
						"ERROR. Ingreso un numero invalido (150 censados max)\n\n", 150, 0, 3)==0)
			{
				array[index].inSitu = auxInSitu;
				flag = 1;
			}
			if(flag == 1)
			{
				flag = 0;
				if(getInt(&auxVirtual, "Ingrese la cantidad de censados con formulario virtual: ",
							"ERROR. Ingreso un numero invalido (150 censados max)\n\n", 150, 0, 3)==0)
				{
					array[index].virtual = auxVirtual;
					flag = 1;
				}
			}
			if(flag == 1)
			{
				if(getInt(&auxAusentes, "Ingrese la cantidad de censados ausentes: ",
							"ERROR. Ingreso un numero invalido (150 censados max)\n\n", 150, 0, 3)==0)
				{
					array[index].ausentes = auxAusentes;
					array[index].estado = FINALIZADO;
					for(int i = 0; i < lenCensistas; i++)
					{
						if(array[index].idCensista == censistas[i].idCensista)
						{
							censistas[i].estado = LIBERADO;
							retorno = 0;
							printf("\nSe han cargado los datos correctamente");
							break;
						}
					}
				}
			}
		}
		else
		{
			printf("No hay zonas pendientes con ese ID");
		}
	}

	return retorno;
}

///// @brief --> Esta funcion busca un pasajero por el id
/////
///// @param --> list Puntero al espacio de memoria donde se buscara el pasajero
///// @param --> len Define el tamanio de la cadena
///// @param --> id recibe el id del pasajero a buscar
///// @return --> Esta funcion retorna el index del pasajero encontrado
int buscarZonaPendientePorId(eZona array[], int len, int idZona)
{
	int retorno = -1;
	if (array != NULL && len > 0 && idZona > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (array[i].idZona == idZona && array[i].isEmpty == OCUPADO && array[i].estado == PENDIENTE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @brief --> Esta funcion busca un pasajero por el id
///
/// @param --> list Puntero al espacio de memoria donde se buscara el pasajero
/// @param --> len Define el tamanio de la cadena
/// @param --> id recibe el id del pasajero a buscar
/// @return --> Esta funcion retorna el index del pasajero encontrado
//int buscarZonaPendientePorId(eZona array[], int len, int idZona, eCensista arrayDos[])
//{
//	int retorno = -1;
//	if (array != NULL && len > 0 && idZona > 0)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			if (array[i].idZona == idZona && array[i].isEmpty == OCUPADO && array[i].estado == PENDIENTE)
//			{
//				for(int j = 0; j < len; j++)
//				{
//					if(array[i].idCensista == arrayDos[j].idCensista && arrayDos[j].estado == ACTIVO)
//					{
//						printf("Esta zona ya fue asignada a un censista responsable");
//						retorno = -1;
//						break;
//					}
//					if(array[i].idCensista != arrayDos[j].idCensista && arrayDos[j].estado == LIBERADO)
//					{
//						retorno = i;
//						break;
//					}
//				}
//			}
//		}
//	}
//	return retorno;
//}


/// @brief --> Esta funcion muestra un censista
///
/// @param --> unPassenger Puntero al espacio de memoria donde se buscara el censista a mostrar
/// @return --> Esta funcion no retorna nada
int mostrarZonasCompleto(eZona array[], int len, eCensista censistas[], int lenCensistas)
{
	int retorno = -1;
	int flag;

	flag = 0;

	char localidades[6][51] = {"", "Hudson   ", "Ranelagh ", "Platanos ", "Sourigues", "Gutierrez"};

	if(array != NULL && len > 0 && censistas != NULL && lenCensistas > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				printf("\n+---------------------------------------------------------------------------------------------------------------------"
						"-----------------------------------------------------+");
				printf("\nID Zona: %d | Calle 1: %d | Calle 2: %d | Calle 3: %d | Calle 4: %d | Localidad: %s | "
						"In Situ: %d | Virtual: %d | Ausentes: %d |"
						 ,array[i].idZona, array[i].calle[0], array[i].calle[1], array[i].calle[2], array[i].calle[3],
						 localidades[array[i].localidad], array[i].inSitu, array[i].virtual, array[i].ausentes);

				for(int j = 0; j < lenCensistas; j++)
				{
					if(array[i].idCensista == censistas[j].idCensista && (censistas[j].estado == ACTIVO || array[i].estado == FINALIZADO))
					{
						printf(" Censista: %s, %s ", censistas[j].apellido, censistas[j].nombre);
						flag = 1;
						break;
					}
					else
					{
						flag = 0;
					}
				}
				if(flag == 0)
				{
					printf(" Censista: No asignado ");
				}
			}
		}



		printf("\n+---------------------------------------------------------------------------------------------------------------------"
						"-----------------------------------------------------+");
		retorno = 0;
	}
	return retorno;
}

///// @brief --> Esta funcion muestra un censista
/////
///// @param --> unPassenger Puntero al espacio de memoria donde se buscara el censista a mostrar
///// @return --> Esta funcion no retorna nada
//void mostrarZonaPendientes(eZona unaZona)
//{
//	char localidades[6][51] = {"", "Hudson", "Ranelagh", "Platanos", "Sourigues", "Gutierrez"};
//
//	if(unaZona.isEmpty == 0 && unaZona.estado == PENDIENTE)
//	{
//		printf("\n+-----------------------------------------------------------------------------------------------+");
//		printf("\nID Zona: %d | Calle 1: %d | Calle 2: %d | Calle 3: %d | Calle 4: %d | Localidad: %s", unaZona.idZona,
//				unaZona.calle[0], unaZona.calle[1], unaZona.calle[2], unaZona.calle[3], localidades[unaZona.localidad]);
//	}
//}

/// @brief --> Esta funcion muestra un censista
///
/// @param --> unPassenger Puntero al espacio de memoria donde se buscara el censista a mostrar
/// @return --> Esta funcion no retorna nada
int mostrarZonasPendientes(eZona array[], int len)
{
	int retorno = -1;

	char localidades[6][51] = {"", "Hudson", "Ranelagh", "Platanos", "Sourigues", "Gutierrez"};

	if(array != NULL && len >0)
	{

		for(int i = 0; i < len; i++)
		{
			if(array[i].isEmpty == 0 && array[i].estado == PENDIENTE)
			{
				printf("\n+-----------------------------------------------------------------------------------------------+");
				printf("\nID Zona: %d | Calle 1: %d | Calle 2: %d | Calle 3: %d | Calle 4: %d | Localidad: %s", array[i].idZona,
						array[i].calle[0], array[i].calle[1], array[i].calle[2], array[i].calle[3], localidades[array[i].localidad]);
			}
		}
		printf("\n+-----------------------------------------------------------------------------------------------+\n");
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion busca en un array si hay datos cargados
///
/// @param --> array Puntero al espacio de memoria donde se buscara si hay algo cargado
/// @param --> len Define el tamaño de cadena
/// @return --> Esta funcion retorna un 1 si se encontro algo cargado, y un 0 si no fue asi
int hayZonaPendiente(eZona array[], int len)
{
	int retorno = 0;
	if (array != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO && array[i].estado == PENDIENTE)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/// @brief --> Esta funcion busca en un array si hay datos cargados
///
/// @param --> array Puntero al espacio de memoria donde se buscara si hay algo cargado
/// @param --> len Define el tamaño de cadena
/// @return --> Esta funcion retorna un 1 si se encontro algo cargado, y un 0 si no fue asi
int hayZonaCargada(eZona array[], int len)
{
	int retorno = 0;
	if (array != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/// @brief --> Esta funcion hardcodea los datos del array
///
/// @param --> list Puntero al espacio de memoria donde se cargaran los censistas
/// @return --> Esta funcion retorna 0 si se cargo correctamente o -1 si no fue asi
int cargaForzadaZonas(eZona array[], int len)
{
	int retorno = -1;
	int i;

	eZona lista[8] = {{5000, {136,137,365,366}, 2, 0, 0, 0, PENDIENTE, 0, OCUPADO},
							{5001, {210,211,490,491}, 1, 0, 0, 0, PENDIENTE, 0, OCUPADO},
							{5002, {290,291,565,566}, 3, 0, 0, 0, PENDIENTE, 0, OCUPADO},
							{5003, {410,411,324,325}, 4, 0, 0, 0, PENDIENTE, 0, OCUPADO},
							{5004, {761,762,100,101}, 5, 0, 0, 0, PENDIENTE, 0, OCUPADO},
							{5005, {542,543,111,112}, 1, 0, 0, 0, PENDIENTE, 0, OCUPADO},
							{5006, {701,702,211,212}, 2, 0, 0, 0, PENDIENTE, 0, OCUPADO},
							{5007, {292,293,575,576}, 3, 0, 0, 0, PENDIENTE, 0, OCUPADO}};


	if(array != NULL && len > 0)
	{
		for(i = 0; i < 8; i++)
		{
			array[i] = lista[i];
			retorno = 0;
		}
	}

	return retorno;
}


