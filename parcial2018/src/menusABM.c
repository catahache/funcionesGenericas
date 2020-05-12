/*
 * menusABM.c
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menusABM.h"
#include "utn.h"

//MAIN:

int menu()
{
	int opcion;

	system("clear");
	printf("***** MENU *****\n\n");
	printf("1. ALTAS\n");
	printf("2. BAJAS\n");
	printf("3. MODIFICACIONES\n");
	printf("4. LISTAS\n");
	printf("5. INFORMES	\n");
	printf("6. SALIR\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 6);

	return opcion;

}

//ALTAS:

int menuAltas()
{
	int opcion;

	system("clear");
	printf("***** Altas *****\n");
	printf("1. CLiente\n");
	printf("2. Nuevo Aviso\n");
	printf("3. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 3);

	return opcion;

}

//esta es la funcion que llamo en main:
void alta(int* nextIdC, int* nextIdA, int* flagC, int* flagA, eCliente listaC[], int tamC,  eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	//pasar next id de todos los que sean necesarios desde main
	//pasar vector y tamanio necesarios
	//pasar todas las flags necesarias desde main
	//pasar tipos necesarios

	char continueS = 's';
	char confirm;

	int idC = *nextIdC;
	int idA = *nextIdA;

	if(nextIdC != NULL && flagC != NULL && listaC != NULL && nextIdA != NULL && flagA != NULL && listaA != NULL)
	{
		do
		{
			switch(menuAltas())
			{
				case 1:
					if(altaC(idC, listaC, tamC)  == 1)
					{
						*nextIdC = idC++;
						*flagC = 1;
					}
					break;
				case 2:
					if(altaA(idA, listaA, tamA, rubros, tamR, listaC, tamC, flagC))
					{
						*nextIdA = idA++;
						*flagA = 1;
					}
					break;
				case 3:
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
int altaC(int idX, eCliente listaC[], int tamC)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibreC(listaC, tamC);

	if(listaC != NULL  && tamC > 0)
	{
		system("clear");
		printf("***** Alta Cliente *****\n");
		if(indice < 0)
		{
			printf("Sistema completo.\n");
		}
		else
		{
			if(utn_getCadena(listaC[indice].nombre, 30, 3, "\nIngrese nombre: ", "El nombre ingresado es invalido.\n") == 0
				&& utn_getCadena(listaC[indice].apellido, 30, 3, "Ingrese apellido: ", "El apellido ingresado es invalido.\n") == 0
				&& utn_getEntero(&listaC[indice].cuit, 3, "Ingrese cuit de 6 digitos: ", "Error.", 100000, 999999) == 0)
			{

				listaC[indice].id = idX;
				listaC[indice].isEmpty = 0; //lleno el lugar
				todoOk = 1; //exito
			}
		}//if indice
	}//if NULL
	return todoOk;
}

int altaA(int idX, eAviso listaA[], int tamA, eRubro rubros[], int tamR, eCliente listaC[], int tamC, int* flagC)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibreA(listaA, tamA);

	if(listaA != NULL && rubros != NULL && tamA > 0 && tamR > 0)
	{
		if(*flagC == 1)
		{
			system("clear");
			printf("***** Nueva Publicacion *****\n");
			if(indice < 0)
			{
				printf("Sistema completo.\n");
			}
			else
			{
				mostrarCs(listaC, tamC, listaA, tamA);
				if(utn_getEntero(&listaA[indice].idCliente , 3, "\nIngrese id del cliente que publica: ", "El id ingresado es invalido.\n", 1000, 2000) == 0
					&& utn_getEntero(&listaA[indice].rubro, 3, "Ingrese rubro: ", "El rubro ingresado es invalido.\n", 1, 4) == 0)
				{
					printf("Ingrese el texto del aviso: ");
					fpurge(stdin);
					fgets(listaA[indice].texto, sizeof(listaA[indice].texto), stdin);

					listaA[indice].id = idX;
					listaA[indice].isEmpty = 0; //lleno el lugar
					todoOk = 1; //exito
					mostrarA(listaA[indice], rubros, tamR);

				}
			}//if indice
		}
		else
		{
			printf("No hay clientes cargados.\n");
		}

	}//if NULL
	return todoOk;
}


//----------------------------------------------------------------------------------------------------------------------
//BAJAS:


//esta es la funcion que llamo en main para dar de baja:
void baja(int flagC, eCliente listaC[], int tamC, eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	char continueS = 's';
	char confirm;
	int idC;


	if(listaC != NULL && listaA != NULL && tamC > 0 && tamA > 0) //agregar las listas que sean
	{
		if(flagC == 1)
		{
			do
			{
				mostrarCs(listaC, tamC, listaA, tamA);
				utn_getEntero(&idC, 3, "Ingrese el id del cliente a eliminar: ", "Error.\n", 1000, 2000);

				if(bajaC(idC, flagC, listaC, tamC, listaA, tamA, rubros, tamR) == 1)
				{
					printf("Se ha eliminado el cliente con exito.\n\n");
				}
				printf("Continuar eliminando? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					continueS = 'n';
				}

			}while(continueS == 's');
		}
		else
		{
			printf("No hay clientes cargados\n");
		}


	}//if null
}

//Hacer una baja por cada estructura
int bajaC(int idC, int flagC, eCliente listaC[], int tamC, eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	int isOk = 0;
	char eliminarG;
	int indiceC;


	indiceC = buscarCPorId(idC, listaC, tamC); //busca con el ID que conseguimos en la funcion baja y devuelve el indice donde esta o -1
	if(indiceC > -1)
	{
		mostrarC(listaC[indiceC], listaA, tamA);
		printf("Avisos del cliente: \n");
		mostrarAvisosPorCliente(idC, listaA, tamA, rubros, tamR);
		printf("Eliminar? s/n: ");
		scanf("%c", &eliminarG);
		if(eliminarG == 's')
		{
			listaC[indiceC].isEmpty = 1; //eliminar
			eliminarAvisosPorCliente(idC, listaA, tamA);
			isOk = 1;
		}
		else
		{
			printf("No se han realizado cambios.\n");
		}
	}
	else
	{
		printf("No existe cliente con ese id.\n");
	}


	return isOk;
}

//----------------------------------------------------------------------------------------------------------------------
//MODIFICACION:

int menuModif()
{
	int opcion;

	system("clear");
	printf("***** Modificaciones *****\n");
	printf("1. Clientes\n");
	printf("2. Pausar publicacion\n");
	printf("3. Reanudar publicacion\n");
	printf("4. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 4);

	return opcion;

}

//esta es la funcion que llamo en main para modificar:
void modificacion(int flagC, int flagA, eCliente listaC[], int tamC, eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	//pasar vector y tamanio necesarios
	//pasar ids necesarios
	//pasar flags necesarias
	char continueS = 's';
	char confirm;


	if(listaC != NULL && listaA != NULL) //agregar las listas que sean
	{
		do
		{
			switch(menuModif())
			{
				case 1:
					if(flagC == 1)
					{
						modificacionCliente(flagC, listaC, tamC, listaA, tamA);
					}
					else
					{
						printf("Error. No hay clientes cargados.\n");
					}
					break;
				case 2:
					if(flagC == 1)
					{
						pausaPublicacion(flagA, listaA, tamA, rubros, tamR);
					}
					else
					{
						printf("Error. No hay publicaciones cargadas.\n");
					}
					//cargar modificacion de otra estructura validada con otro flag (agregarlo al prototipo de la funcion)
					break;
				case 3:
					if(flagC == 1)
					{
						reanudarPublicacion(flagA, listaA, tamA, rubros, tamR);
					}
					else
					{
						printf("Error. No hay publicaciones cargadas.\n");
					}
					//cargar modificacion de otra estructura validada con otro flag (agregarlo al prototipo de la funcion)
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

//Hacer una modificacion por cada estructura
int modificacionCliente(int flagC, eCliente listaC[], int tamC, eAviso listaA[], int tamA)
{
	int isOk = -1;
	int auxId;
	int opcion;
	char confirmar;
	char continuarC;
	int indice;

	char nuevoNombre[30];
	char nuevoApellido[30];
	int nuevoCuit;

	system("clear");
	printf("***** Modificar Cliente *****\n\n");

	if(flagC == 1)
	{
		mostrarCs(listaC, tamC, listaA, tamA);
		if(listaC != NULL && tamC > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID del cliente a modificar: ", "Error. No es un ID.\n", 1000, 2000) == 0 )
		{
			indice = buscarCPorId(auxId, listaC, tamC);

			if(indice == -1)
			{
				printf("No existe ese ID en el sistema.\n");
			}
			else
			{
				printf("El ID %d pertenece al siguiente cliente:\n", auxId);
				printf("ID    Nombre    Apellido    CUIT     Cantidad de avisos\n\n");
				mostrarC(listaC[indice], listaA, tamA);
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
						printf("    3. Modificar cuit\n");
						if(utn_getEntero(&opcion, 3, "Ingrese opcion a modificar: ", "Error, no es una opcion valida", 1, 3) == 0)
						{
							switch(opcion) //copio los nuevos valores al generico
							{
								case 1:
									if(utn_getCadena(nuevoNombre, 30, 3, "Ingrese nuevo nombre: ", "Error, invalido.\n") == 0)
									{
										strcpy(listaC[indice].nombre, nuevoNombre);
										isOk= 0;
									}
									break;
								case 2:
									if(utn_getCadena(nuevoApellido, 30, 3, "Ingrese nuevo apellido: ", "Error, invalido.\n") == 0)
									{
										strcpy(listaC[indice].apellido, nuevoApellido);
										isOk= 0;
									}
									break;
								case 3:
									if(utn_getEntero(&nuevoCuit, 3, "Ingrese nueva edad: ", "Error, invalida.\n", 18, 100) == 0)
									{
										listaC[indice].cuit = nuevoCuit;
										isOk= 0;
									}
									break;
								default:
									printf("No es una opcion valida.\n\n");
							}
							if(isOk == 0)
							{
								printf("Se han modificado los datos correctamente. \n");
								printf("ID    Nombre    Apellido    CUIT     Cantidad de avisos\n\n");
								mostrarC(listaC[indice], listaA, tamA);//muestro el generico con los datos modificados
							}
							printf("Desea seguir modificando? s/n: ");
							fpurge(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
								continuarC = 'n';
							}
						}//if opcion a modificar == 0
					}while(continuarC == 's');
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
		printf("No hay clientes que modificar.\n");

	}

	return isOk;
}

//Hacer una modificacion por cada estructura
int pausaPublicacion(int flagA, eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	int isOk = -1;
	int auxId;
	char confirmar;
	char continuarA;
	int indice;

	system("clear");
	printf("***** Pausar publicacion *****\n\n");

	if(flagA == 1)
	{
		mostrarAs(listaA, tamA, rubros, tamR);
		if(listaA != NULL && tamA > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID de la publicacion a pausar: ", "Error. No es un ID.\n", 1, 1001) == 0 )
		{
			indice = buscarAPorId(auxId, listaA, tamA);//encuentra al generico a modificar

			if(indice == -1)
			{
				printf("No existe ese ID en el sistema.\n");
			}
			else
			{
				if(listaA[indice].estado == 0)
				{
					printf("El ID %d pertenece a la siguiente publicacion:\n", auxId);
					printf("ID    ID cliente    Rubro         Texto  \n\n");
					mostrarA(listaA[indice], rubros, tamR);
					printf("Desea pausarla? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirmar);

					if(confirmar == 's')
					{
						do
						{
							listaA[indice].estado = 0;
							isOk = 0;

							printf("Se han modificado el estado correctamente. \n");
							printf("ID    ID cliente    Rubro         Texto  \n\n");
							mostrarA(listaA[indice], rubros, tamR);
							pause();

							printf("Desea seguir modificando? s/n: ");
							fpurge(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
								continuarA = 'n';
							}

						}while(continuarA == 's');
					}//if confirma
					else if(confirmar == 'n')
					{
						printf("No se han registrado modificaciones.\n");
					}
				}
				else
				{
					printf("Ese anuncio no esta activo\n");
				}

			}//else
		}//if NULL
	}//if flagA == 1
	else
	{
		printf("No hay publicaciones que modificar.\n");

	}

	return isOk;
}

int reanudarPublicacion(int flagA, eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	int isOk = -1;
	int auxId;
	char confirmar;
	char continuarA;
	int indice;

	system("clear");
	printf("***** Reanudar publicacion *****\n\n");

	if(flagA == 1)
	{
		mostrarAs(listaA, tamA, rubros, tamR);
		if(listaA != NULL && tamA > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID de la publicacion a reanudar: ", "Error. No es un ID.\n", 1, 1001) == 0 )
		{
			indice = buscarAPorId(auxId, listaA, tamA);//encuentra al aviso a modificar

			if(indice == -1)
			{
				printf("No existe ese ID en el sistema.\n");
			}
			else
			{
				if(listaA[indice].estado == 0)
				{
					printf("El ID %d pertenece a la siguiente publicacion:\n", auxId);
					printf("ID    ID cliente    Rubro         Texto  \n\n");
					mostrarA(listaA[indice], rubros, tamR);
					printf("Desea reanudarla? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirmar);

					if(confirmar == 's')
					{
						do
						{
							listaA[indice].estado = 1;
							isOk = 0;

							printf("Se han modificado el estado correctamente. \n");
							printf("ID    ID cliente    Rubro         Texto  \n\n");
							mostrarA(listaA[indice], rubros, tamR);
							pause();

							printf("Desea seguir modificando? s/n: ");
							fpurge(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
								continuarA = 'n';
							}

						}while(continuarA == 's');
					}//if confirma
					else if(confirmar == 'n')
					{
						printf("No se han registrado modificaciones.\n");
					}
				}
				else
				{
					printf("Ese anuncio no esta pausado\n");
				}
			}//else
		}//if NULL
	}//if flagM == 1
	else
	{
		printf("No hay publicaciones que modificar.\n");

	}

	return isOk;
}
