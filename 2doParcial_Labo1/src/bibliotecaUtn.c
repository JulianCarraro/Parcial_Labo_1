/*
 * bibliotecaUtn.c
 *
 *  Created on: 21 abr. 2022
 *      Author: carra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaUtn.h"


/// @brief --> Esta funcion pide y valida numeros enteros
///
/// @param --> pNumeroIngresado Este parametro retorna el numero ingresado por puntero
/// @param --> mensaje El mensaje cuando el usuario ingresa datos validos
/// @param --> mensajeError El mensaje erroneo, en caso de que ingrese datos no validos
/// @param --> maximo Indica el numero minimo que se puede ingresar
/// @param --> minimo Indica el numero maximo que se puede ingresar
/// @param --> maximoDeReintentos Indica el maximo de reintentos de validacion
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos) {

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo
			&& maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if(getNumero(&auxNumeroIngresado) == 1 && auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo)
			{
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				maximoDeReintentos--;
				retorno = -1;
			}
		} while (maximoDeReintentos > 0);
	}

	return retorno;
}

/// @brief --> Esta funcion pide y valida numeros enteros
///
/// @param --> pNumeroIngresado Este parametro retorna el numero ingresado por puntero
/// @param --> mensaje El mensaje cuando el usuario ingresa datos validos
/// @param --> mensajeError El mensaje erroneo, en caso de que ingrese datos no validos
/// @param --> maximo Indica el numero minimo que se puede ingresar
/// @param --> minimo Indica el numero maximo que se puede ingresar
/// @param --> maximoDeReintentos Indica el maximo de reintentos de validacion
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int getIntInText(char *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos) {

	char auxNumeroIngresado[128];
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo
			&& maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if(myGets(auxNumeroIngresado, sizeof(auxNumeroIngresado))==0 && validarNumero(auxNumeroIngresado)==1
					&& validarRangoDeNumero(auxNumeroIngresado, minimo, maximo)==0)
			{
				strncpy(pNumeroIngresado, auxNumeroIngresado, sizeof(&pNumeroIngresado));
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				maximoDeReintentos--;
				retorno = -1;
			}
		} while (maximoDeReintentos > 0);
	}

	return retorno;
}

int validarRangoDeNumero(char * numeroIngresado, int minimo, int maximo)
{
	int retorno = -1;
	int numeroAVericar;

	numeroAVericar = atoi(numeroIngresado);

	if(numeroIngresado != NULL && numeroAVericar >= minimo && numeroAVericar <= maximo)
	{
		retorno = 0;
	}

	return retorno;
}

/// @brief --> Esta funcion pide y valida numeros enteros
///
/// @param --> pNumeroIngresado Este parametro retorna el numero ingresado por puntero
/// @param --> mensaje El mensaje cuando el usuario ingresa datos validos
/// @param --> mensajeError El mensaje erroneo, en caso de que ingrese datos no validos
/// @param --> maximo Indica el numero minimo que se puede ingresar
/// @param --> minimo Indica el numero maximo que se puede ingresar
/// @param --> maximoDeReintentos Indica el maximo de reintentos de validacion
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int getFloatInText(char *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos) {

	char auxNumeroIngresado[10];
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo
			&& maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if(myGets(auxNumeroIngresado, sizeof(auxNumeroIngresado))==0 && validarNumeroFlotante(auxNumeroIngresado)==1
					&& validarRangoDeNumero(auxNumeroIngresado, minimo, maximo)==0)
			{
				strncpy(pNumeroIngresado, auxNumeroIngresado, sizeof(&pNumeroIngresado));
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				maximoDeReintentos--;
				retorno = -1;
			}
		} while (maximoDeReintentos > 0);
	}

	return retorno;
}

/// @brief --> Esta funcion pide y valida numeros flotantes
///
/// @param --> pNumeroIngresado Este parametro retorna el numero ingresado por puntero
/// @param --> mensaje El mensaje cuando el usuario ingresa datos validos
/// @param --> mensajeError El mensaje erroneo, en caso de que ingrese datos no validos
/// @param --> maximo Indica el numero minimo que se puede ingresar
/// @param --> minimo Indica el numero maximo que se puede ingresar
/// @param --> maximoDeReintentos Indica el maximo de reintentos de validacion
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int getFloat(float *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos) {

	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo
			&& maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if(getNumeroFlotante(&auxNumeroIngresado) == 1 && auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo)
			{
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			}
			else {
				printf("%s", mensajeError);
				maximoDeReintentos--;
				retorno = -1;
			}
		} while (maximoDeReintentos > 0);
	}

	return retorno;
}

/// @brief --> Esta funcion pide y valida caracteres
///
/// @param --> array Este parametro retorna el caracter ingresado por puntero
/// @param --> mensaje El mensaje cuando el usuario ingresa datos validos
/// @param --> mensajeError El mensaje erroneo, en caso de que ingrese datos no validos
/// @param --> maximoDeReintentos Indica el maximo de reintentos de validacion
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int getChars(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos) {

	char auxChar[52];
	int retorno;
	retorno = -1;

	if (array != NULL && mensaje != NULL && mensajeError != NULL &&
			len > 0 && maximoReintentos >= 0) {
			do
			{
				printf("%s", mensaje);
				fflush(stdin);
				if(myGets(auxChar,sizeof(auxChar))==0)
				{
					if(validarLetras(auxChar)==1)
					{
						strncpy(array, auxChar, len);
						retorno = 0;
						break;
					}
					else
					{
						printf("%s", mensajeError);
						retorno = -1;
						maximoReintentos--;
					}
				}
				else
				{
					maximoReintentos--;
				}

			}while(maximoReintentos > 0);

		}


	return retorno;
}

/// @brief --> Esta funcion valida si la cadena ingresada es numerica
///
/// @param --> cadena Cadena de caracteres a ser analizada
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int validarNumero(char * cadena)
{
	int retorno;
	int i;

	i = 0;
	retorno = 1;

	if(cadena != NULL)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		for( ; cadena[i] != '\0'; i++)
		{
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}


	return retorno;
}

/// @brief --> Esta funcion valida si la cadena ingresada es numerica
///
/// @param --> pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return --> Esta funcion retorna un 1 si se ingresaron datos validos, y un 0 si no son validos
int getNumero(int * pResultado)
{
	int retorno;
	char auxNumero[256];
	retorno = 0;

	fflush(stdin);
	if(pResultado != NULL)
	{
		if(myGets(auxNumero,sizeof(auxNumero))==0 && validarNumero(auxNumero)==1)
		{
			retorno = 1;
			*pResultado = atoi(auxNumero);
		}
	}

	return retorno;
}


/// @brief --> Esta funcion valida si la cadena ingresada es numerica flotante
///
/// @param --> pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return --> Esta funcion retorna un 1 si se ingresaron datos validos, y un 0 si no son validos
int getNumeroFlotante(float * pResultado)
{
	int retorno;
	char auxNumero[256];
	retorno = 0;

	fflush(stdin);
	if(pResultado != NULL)
	{
		if(myGets(auxNumero,sizeof(auxNumero))==0 && validarNumeroFlotante(auxNumero)==1)
		{
			retorno = 1;
			*pResultado = atof(auxNumero);
		}
	}

	return retorno;
}

/// @brief --> Esta funcion valida si la cadena ingresada es numerica flotante
///
/// @param --> cadena Cadena de caracteres a ser analizada
/// @return --> Esta funcion retorna un 1 si se ingresaron datos validos, y un 0 si no son validos
int validarNumeroFlotante(char * cadena)
{
	int retorno;
	int i;
	int contador;

	i = 0;
	retorno = 1;
	contador = 0;

	if(cadena != NULL)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		for( ; cadena[i] != '\0'; i++)
		{
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				if(cadena[i] == '.' && contador == 0)
				{
					contador++;

				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}


	return retorno;
}

/// @brief --> Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena * un máximo de 'longitud - 1' caracteres
///
/// @param --> cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
/// @param --> len Define el tamaño de cadena
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un 1 si no son validos
int myGets(char* cadena, int len)
{
	int retorno;

	retorno = 1;

	if(cadena != NULL && len > 0 && fgets(cadena,len,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
			retorno = 0;
		}
		else
		{
			printf("ERROR. Te pasaste de los caracteres\n\n");
		}
	}

	return retorno;
}

/// @brief --> Esta funcion pide y muestra el menu principal
///
/// @param --> opcionMenu Puntero al espacio de memoria donde se copiara la opcion del menu obtenida
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int menuPrincipal(int * opcionMenu)
{
	int auxOpcion;
	int retorno = -1;

	printf("\n*******************MENU PRINCIPAL*******************\n\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto) \n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario) \n");
	printf("3. Alta de pasajero \n");
	printf("4. Modificar datos de pasajero \n");
	printf("5. Baja de pasajero \n");
	printf("6. Listar pasajeros \n");
	printf("7. Ordenar pasajeros \n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto) \n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario) \n");
	printf("10. SALIR \n");

	if(getInt(&auxOpcion, "Ingrese una opcion: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			10, 1, 5)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
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

	printf("\n******************MODIFICACIONES******************\n\n");
	printf("1. NOMBRE \n");
	printf("2. APELLIDO \n");
	printf("3. PRECIO \n");
	printf("4. CODIGO DE VUELO \n");
	printf("5. TIPO DE PASAJERO \n");
	printf("6. ESTADO DE VUELO \n");
	printf("7. SALIR \n");

	if(getInt(&auxOpcion, "Que desea modificar?: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			7, 1, 5)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
	}


	return retorno;

}

/// @brief --> Esta funcion pide y muestra el menu de ordenar
///
/// @param --> opcionMenu Puntero al espacio de memoria donde se copiara la opcion del menu obtenida
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int menuOrdenamiento(int * opcionMenu)
{
	int auxOpcion;
	int retorno = -1;

	printf("\n******************MENU DE ORDENAMIENTO******************\n\n");
	printf("1. ORDENAR POR ID \n");
	printf("2. ORDENAR POR NOMBRE \n");
	printf("3. ORDENAR POR APELLIDO \n");
	printf("4. ORDENAR POR PRECIO \n");
	printf("5. ORDENAR POR CODIGO DE VUELO \n");
	printf("6. ORDENAR POR TIPO DE PASAJERO \n");
	printf("7. ORDENAR POR ESTADO DE VUELO \n");
	printf("8. SALIR \n");

	if(getInt(&auxOpcion, "De que forma desea ordenar?: ", "ERROR. Ingresaste una opcion incorrecta.\n\n",
			8, 1, 3)==0)
	{
		*opcionMenu = auxOpcion;
		retorno = 0;
	}


	return retorno;

}

/// @brief --> Esta funcion valida si la cadena ingresada tiene solo letras
///
/// @param --> cadena Cadena de caracteres a ser analizada
/// @return --> Esta funcion retorna un 1 si se ingresaron datos validos, y un 0 si no son validos
int validarLetras(char cadena[])
{
	int retorno=0;
	int len = strlen(cadena);

	if(cadena!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(cadena[0] == ' ')
			{
				break;
			}
			if((cadena[i]>='A' && cadena[i]<='Z') || (cadena[i]>='a' && cadena[i]<='z') || cadena[i]==' ')
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @brief --> Esta funcion valida si la cadena ingresada tiene solo letras
///
/// @param --> flyCode Cadena de caracteres a ser analizada
/// @return --> Esta funcion retorna un 1 si se ingresaron datos validos, y un 0 si no son validos
int validarFlyCode(char flyCode[])
{
	int retorno = -1;
	int len = strlen(flyCode);

	if(flyCode!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if((flyCode[i]>='A' && flyCode[i]<='Z') || (flyCode[i]>='a' && flyCode[i]<='z') || (flyCode[i] <= '9' && flyCode[i] >= '0'))
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}


	return retorno;
}

/// @brief --> Esta funcion pide y valida numeros y caracteres
///
/// @param --> array Este parametro retorna el caracter y/o numero ingresado por puntero
/// @param --> mensaje El mensaje cuando el usuario ingresa datos validos
/// @param --> mensajeError El mensaje erroneo, en caso de que ingrese datos no validos
/// @param --> maximoDeReintentos Indica el maximo de reintentos de validacion
/// @return --> Esta funcion retorna un 0 si se ingresaron datos validos, y un -1 si no son validos
int getCodeChar(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos) {

	char auxChar[12];
	int retorno;
	int i;

	retorno = -1;

	if (array != NULL && mensaje != NULL && mensajeError != NULL &&
			len > 0 && maximoReintentos >= 0) {
			do
			{
				printf("%s", mensaje);
				fflush(stdin);
				if(myGets(auxChar,sizeof(auxChar))==0)
				{
					if(validarFlyCode(auxChar)==1)
					{
						for(i = 0; auxChar[i] != '\0'; i++)
						{
							auxChar[i] = toupper(auxChar[i]);
						}
						strncpy(array, auxChar, len);
						retorno = 0;
						break;
					}
					else
					{
						printf("%s", mensajeError);
						retorno = -1;
						maximoReintentos--;
					}
				}
				else
				{
					maximoReintentos--;
				}

			}while(maximoReintentos > 0);

		}


	return retorno;
}



