/*
 * censista.c
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

#define LEN_CENSISTAS 15
#define OCUPADO 0
#define VACIO 1
#define LIBERADO 1
#define ACTIVO 2
#define INACTIVO 3


/// @brief --> Esta funcion va autoincrementando el id
///
/// @return --> Esta funcion retorna el id
int incrementarId()
{
    static int id = 1000;
    id++;
    return id;
}

/// @brief --> Esta funcion inicializa el array de censistas
///
/// @param --> lista Puntero al espacio de memoria donde se inicializara los datos
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int inicializarCensistas(eCensista * lista, int len)
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

/// @brief --> Esta funcion pide y carga los censistas
///
/// @param --> array Puntero al espacio de memoria donde se guardaran los datos
/// @param --> len Define el tamanio de la cadena
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int cargarCensista(eCensista array[], int len) {
	int retorno = -1;
	int indexLibre;
	char auxNombre[51];
	char auxApellido[51];
	int auxAnioNacimiento;
	int auxMesNacimiento;
	int auxDiaNacimiento;
	int auxEdad;
	int auxCalle;
	int auxNumeroCasa;
	int flag;

	flag = 0;

	if (array != NULL && len > 0) {
		indexLibre = buscarIndexPorIsEmpty(array, len);
		if (indexLibre != -1) {
			if(getChars(auxNombre, sizeof(auxNombre), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
					3)==0)
			{
				strncpy(array[indexLibre].nombre, auxNombre, sizeof(array[indexLibre].nombre));
				flag = 1;
			}
			if(flag == 1)
			{
				flag = 0;
				if(getChars(auxApellido, sizeof(auxApellido), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
						3)==0)
				{
					strncpy(array[indexLibre].apellido, auxApellido, sizeof(array[indexLibre].apellido));
					flag = 1;
				}
			}
			if(flag == 1)
			{
				flag = 0;
				if(getInt(&auxAnioNacimiento, "Ingrese el anio de nacimiento (Mayor de 18 anios): ", "ERROR. Ingreso un anio invalido\n\n",
						2004, 1970, 3)==0)
				{
					array[indexLibre].fecha.anioNacimiento = auxAnioNacimiento;
					flag = 1;
				}
			}
			if(flag == 1)
			{
				flag = 0;
				if(getInt(&auxMesNacimiento, "Ingrese el mes de nacimiento: ", "ERROR. Ingreso un mes invalido\n\n",
						12, 1, 3)==0)
				{
					array[indexLibre].fecha.mesNacimiento = auxMesNacimiento;
					flag = 1;
				}
			}
			if(flag == 1)
			{
				flag = 0;
				if(getInt(&auxDiaNacimiento, "Ingrese el dia de nacimiento: ", "ERROR. Ingreso un dia invalido\n\n",
						31, 1, 3)==0)
				{
					array[indexLibre].fecha.diaNacimiento = auxDiaNacimiento;
					flag = 1;
				}
			}

			auxEdad = edadCensista(array[indexLibre].fecha.anioNacimiento, array[indexLibre].fecha.mesNacimiento);
			if(auxEdad > 17)
			{
				array[indexLibre].edad = auxEdad;
			}
			else
			{
				printf("\nEl censista es menor de 18 anios\n");
				flag = 0;
			}

			if(flag == 1)
			{
				flag = 0;
				if(getInt(&auxCalle, "Ingrese la calle del domicilio: ", "ERROR. Ingreso una calle invalida\n\n",
						999, 1, 3)==0)
				{
					array[indexLibre].direccion.calle = auxCalle;
					flag = 1;
				}
			}
			if(flag == 1)
			{
				if(getInt(&auxNumeroCasa, "Ingrese el numero de casa del domicilio: ", "ERROR. Ingreso un numero de casa invalido\n\n",
						9999, 100, 3)==0)
				{
					array[indexLibre].direccion.numeroDeCasa = auxNumeroCasa;
					array[indexLibre].idCensista = incrementarId();
					array[indexLibre].estado = LIBERADO;
					array[indexLibre].isEmpty = OCUPADO;
					printTitle();
					mostrarCensista(array[indexLibre]);
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/// @brief --> Esta funcion calcula la edad del censista
///
/// @param --> anioNacimiento Recibe el anio de nacimiento
/// @param --> mesNacimiento Recibe el mes de nacimiento
/// @return --> Esta funcion retorna la edad del censista
int edadCensista(int anioNacimiento, int mesNacimiento)
{
	int anioActual = 2022;
	int edad;

	edad = anioActual - anioNacimiento;

	if(mesNacimiento > 5)
	{
		edad--;
	}

	return edad;
}

/// @brief --> Esta funcion busca un espacio libre en el array
///
/// @param --> array Puntero al espacio de memoria donde se buscara el lugar libre
/// @param --> len Define el tamanio de la cadena
/// @return --> Esta funcion retorna un index libre
int buscarIndexPorIsEmpty(eCensista array[], int len)
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

/// @brief --> Esta funcion permite modificar los datos de un censista
///
/// @param --> list Puntero al espacio de memoria donde se modificaran los datos
/// @param --> len Define el tamanio de la cadena
/// @param --> idCensista recibe el id del censista a modificar
/// @return --> Esta funcion retorna 0 si se modifico correctamente, o -1 si no fue asi
int modificarCensista(eCensista array[], int len, int idCensista)
{
	int retorno = -1;
	int index;
	int opcionMenu;
	int opcionFecha;
	int opcionDireccion;
	char auxNombre[51];
	char auxApellido[51];
	int auxAnioNacimiento;
	int auxMesNacimiento;
	int auxDiaNacimiento;
	int auxEdad;
	int auxCalle;
	int auxNumeroCasa;
	int flag;

	flag = 0;

	if (array != NULL && len > 0 && idCensista > 0)
	{
		index = buscarCensistaPorId(array, len, idCensista);

    	if (index != -1)
    	{
			do
			{
				printTitle();
				mostrarCensista(array[index]);
				if(menuModificaciones(&opcionMenu)==0)
				{
					switch(opcionMenu)
					{
						case 1:
							if(getChars(auxNombre, sizeof(auxNombre), "Ingrese un nombre: ", "ERROR. Ingreso un nombre invalido\n\n",
									3)==0)
							{
								strncpy(array[index].nombre, auxNombre, sizeof(array[index].nombre));
							}
							break;
						case 2:
							if(getChars(auxApellido, sizeof(auxApellido), "Ingrese un apellido: ", "ERROR. Ingreso un apellido invalido\n\n",
									3)==0)
							{
								strncpy(array[index].apellido, auxApellido, sizeof(array[index].apellido));
							}
							break;
						case 3:
							flag = 0;
							do
							{
								if(subMenuFechaNacimiento(&opcionFecha)==0)
								{
									switch(opcionFecha)
									{
										case 1:
											if(getInt(&auxAnioNacimiento, "Ingrese el anio de nacimiento (Mayor de 18 anios): ", "ERROR. Ingreso un anio invalido\n\n",
													2004, 1970, 3)==0)
											{
												array[index].fecha.anioNacimiento = auxAnioNacimiento;
											}
											break;
										case 2:
											if(getInt(&auxMesNacimiento, "Ingrese el mes de nacimiento: ", "ERROR. Ingreso un mes invalido\n\n",
													12, 1, 3)==0)
											{
												array[index].fecha.mesNacimiento = auxMesNacimiento;
											}
											break;
										case 3:
											if(getInt(&auxDiaNacimiento, "Ingrese el dia de nacimiento: ", "ERROR. Ingreso un dia invalido\n\n",
													31, 1, 3)==0)
											{
												array[index].fecha.diaNacimiento = auxDiaNacimiento;
											}
											break;
										case 4:
											auxEdad = edadCensista(array[index].fecha.anioNacimiento, array[index].fecha.mesNacimiento);
											if(auxEdad > 17)
											{
												array[index].edad = auxEdad;
												flag = 1;
											}
											else
											{
												flag = 0;
												printf("\nEl censista es menor de 18 anios, no puede continuar hasta modificarlo\n");
											}
											break;
									}
								}

							}while(flag != 1);
							break;
						case 4:
							do
							{
								if(subMenuDireccion(&opcionDireccion)==0)
								{
									switch(opcionDireccion)
									{
										case 1:
											if(getInt(&auxCalle, "Ingrese la calle del domicilio: ", "ERROR. Ingreso una calle invalida\n\n",
													999, 1, 3)==0)
											{
												array[index].direccion.calle = auxCalle;
											}
											break;
										case 2:
											if(getInt(&auxNumeroCasa, "Ingrese el numero de casa del domicilio: ", "ERROR. Ingreso un numero de casa invalido\n\n",
													9999, 100, 3)==0)
											{
												array[index].direccion.numeroDeCasa = auxNumeroCasa;
											}
											break;
										case 3:
											break;
									}
								}

							}while(opcionDireccion != 3);
							break;
						case 5:
							retorno = 0;
							printf("\nSe han guardado los cambios\n");
							break;
					}
				}

			}while(opcionMenu != 5);
	    }
    	else
    	{
    		printf("No hay asociado con ese ID\n");
    	}
	}
	return retorno;
}


/// @brief --> Esta funcion muestra un censista
///
/// @param --> unCensista Recibe los datos del censista a mostrar
/// @return --> Esta funcion no retorna nada
void mostrarCensista(eCensista unCensista)
{
	if(unCensista.isEmpty == OCUPADO)
	{
		printf("|%*d|%*s|%*s|%*d/%*d/%*d|%*d|%*d|%*d|\n", -15, unCensista.idCensista, -15, unCensista.nombre, -15,
				unCensista.apellido, 2, unCensista.fecha.diaNacimiento, 2,
				unCensista.fecha.mesNacimiento, -14, unCensista.fecha.anioNacimiento, -15, unCensista.edad, -17, unCensista.direccion.calle, -15, unCensista.direccion.numeroDeCasa);

	}
}

/// @brief --> Esta funcion muestra el titulo
///
/// @return --> Esta funcion no retorna nada
void printTitle()
{


	printf("+----------------------------------------------------------------------------------------------------------------------+");
	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n", -15,"ID DEL CENSISTA", -15, "NOMBRE", -15, "APELLIDO", -20, "FECHA DE NACIMIENTO", -15, "EDAD", -15, "DOMICILIO (CALLE)", -15, "ALTURA");
	printf("+---------------+---------------+---------------+--------------------+---------------+---------------------------------+\n");
}

/// @brief --> Esta funcion muestra todos los pasajeros cargados
///
/// @param --> array Puntero al espacio de memoria donde se buscaran los censistas a mostrar
/// @param --> len Define el tamanio de la cadena
/// @return --> Esta funcion retorna 0 si se verifico correctamente o -1 si no fue asi
int mostrarCensistas(eCensista array[], int len)
{
	int retorno = -1;

	if(array != NULL && len >0)
	{
		printTitle();
		for(int i = 0; i < LEN_CENSISTAS; i++)
		{
			mostrarCensista(array[i]);
		}
		printf("+----------------------------------------------------------------------------------------------------------------------+\n");
		retorno = 0;
	}
	return retorno;
}

/// @brief --> Esta funcion busca un censista por el id
///
/// @param --> list Puntero al espacio de memoria donde se buscara el censista
/// @param --> len Define el tamanio de la cadena
/// @param --> id recibe el id del censista a buscar
/// @return --> Esta funcion retorna el index del censista encontrado
int buscarCensistaPorId(eCensista array[], int len, int idCensista)
{
	int retorno = -1;
	if (array != NULL && len > 0 && idCensista > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(array[i].idCensista == idCensista && array[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @brief --> Esta funcion da de baja un censista
///
/// @param --> array Puntero al espacio de memoria donde se buscan los datos a borrar
/// @param --> len Define el tamanio de la cadena
/// @param --> idCensista Recibe el id del censista a borrar
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int bajaCensista(eCensista array[], int len, int idCensista) {
	int retorno = -1;
	int index;

	if (array != NULL && len > 0 && idCensista > 0) {

		index = buscarCensistaPorId(array, len, idCensista);

		if (index != -1)
		{
			printf("\nSe ha dado de baja el censista: \n");
			printTitle();
			mostrarCensista(array[index]);
			if(array[index].estado == ACTIVO)
			{
				array[index].estado = INACTIVO;
				retorno = 0;
			}
			else
			{
				if(array[index].estado == LIBERADO)
				{
					array[index].isEmpty = VACIO;
					retorno = 0;
				}
			}
		}
    	else
    	{
    		printf("No hay censista con ese ID\n");
    	}
	}

	return retorno;
}

/// @brief --> Esta funcion busca en un array si hay algun censista cargados
///
/// @param --> array Puntero al espacio de memoria donde se buscara si hay algo cargado
/// @param --> len Define el tamaño de cadena
/// @return --> Esta funcion retorna un 1 si se encontro algo cargado, y un 0 si no fue asi
int hayAlgoCargado(eCensista array[], int len)
{
	int retorno = 0;
	if (array != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (array[i].isEmpty == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/// @brief --> Esta funcion busca un censista liberado por el id
///
/// @param --> list Puntero al espacio de memoria donde se buscara el censista
/// @param --> len Define el tamanio de la cadena
/// @param --> id recibe el id del censista a buscar
/// @return --> Esta funcion retorna el index del censista liberado encontrado
int buscarCensistaLiberadoPorId(eCensista array[], int len, int idCensista)
{
	int retorno = -1;
	if (array != NULL && len > 0 && idCensista > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(array[i].idCensista == idCensista && array[i].estado == LIBERADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @brief --> Esta funcion busca en un array si hay algun censista liberado cargados
///
/// @param --> array Puntero al espacio de memoria donde se buscara si hay algo cargado
/// @param --> len Define el tamaño de cadena
/// @return --> Esta funcion retorna un 1 si se encontro algo cargado, y un 0 si no fue asi
int hayCensistaLibreCargado(eCensista array[], int len)
{
	int retorno = 0;
	if (array != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(array[i].isEmpty == OCUPADO && array[i].estado == LIBERADO)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

//int existeCensistaLiberadoPorId(eCensista pArray[], int len, int idCensista)
//{
//	int retorno = -1;
//
//		if(pArray != NULL && len > 0)
//		{
//			for(int i = 0; i < len; i++)
//			{
//				if(pArray[i].estado == LIBERADO && pArray[i].idCensista == idCensista)
//				{
//					retorno = 0;
//					break;
//				}
//			}
//		}
//	return retorno;
//}

/// @brief --> Esta funcion muestra un censista liberado
///
/// @param --> unCensista Recibe los datos del censista liberado a mostrar
/// @return --> Esta funcion no retorna nada
void mostrarCensistaLiberado(eCensista unCensista)
{
	if(unCensista.isEmpty == OCUPADO && unCensista.estado == LIBERADO)
	{
		printf("|%*d|%*s|%*s|%*d/%*d/%*d|%*d|%*d|%*d|\n", -15, unCensista.idCensista, -15, unCensista.nombre, -15,
				unCensista.apellido, 2, unCensista.fecha.diaNacimiento, 2,
				unCensista.fecha.mesNacimiento, -14, unCensista.fecha.anioNacimiento, -15, unCensista.edad, -17, unCensista.direccion.calle, -15, unCensista.direccion.numeroDeCasa);

	}
}

/// @brief --> Esta funcion muestra todos los censistas liberados cargados
///
/// @param --> array Puntero al espacio de memoria donde se buscaran los censistas liberados a mostrar
/// @param --> len Define el tamanio de la cadena
/// @return --> Esta funcion retorna 0 si se verifico correctamente o -1 si no fue asi
int mostrarCensistasLiberados(eCensista array[], int len)
{
	int retorno = -1;

	if(array != NULL && len >0)
	{
		printTitle();
		for(int i = 0; i < LEN_CENSISTAS; i++)
		{
			mostrarCensistaLiberado(array[i]);
		}
		printf("+----------------------------------------------------------------------------------------------------------------------+\n");
		retorno = 0;
	}
	return retorno;
}

/// @brief --> Esta funcion hardcodea los datos del array
///
/// @param --> list Puntero al espacio de memoria donde se cargaran los censistas
/// @return --> Esta funcion retorna 0 si se cargo correctamente o -1 si no fue asi
int cargaForzadaCensistas(eCensista array[], int len)
{
	int retorno = -1;
	int i;

	eCensista lista[8] = {{2000, "Julian", "Alvarez", {2000,1,31}, 22, {365, 1334}, LIBERADO, OCUPADO},
							{2001, "Marcelo", "Gallardo", {1976,1,18}, 46, {400, 4011}, LIBERADO, OCUPADO},
							{2002, "Gonzalo", "Montiel", {1997,1,1}, 25, {789, 7990}, LIBERADO, OCUPADO},
							{2003, "Rafael", "Borre", {1995,9,15}, 26, {121, 1295}, LIBERADO, OCUPADO},
							{2004, "Lucas", "Pratto", {1988,6,4}, 33, {210, 1075}, LIBERADO, OCUPADO},
							{2005, "Enzo", "Perez", {1986,2,22}, 36, {910, 9320}, LIBERADO, OCUPADO},
							{2006, "Milton", "Casco", {1988,4,11}, 34, {755, 7511}, LIBERADO, OCUPADO},
							{2007, "Lionel", "Messi", {1987,6,24}, 34, {820, 8295}, LIBERADO, OCUPADO}};


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

/// @brief --> Esta funcion pide y muestra el menu de modificaciones
///
/// @param --> opcionMenu Puntero al espacio de memoria donde se copiara la opcion del menu obtenida
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int menuModificaciones(int * opcionMenu)
{
	int auxOpcion;
	int retorno = -1;

	printf("\n************MODIFICACIONES************\n\n");
	printf("1. NOMBRE \n");
	printf("2. APELLIDO \n");
	printf("3. FECHA DE NACIMIENTO \n");
	printf("4. DIRECCION \n");
	printf("5. SALIR \n");

	if(getInt(&auxOpcion, "Que desea modificar?: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			5, 1, 5)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
	}


	return retorno;

}

/// @brief --> Esta funcion pide y muestra el submenu de la fecha de nacimiento
///
/// @param --> opcionMenu Puntero al espacio de memoria donde se copiara la opcion del menu obtenida
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int subMenuFechaNacimiento(int * opcionMenu)
{
	int auxOpcion;
	int retorno = -1;

	printf("\n1. ANIO DE NACIMIENTO \n");
	printf("2. MES DE NACIMIENTO \n");
	printf("3. DIA DE NACIMIENTO \n");
	printf("4. SALIR \n");


	if(getInt(&auxOpcion, "Que desea modificar?: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			4, 1, 3)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
	}


	return retorno;
}

/// @brief --> Esta funcion pide y muestra el submenu de la fecha de nacimiento
///
/// @param --> opcionMenu Puntero al espacio de memoria donde se copiara la opcion del menu obtenida
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int subMenuDireccion(int * opcionMenu)
{
	int auxOpcion;
	int retorno = -1;

//	printf("\nFECHA DE NACIMIENTO\n\n");
	printf("1. CALLE \n");
	printf("2. NUMERO DE CASA \n");
	printf("3. SALIR \n");

	if(getInt(&auxOpcion, "Que desea modificar?: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			3, 1, 3)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
	}


	return retorno;
}

