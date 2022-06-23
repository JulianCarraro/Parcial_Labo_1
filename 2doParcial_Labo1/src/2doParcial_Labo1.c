#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "bibliotecaUtn.h"

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);

	int option = 0;
	char respuesta;
	int flag;
	int flagCargaArchivo;
	int flagSave;
	int cantidad;
	int criterio;

	LinkedList *lista = ll_newLinkedList();
	LinkedList *listaPrimeraClase = ll_newLinkedList();
	LinkedList *listaConMillas = ll_newLinkedList();
	respuesta = 'n';
	flag = 0;
	flagCargaArchivo = 0;
	flagSave = 0;
	cantidad = 0;

	do
	{
		if(menuPrincipal(&option)==0)
		{
			if(option == 1 || option == 2 || option == 3 || option == 10 || flag == 1)
			{
				switch(option)
				{
					case 1:
						if(flagCargaArchivo == 0)
						{
							if(controller_loadFromText("data.csv", lista)==0)
							{
								printf("\nSe han cargado los pasajeros correctamente (modo texto)\n");
								flag = 1;
								flagCargaArchivo = 1;
								if(flagSave == 1)
								{
									flagSave = 0;
								}
							}
							else
							{
								printf("\nERROR al cargar el archivo (modo texto)\n");
							}
						}
						else
						{
							printf("\nYa has cargado los pasajeros\n");
						}
						break;
					case 2:
						if(flagCargaArchivo == 0)
						{
							if(controller_loadFromBinary("data.bin", lista)==0)
							{
								printf("\nSe han cargado los pasajeros correctamente (modo binario)\n");
								flag = 1;
								flagCargaArchivo = 1;
								if(flagSave == 1)
								{
									flagSave = 0;
								}
							}
							else
							{
								printf("\nERROR al cargar el archivo (modo binario)\n");
							}
						}
						else
						{
							printf("\nYa has cargado los pasajeros\n");
						}
						break;
					case 3:
						if(controller_addPassenger(lista)==0)
						{
							printf("\nSe ha añadido correctamente el pasajero\n");
							flag = 1;
							if(flagSave == 1)
							{
								flagSave = 0;
							}
						}
						break;
					case 4:
						if(controller_editPassenger(lista)==0)
						{
							printf("\nSe han guardado los cambios correctamente\n");
							if(flagSave == 1)
							{
								flagSave = 0;
							}
						}
						break;
					case 5:
						if(controller_removePassenger(lista)==0)
						{
							printf("\nSe ha dado de baja el pasajero\n");
							if(flagSave == 1)
							{
								flagSave = 0;
							}
						}
						break;
					case 6:
						if(controller_ListPassenger(lista)==-1)
						{
							printf("\nNo hay pasajeros para mostrar\n");
							if(flagSave == 1)
							{
								flagSave = 0;
							}
						}
						break;
					case 7:
						if(controller_sortPassenger(lista)==0)
						{
							printf("\nLISTAR los pasajeros para ver los cambios realizados\n");
							if(flagSave == 1)
							{
								flagSave = 0;
							}
						}
						break;
					case 8:
						if(flagCargaArchivo == 1)
						{
							if(controller_saveAsText("data.csv", lista)==0)
							{
								printf("\nSe guardaron los datos de los pasajeros correctamente (modo texto)\n");
								flagSave = 1;
							}
							else
							{
								printf("\nERROR al guardar el archivo (modo texto)\n");
							}
						}
						else
						{
							printf("\nDebe cargar los datos de los pasajeros para poder guardar (opcion 1)\n");
						}
						break;
					case 9:
						if(flagCargaArchivo == 1)
						{
							if(controller_saveAsBinary("data.bin", lista)==0)
							{
								printf("\nSe guardaron los datos de los pasajeros correctamente (modo binario)\n");
								flagSave = 1;
							}
							else
							{
								printf("\nERROR al guardar el archivo (modo binario)\n");
							}
						}
						else
						{
							printf("\nDebe cargar los datos de los pasajeros para poder guardar (opcion 1)\n");
						}
						break;
					case 10:
						if(flag == 0 || flagSave == 1)
						{
							getChars(&respuesta, sizeof(respuesta), "¿Desea salir del programa? s(si) o n(no): ",
									"Ingreso un caracter invalido\n", 3);
							if(respuesta == 's')
							{
								ll_deleteLinkedList(lista);
							}
						}
						else
						{
							printf("\nDebe guardar los datos para poder salir\n");
						}
						break;
					case 11:
						if(getInt(&criterio, "\nQue tipo de pasajero desea contar?\n1.FirstClass\n2.ExecutiveClass\n3. EconomyClass\nElija una opcion: ",
								"Ingreso una opcion incorrecta", 3, 1, 5)==0)
						{
							switch(criterio)
							{
								case 1:
									cantidad = ll_count(lista, contadorPrimeraClase);
									printf("\nLa cantidad de pasajeros de primera clase es: %d\n", cantidad);
									break;
								case 2:
									cantidad = ll_count(lista, contadorClaseEjecutiva);
									printf("\nLa cantidad de pasajeros de clase ejecutiva es: %d\n", cantidad);
									break;
								case 3:
									cantidad = ll_count(lista, contadorClaseEconomica);
									printf("\nLa cantidad de pasajeros de clase economica es: %d\n", cantidad);
									break;
							}
						}
						break;
					case 12:
						if(ll_isEmpty(lista)==0)
						{
							listaPrimeraClase = ll_filter(lista, primeraClase);
							if(controller_saveAsPassengersFirstClass("PPrimeraClase.csv", listaPrimeraClase)==0)
							{
								printf("\nSe han cargado correctamente los pasajeros de primera clase\n");
							}
						}
						else
						{
							printf("\nNo hay pasajeros cargados\n");
						}
						break;
					case 13:
						if(ll_isEmpty(lista)==0)
						{
							listaConMillas = ll_map(lista, calcular);
							controller_ListPassengerWithMillas(listaConMillas);
						}
						else
						{
							printf("\nNo hay pasajeros cargados para filtrar\n");
						}
						break;
				}
			}
			else
			{
				printf("\nPrimero debe cargar algun pasajero para avanzar\n");
			}

		}
	}while(respuesta != 's');

	printf("\n¡¡HASTA LUEGO!!\n");

	return 0;
}
