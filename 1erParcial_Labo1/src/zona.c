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

/// @brief --> Esta funcion va autoincrementando el id de la zona
///
/// @return --> Esta funcion retorna el id
int incrementarIdZona()
{
    static int id = 4000;
    id++;
    return id;
}

/// @brief --> Esta funcion inicializa el array de zonas
///
/// @param --> lista Puntero al espacio de memoria donde se inicializara los datos
/// @param --> len Define el tamanio de la cadena
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

/// @brief --> Esta funcion pide y carga las zonas
///
/// @param --> array Puntero al espacio de memoria donde se guardaran los datos
/// @param --> len Define el tamanio de la cadena
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
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
					"ERROR. Ingreso una opcion incorrecta\n\n", 5, 1, 3)==0)
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

/// @brief --> Esta funcion muestra las localidades
///
/// @return --> Esta funcion no retorna nada
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
/// @param --> array Puntero al espacio de memoria donde se buscara el lugar libre
/// @param --> len Define el tamanio de la cadena
/// @return --> Esta funcion retorna el index libre
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

/// @brief --> Esta funcion pide y modifica las zonas
///
/// @param --> array Puntero al espacio de memoria donde se guardaran los datos
/// @param --> len Define el tamanio de la cadena
/// @param --> idZona Recibe el id de la zona a modificar
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int modificarZona(eZona array[], int len, int idZona)
{
	int retorno = -1;
	int index;
	int opcionMenu;
	int auxId;
	int auxCalleUno;
	int auxCalleDos;
	int auxCalleTres;
	int auxCalleCuatro;
	int auxLocalidad;

	if (array != NULL && len > 0 && idZona > 0)
	{
		if(hayZonaCargada(array, len))
		{
			mostrarZonas(array, len);
			if(getInt(&auxId, "Ingrese el id de la zona que desea modificar: ",
					"Error, el id no es valido\n\n", 6000,
					4000, 3)==0)
			{
				idZona = auxId;
			}

			index = buscarZonaPorId(array, len, idZona);

			if(index != -1)
			{
				do
				{
					mostrarZona(array[index]);
					if(menuModificacionesZonas(&opcionMenu)==0)
					{
						switch(opcionMenu)
						{
							case 1:
								if(getInt(&auxCalleUno, "Ingrese la calle 1: ",
										"Error, la calle no es valida\n\n", 999,
										1, 3)==0)
								{
									array[index].calle[0] = auxCalleUno;
								}
								break;
							case 2:
								if(getInt(&auxCalleDos, "Ingrese la calle 2: ",
										"Error, la calle no es valida\n\n", 999,
										1, 3)==0)
								{
									array[index].calle[1] = auxCalleDos;
								}
								break;
							case 3:
								if(getInt(&auxCalleTres, "Ingrese la calle 3: ",
										"Error, la calle no es valida\n\n", 999,
										1, 3)==0)
								{
									array[index].calle[2] = auxCalleTres;
								}
								break;
							case 4:
								if(getInt(&auxCalleCuatro, "Ingrese la calle 4: ",
										"Error, la calle no es valida\n\n", 999,
										1, 3)==0)
								{
									array[index].calle[3] = auxCalleCuatro;
								}
								break;
							case 5:
								if(getInt(&auxLocalidad, "Ingrese la localidad: ",
										"Error, la localidad no es valida\n\n", 5,
										1, 3)==0)
								{
									array[index].localidad = auxLocalidad;
								}
								break;
							case 6:
								retorno = 0;
								printf("\nSe han guardado los cambios\n");
								break;
						}
					}

				}while(opcionMenu != 6);


			}
			else
			{
				printf("No hay zona con ese ID\n");
			}
		}
	}

	return retorno;
}

/// @brief --> Esta funcion da de baja la Zona
///
/// @param --> array Puntero al espacio de memoria donde se buscan los datos a borrar
/// @param --> len Define el tamanio de la cadena
/// @param --> idZona Recibe el id de la zona a borrar
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int bajaZona(eZona array[], int len, int idZona)
{
	int retorno = -1;
	int index;
	int auxId;

	if (array != NULL && len > 0 && idZona > 0)
	{
		if(hayZonaPendiente(array, len))
		{
			mostrarZonasPendientes(array, len);
			if(getInt(&auxId, "Ingrese el id de la zona que desea dar de baja (debe estar pendiente): ",
					"Error, el id no es valido\n\n", 6000,
					4000, 3)==0)
			{
				idZona = auxId;
			}

			index = buscarZonaPendientePorId(array, len, idZona);

			if(index != -1)
			{
				printf("\nSe ha dado de baja el censista: \n");
				array[index].isEmpty = VACIO;
				retorno = 0;
			}
	    	else
	    	{
	    		printf("No hay censista con ese ID\n");
	    	}
		}
    	else
    	{
    		printf("No hay ninguna zona pendiente para dar de baja\n");
    	}
	}

	return retorno;
}

/// @brief --> Esta funcion muestra una zona
///
/// @param --> unaZona Recibe los datos de la zona a mostrar
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

/// @brief --> Esta funcion muestra las zonas
///
/// @param --> array Puntero al espacio de memoria donde se buscaran las zonas a mostrar
/// @return --> Esta funcion retorna 0 si funciono correctamente, o un -1 si no fue asi
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

