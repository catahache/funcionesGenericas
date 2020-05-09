/*
 * menusABM.c
 *
 *  Created on: May 9, 2020
 *      Author: catalina
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menusABM.h"
#include "estructGenerica.h"
#include "estructTipo.h"
#include "utn.h"

//MODIFICAR LAS SIGUIENTES FUNCIONES CON LAS ESTRUCTURAS NECESARIAS. CUANTAS MAS ESTRUCTURAS Y TIPOS CREE, MAS PARAMETROS LES PASO!!!


//MAIN:

int menu()
{
	int opcion;

	system("clear");
	printf("***** MENU *****\n\n");
	printf("1. ALTAS\n");
	printf("2. BAJAS\n");
	printf("3. MODIFICACIONES\n");
	printf("4. SALIR\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 4);

	return opcion;

}

//ALTAS:

int menuAltas()
{
	int opcion;

	system("clear");
	printf("***** Altas *****\n");
	printf("1. Generico\n");
	printf("2. \n");
	printf("3. \n");
	printf("4. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 4);

	return opcion;

}

//esta es la funcion que llamo en main:
void alta(int* nextIdG, int* flagG, eGenerica listaG[], int tamG,  eTipoG listaT[], int tamT)
{
	//pasar next id de todos los que sean necesarios desde main
	//pasar vector y tamanio necesarios
	//pasar todas las flags necesarias desde main
	//pasar tipos necesarios

	char continueS = 's';
	char confirm;

	int idG = *nextIdG;

	if(nextIdG != NULL && flagG != NULL && listaG != NULL)
	{
		do
		{
			switch(menuAltas())
			{
				case 1:
					if(altaGenerico(idG, listaG, tamG, listaT, tamT)  == 1)
					{
						*nextIdG = idG++;
						*flagG = 1;
					}
					break;
				case 2:
					//cargar alta de otra cosa
					break;
				case 3:
					//cargar alta de otra cosa
					break;
				case 4:
					system("clear");
					printf("\n***** Salir *****\n\n ");
					printf("Confirma salida? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueS = 'n';
					}
					break;
				default:
					printf("No es una opcion valida.\n");

			}
		}while(continueS == 's');
	}
}

//BAJAS:

int menuBajas()
{
	int opcion;

	system("clear");
	printf("***** Bajas *****\n");
	printf("1. Generico\n");
	printf("2. \n");
	printf("3. \n");
	printf("4. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 4);

	return opcion;

}

//esta es la funcion que llamo en main para dar de baja:
void baja(int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT)
{
	//pasar vector y tamanio necesarios
	//pasar ids necesarios
	//pasar flags necesarias
	char continueS = 's';
	char confirm;
	int idG;


	if(listaG != NULL) //agregar las listas que sean
	{
		do
		{
			switch(menuBajas())
			{
				case 1:
					utn_getEntero(&idG, 3, "Ingrese el id del generico a eliminar: ", "Error,id no valido.\n", 1000, 1050);
					if(bajaGenerico(idG, flagG, listaG, tamG, listaT, tamT)  == 1)
					{
						printf("Se ha eliminado el generico con exito.\n\n");
					}
					break;
				case 2:
					//cargar baja de otra cosa
					break;
				case 3:
					//cargar baja de otra cosa
					break;
				case 4:
					system("clear");
					printf("\n***** Salir *****\n\n ");
					printf("Confirma salida? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueS = 'n';
					}
					break;
				default:
					printf("No es una opcion valida.\n");

			}
		}while(continueS == 's');

	}//if null
}



//MODIFICACIONES:
int menuModif()
{
	int opcion;

	system("clear");
	printf("***** Modificaciones *****\n");
	printf("1. Generico\n");
	printf("2. \n");
	printf("3. \n");
	printf("4. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 4);

	return opcion;

}

//esta es la funcion que llamo en main para modificar:
void modificacion(int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT)
{
	//pasar vector y tamanio necesarios
	//pasar ids necesarios
	//pasar flags necesarias
	char continueS = 's';
	char confirm;


	if(listaG != NULL) //agregar las listas que sean
	{
		do
		{
			switch(menuModif())
			{
				case 1:
					modificacionGenerica(flagG, listaG, tamG, listaT, tamT);
					break;
				case 2:
					//cargar modificacion de otra estructura
					break;
				case 3:
					//cargar modificacion de otra estructura
					break;
				case 4:
					system("clear");
					printf("\n***** Salir *****\n\n ");
					printf("Confirma salida? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueS = 'n';
					}
					break;
				default:
					printf("No es una opcion valida.\n");

			}
		}while(continueS == 's');
	}
}









//Hacer un alta por cada estructura
int altaGenerico(int idX, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibre(listaG, tamG);

	if(listaG != NULL && listaT != NULL && tamG > 0 && tamT > 0)
	{
		system("clear");
		printf("***** Alta Generico *****\n");
		if(indice < 0)
		{
			printf("Sistema completo.\n");
		}
		else
		{
			if(utn_getCadena(listaG[indice].nombre, 30, 3, "\nIngrese nombre: ", "El nombre ingresado es invalido.\n") == 0
				&& utn_getCadena(listaG[indice].apellido, 30, 3, "Ingrese apellido: ", "El apellido ingresado es invalido.\n") == 0
				&& utn_getEntero(&listaG[indice].edad, 3, "Ingrese edad de 18 a 100: ", "Error.", 18, 100) == 0)
			{
				mostrarTipos(listaT, tamT); //muestra los tipos

				if(utn_getEntero(&listaG[indice].idTipo, 3, "Ingrese tipo: ", "El tipo ingresado no es valido.\n", 1, 3) == 0)
				{
					listaG[indice].id = idX;
					listaG[indice].isEmpty = 0; //lleno el lugar
					todoOk = 1; //exito
				}
			}
		}//if indice
	}//if NULL
	return todoOk;
}

//Hacer una baja por cada estructura
int bajaGenerico(int idG, int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT)
{
	int isOk = 0;
	char eliminarG;
	int indiceG;

	if(flagG == 1)
	{
		indiceG = buscarGenericoPorId(idG, listaG, tamG); //busca con el ID que conseguimos en la funcion baja y devuelve el indice donde esta o -1
		if(indiceG > -1)
		{
			mostrarGenerico(listaG[indiceG], listaT, tamT); //muestra el elemento generico a eliminar
			printf("Eliminar? s/n: ");
			scanf("%c", &eliminarG);
			if(eliminarG == 's')
			{
				listaG[indiceG].isEmpty = 1; //eliminar
				isOk = 1;
			}
			else
			{
				printf("No se han realizado cambios.\n");
			}
		}
		else
		{
			printf("No existe generico con ese id.\n");
		}
	}
	else
	{
		printf("No hay genericos cargados\n");
	}
	return isOk;
}


//Hacer una modificacion por cada estructura
int modificacionGenerica(int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT)
{
	int isOk = -1;
	int auxId;
	int opcion;
	char confirmar;
	char continuarG;
	int indice;

	char nuevoNombre[30];
	char nuevoApellido[30];
	int nuevaEdad;
	int nuevoTipo;

	system("clear");
	printf("***** Modificar *****\n\n");

	if(flagG == 1)
	{
		if(listaG != NULL && tamG > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID del genero a modificar: ", "Error. No es un ID.\n", 1000, 2000) == 0 )
		{
			indice = buscarGenericoPorId(auxId, listaG, tamG);//encuentra al generico a modificar

			if(indice == -1)
			{
				printf("No existe ese ID en el sistema.\n");
			}
			else
			{
				printf("El ID %d pertenece al siguiente generico:\n", auxId);
				printf("ID    Nombre    Apellido    Edad     Tipo\n\n");
				mostrarGenerico(listaG[indice], listaT, tamT);
				printf("Desea modificarlo? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirmar);

				if(confirmar == 's')
				{
					do
					{
						system("clear");
						//OJO agregar o sacar las opciones (capos de la estruct) necesarias:
						printf("    1. Modificar nombre\n");
						printf("    2. Modificar apellido\n");
						printf("    3. Modificar edad\n");
						printf("    4. Modificar tipo\n");
						if(utn_getEntero(&opcion, 3, "Ingrese opcion a modificar: ", "Error, no es una opcion valida", 1, 4) == 0)
						{
							switch(opcion) //copio los nuevos valores al generico
							{
								case 1:
									if(utn_getCadena(nuevoNombre, 30, 3, "Ingrese nuevo nombre: ", "Error, invalido.\n") == 0)
									{
										strcpy(listaG[indice].nombre, nuevoNombre);
										isOk= 0;
									}
									break;
								case 2:
									if(utn_getCadena(nuevoApellido, 30, 3, "Ingrese nuevo apellido: ", "Error, invalido.\n") == 0)
									{
										strcpy(listaG[indice].apellido, nuevoApellido);
										isOk= 0;
									}
									break;
								case 3:
									if(utn_getEntero(&nuevaEdad, 3, "Ingrese nueva edad: ", "Error, invalida.\n", 18, 100) == 0)
									{
										listaG[indice].edad = nuevaEdad;
										isOk= 0;
									}
									break;
								case 4:
									printf("Tipos disponibles:\n");
									mostrarTipos(listaT, tamT);
									if(utn_getEntero(&nuevoTipo, 3, "Ingrese id de nuevo tipo: ", "Error, invalido.\n", 1, 4) == 0)
									{
										listaG[indice].idTipo = nuevoTipo;
										isOk= 0;
									}
									break;
								default:
									printf("No es una opcion valida.\n\n");
							}
							if(isOk == 0)
							{
								printf("Se han modificado los datos correctamente. \n");
								printf("ID    Nombre    Apellido    Edad     Tipo\n\n");
								mostrarGenerico(listaG[indice], listaT, tamT);//muestro el generico con los datos modificados
							}
							printf("Desea seguir modificando? s/n: ");
							fpurge(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
								continuarG = 'n';
							}
						}//if opcion a modificar == 0
					}while(continuarG == 's');
				}//if confirma
				else if(confirmar == 'n')
				{
					printf("No se han registrado modificaciones.\n");
				}
			}//else
		}//if NULL
	}//if flagM == 1
	else
	{
		printf("No hay musicos que modificar.\n");

	}

	return isOk;
}

