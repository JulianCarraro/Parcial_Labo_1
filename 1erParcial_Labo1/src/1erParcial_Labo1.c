/*
 ============================================================================
 Name        : Parcial2022
 Author      : Julian Carraro
 Version     : 1E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "censista.h"
#include "zona.h"

#define LEN_CENSISTAS 15
#define LEN_ZONAS 15

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	eCensista censista[LEN_CENSISTAS];
	eZona zona[LEN_ZONAS];
	int auxId = 1000;
	int auxIdZona = 1000;
	int idCensista;
	int idZona;

	inicializarCensistas(censista, LEN_CENSISTAS);
	inicializarZonas(zona, LEN_ZONAS);

	do
	{
		if(menuPrincipal(&opcionMenu)==0)
		{
			switch(opcionMenu)
			{
				case 1:
					printf("\nCARGAR CENSISTA\n\n");
					cargarCensista(censista, LEN_CENSISTAS);
					break;
				case 2:
					if(hayAlgoCargado(censista, LEN_CENSISTAS)==1)
					{
						printf("\nMODIFICAR CENSISTA\n\n");
						mostrarCensistas(censista, LEN_CENSISTAS);
						if(getInt(&auxId, "Ingrese el id del censista que desea modificar: ",
								"Error, el id no es valido\n\n", 3000,
								1000, 3)==0)
						{
							idCensista = auxId;
						}
						modificarCensista(censista, LEN_CENSISTAS, idCensista);
					}
					else
					{
						printf("\nNo hay ningun censista cargado para modificar");
					}
					break;
				case 3:
					if(hayAlgoCargado(censista, LEN_CENSISTAS)==1)
					{
						printf("\nDAR DE BAJA CENSISTA\n\n");
						mostrarCensistas(censista, LEN_CENSISTAS);
						if(getInt(&auxId, "Ingrese el id del censista que desea dar de baja: ",
								"Error, el id no es valido\n\n", 3000,
								1000, 3)==0)
						{
							idCensista = auxId;
						}
						bajaCensista(censista, LEN_CENSISTAS, idCensista);
					}
					else
					{
						printf("\nNo hay ningun censista cargado para dar de baja");
					}
					break;
				case 4:
					printf("\nCARGAR ZONA\n\n");
					cargarZonas(zona, LEN_ZONAS);
					break;
				case 5:
					if(hayCensistaLibreCargado(censista, LEN_CENSISTAS)==1)
					{
						if(hayZonaPendiente(zona, LEN_ZONAS) == 1)
						{
							printf("\nASIGNAR ZONA A CENSAR\n");
							mostrarZonasPendientesNoAsignadas(zona, LEN_ZONAS, censista, LEN_CENSISTAS);
							if(getInt(&auxIdZona, "Ingrese el ID de la zona que desea censar: ",
										"ERROR. Ingreso una id incorrecto\n\n", 6000, 4000, 3)==0)
							{
								idZona = auxIdZona;
							}
							asignarZona(zona, LEN_ZONAS, idZona, censista, LEN_CENSISTAS);
						}
						else
						{
							printf("\nNo hay zonas pendientes para asignar");
						}
					}
					else
					{
						printf("\nNo hay censistas liberados para asignar");
					}
					break;
				case 6:
					if(hayZonaPendiente(zona, LEN_ZONAS) == 1)
					{
						mostrarZonasPendientes(zona, LEN_ZONAS);
						if(getInt(&auxIdZona, "Ingrese el ID de la zona que desea cargar los datos: ",
									"ERROR. Ingreso un id incorrecto\n\n", 6000, 4000, 3)==0)
						{
							idZona = auxIdZona;
						}
						cargarDatos(zona, LEN_ZONAS, idZona, censista, LEN_CENSISTAS);
					}
					else
					{
						printf("\nNo hay zonas pendientes para cargar los datos");
					}
					break;
				case 7:
					if(hayAlgoCargado(censista, LEN_CENSISTAS)==1)
					{
						mostrarCensistas(censista, LEN_CENSISTAS);
					}
					else
					{
						printf("\nNo hay censistas cargados para mostrar");
					}
					break;
				case 8:
					if(hayZonaCargada(zona, LEN_ZONAS))
					{
						mostrarZonasCompleto(zona, LEN_ZONAS, censista, LEN_CENSISTAS);
					}
					else
					{
						printf("\nNo hay zonas cargadas para mostrar");
					}
					break;
				case 9:
					cargaForzadaCensistas(censista, LEN_CENSISTAS);
					break;
				case 10:
					cargaForzadaZonas(zona, LEN_ZONAS);
					break;
				case 11:
					break;
			}

		}

	}while(opcionMenu != 11);

	return EXIT_SUCCESS;
}