/// @brief --> Esta funcion asigna una zona a un censista
///
/// @param --> array Puntero al espacio de memoria donde se buscan los datos de la zona
/// @param --> len Define el tamanio de la cadena del array de Zonas
/// @param --> idZona Recibe el id de la Zona a asignar
/// @param --> arrayCensistas Puntero al espacio de memoria donde se buscan los datos del censista
/// @param --> lenCensistas Define el tamanio de la cadena del array de censistas
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
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

/// @brief --> Esta funcion carga los datos de la zona al sistema
///
/// @param --> array Puntero al espacio de memoria donde se buscan los datos de la zona
/// @param --> len Define el tamanio de la cadena del array de Zonas
/// @param --> idZona Recibe el id de la Zona a cargar
/// @param --> arrayCensistas Puntero al espacio de memoria donde se buscan los datos del censista
/// @param --> lenCensistas Define el tamanio de la cadena del array de censistas
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
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

///// @brief --> Esta funcion busca una Zona Pendiente por el id
/////
///// @param --> array Puntero al espacio de memoria donde se buscara la Zona
///// @param --> len Define el tamanio de la cadena
///// @param --> id recibe el id de la zona a buscar
///// @return --> Esta funcion retorna el index de la zona encontrada
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

///// @brief --> Esta funcion busca una Zona por el id
/////
///// @param --> array Puntero al espacio de memoria donde se buscara la Zona
///// @param --> len Define el tamanio de la cadena
///// @param --> id recibe el id de la zona a buscar
///// @return --> Esta funcion retorna el index de la zona encontrada
int buscarZonaPorId(eZona array[], int len, int idZona)
{
	int retorno = -1;
	if (array != NULL && len > 0 && idZona > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (array[i].idZona == idZona && array[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

///// @brief --> Esta funcion muestra las zonas con todos sus datos
/////
///// @param --> array Puntero al espacio de memoria donde se buscara la Zona
///// @param --> len Define el tamanio de la cadena
///// @param --> censistas Puntero al espacio de memoria donde se buscara el censista
///// @param --> lenCensistas Define el tamanio de la cadena de censistas
///// @return --> Esta funcion retorna 0 si se valido correctamente o -1 si no fue asi
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

/// @brief --> Esta funcion muestra las zonas pendientes
///
///// @param --> array Puntero al espacio de memoria donde se buscara las zonas pendientes
///// @param --> len Define el tamanio de la cadena
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

/// @brief --> Esta funcion busca en un array si hay zonas pendientes cargadas
///
/// @param --> array Puntero al espacio de memoria donde se buscara si hay alguna zona pendiente cargada
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

/// @brief --> Esta funcion busca en un array si hay una zona cargada
///
/// @param --> array Puntero al espacio de memoria donde se buscara si hay una zona cargada
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
/// @param --> list Puntero al espacio de memoria donde se cargaran las zonas
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
		}
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion pide y muestra el menu de modificaciones de las zonas
///
/// @param --> opcionMenu Puntero al espacio de memoria donde se copiara la opcion del menu obtenida
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int menuModificacionesZonas(int * opcionMenu)
{
	int auxOpcion;
	int retorno = -1;

	printf("\n************MODIFICACIONES************\n\n");
	printf("1. CALLE 1 \n");
	printf("2. CALLE 2 \n");
	printf("3. CALLE 3 \n");
	printf("4. CALLE 4 \n");
	printf("5. LOCALIDAD \n");
	printf("6. SALIR \n");

	if(getInt(&auxOpcion, "Que desea modificar?: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			6, 1, 5)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
	}


	return retorno;

}

///// @brief --> Esta funcion muestra las zonas pendientes
/////
/////// @param --> array Puntero al espacio de memoria donde se buscara las zonas pendientes
/////// @param --> len Define el tamanio de la cadena
///// @return --> Esta funcion no retorna nada
//int mostrarZonasPendientesNoAsignadas(eZona array[], int len, eCensista arrayCensistas[], int lenCensistas)
//{
//	int retorno = -1;
//
//	char localidades[6][51] = {"", "Hudson", "Ranelagh", "Platanos", "Sourigues", "Gutierrez"};
//
//	if(array != NULL && len >0)
//	{
//
//		for(int i = 0; i < len; i++)
//		{
//			if(array[i].isEmpty == OCUPADO && array[i].estado == PENDIENTE)
//			{
//				for(int j = 0; j < lenCensistas; j++)
//				{
//					if(array[i].idCensista == arrayCensistas[j].idCensista &&
//							(arrayCensistas[j].estado == LIBERADO || arrayCensistas[j].estado == INACTIVO))
//					printf("\n+-----------------------------------------------------------------------------------------------+");
//					printf("\nID Zona: %d | Calle 1: %d | Calle 2: %d | Calle 3: %d | Calle 4: %d | Localidad: %s", array[i].idZona,
//							array[i].calle[0], array[i].calle[1], array[i].calle[2], array[i].calle[3], localidades[array[i].localidad]);
//					break;
//				}
//			}
//		}
//		printf("\n+-----------------------------------------------------------------------------------------------+\n");
//		retorno = 0;
//	}
//
//	return retorno;
//}

