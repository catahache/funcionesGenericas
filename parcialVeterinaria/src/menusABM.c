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
	printf("5. SALIR\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 5);

	return opcion;

}

//ALTAS:


//esta es la funcion que llamo en main:
void alta(int* nextIdM, eMascota listaM[], int tamM,  eTipo listaT[], int tamT, eCliente listaC[], int tamC)
{
	//pasar next id de todos los que sean necesarios desde main
	//pasar vector y tamanio necesarios
	//pasar todas las flags necesarias desde main
	//pasar tipos necesarios

	char continueS = 's';
	char confirm;

	int idM = *nextIdM;

	if(nextIdM != NULL && listaM != NULL)
	{
		do
		{

			if(altaMascota(idM, listaM, tamM, listaT, tamT, listaC, tamC)  == 1)
			{
				*nextIdM = idM++;
			}

			system("clear");
			printf("\n***** Salir *****\n\n ");
			printf("Seguir dando de alta? s/n: ");
			fpurge(stdin);
			scanf("%c", &confirm);
			if(confirm == 'n')
			{
				continueS = 'n';
			}

		}while(continueS == 's');
	}
}

//BAJAS:


//esta es la funcion que llamo en main para dar de baja:
void baja(eMascota listaM[], eCliente listaC[], int tamC, int tamM, eTipo listaT[], int tamT)
{
	//pasar vector y tamanio necesarios
	//pasar ids necesarios
	//pasar flags necesarias

	int idM;


	if(listaM != NULL) //agregar las listas que sean
	{
		mostrarMs(listaM, tamM, listaT, tamT);
		utn_getEntero(&idM, 3, "Ingrese el id de la mascota a eliminar: ", "Error,id no valido.\n", 1000, 2000);
		if(bajaMascota(idM, listaM, tamM, listaT, tamT) == 1)
		{
			printf("Se ha eliminado la mascota con exito.\n\n");
		}

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
void modificacion(eMascota listaM[], int tamM, eTipo listaT[], int tamT)
{
	//pasar vector y tamanio necesarios
	//pasar ids necesarios
	//pasar flags necesarias
	char continueS = 's';
	char confirm;


	if(listaM != NULL && listaT != NULL) //agregar las listas que sean
	{
		do
		{
			modificacionMascota(listaM, tamM, listaT, tamT);
			system("clear");
			printf("\n***** Salir *****\n\n ");
			printf("Confirma salida? s/n: ");
			fpurge(stdin);
			scanf("%c", &confirm);
			if(confirm == 's')
			{
				continueS = 'n';
			}

		}while(continueS == 's');
	}
}




//Hacer un alta por cada estructura
int altaMascota(int idX, eMascota listaM[], int tamM, eTipo listaT[], int tamT, eCliente listaC[], int tamC)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibreM(listaM, tamM);

	if(listaM != NULL && listaT != NULL && tamM > 0 && tamT > 0)
	{
		system("clear");
		printf("***** Alta Mascota *****\n");
		if(indice < 0)
		{
			printf("Sistema completo.\n");
		}
		else
		{
			printf("Duenios disponibles:\n");
			mostrarCs(listaC, tamC, listaT, tamT, listaM, tamM);
			if(utn_getEntero(&listaM[indice].idDuenio, 3, "Ingrese ID del duenio: ", "El ID ingresado no es valido.\n", 1000, 2000) == 0 &&
				utn_getCadena(listaM[indice].nombre, 30, 3, "\nIngrese nombre: ", "El nombre ingresado es invalido.\n") == 0)
			{
				mostrarTipos(listaT, tamT); //muestra los tipos

				if(utn_getEntero(&listaM[indice].idTipo, 3, "Ingrese tipo: ", "El tipo ingresado no es valido.\n", 1, 3) == 0 &&
					utn_getCadena(listaM[indice].raza, 30, 3, "\nIngrese raza: ", "La raza ingresada es invalida.\n") == 0 &&
					utn_getFlotante(&listaM[indice].peso, 3, "Ingrese peso: ", "El peso ingresado no es valido.\n", 1, 35) == 0)
				{
					printf("Ingrese sexo:\n");
					fpurge(stdin);
					scanf("%c", &listaM[indice].sexo);
					listaM[indice].id = idX;
					listaM[indice].isEmpty = 0; //lleno el lugar
					todoOk = 1; //exito
				}
			}
		}//if indice
	}//if NULL
	return todoOk;
}

//Hacer una baja por cada estructura
int bajaMascota(int idM,  eMascota listaM[], int tamM, eTipo listaT[], int tamT)
{
	int isOk = 0;
	char eliminarM;
	int indiceM;

		indiceM = buscarMascotaPorId(idM, listaM, tamT); //busca con el ID que conseguimos en la funcion baja y devuelve el indice donde esta o -1
		if(indiceM > -1)
		{
			mostrarM(listaM[indiceM], tamM, listaT, tamT);
			printf("Eliminar? s/n: ");
			scanf("%c", &eliminarM);
			if(eliminarM == 's')
			{
				listaM[indiceM].isEmpty = 1; //eliminar
				isOk = 1;
			}
			else
			{
				printf("No se han realizado cambios.\n");
			}
		}
		else
		{
			printf("No existe mascota con ese id.\n");
		}

	return isOk;
}


//Hacer una modificacion por cada estructura
int modificacionMascota(eMascota listaM[], int tamM, eTipo listaT[], int tamT)
{
	int isOk = -1;
	int auxId;
	int opcion;
	char confirmar;
	char continuarM;
	int indice;

	char nuevoNombre[30];
	char nuevaRaza[30];
	int nuevaEdad;
	int nuevoTipo;
	float nuevoPeso;
	char nuevoSexo;

	system("clear");
	printf("***** Modificar *****\n\n");

	mostrarMs(listaM, tamM, listaT, tamT);

	if(listaM != NULL && tamM > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID de la mascota a modificar: ", "Error. No es un ID.\n", 1000, 2000) == 0 )
	{

		indice = buscarMascotaPorId(auxId, listaM, tamM);

		if(indice == -1)
		{
			printf("No existe ese ID en el sistema.\n");
		}
		else
		{
			printf("El ID %d pertenece a la siguiente mascota:\n", auxId);
			printf("ID    Nombre    Tipo     Raza     Edad     Peso      Sexo      ID duenio\n\n");
			mostrarM(listaM[indice], tamM, listaT, tamT);
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
					printf("    2. Modificar Tipo\n");
					printf("    3. Modificar Raza\n");
					printf("    4. Modificar edad\n");
					printf("    5. Modificar peso\n");
					printf("    6. Modificar sexo\n");
					if(utn_getEntero(&opcion, 3, "Ingrese opcion a modificar: ", "Error, no es una opcion valida", 1, 4) == 0)
					{
						switch(opcion) //copio los nuevos valores al generico
						{
							case 1:
								if(utn_getCadena(nuevoNombre, 30, 3, "Ingrese nuevo nombre: ", "Error, invalido.\n") == 0)
								{
									strcpy(listaM[indice].nombre, nuevoNombre);
									isOk= 0;
								}
								break;
							case 2:
								printf("Tipos disponibles:\n");
								mostrarTipos(listaT, tamT);
								if(utn_getEntero(&nuevoTipo, 3, "Ingrese nuevo tipo: ", "Error, invalido.\n", 1, 3) == 0)
								{
									listaM[indice].idTipo = nuevoTipo;
									isOk= 0;
								}
								break;
							case 3:
								if(utn_getCadena(nuevaRaza, 18, 3, "Ingrese nueva raza: ", "Error. Raza invalida.\n") == 0)
								{
									strcpy(listaM[indice].raza, nuevaRaza);
									isOk= 0;
								}
								break;
							case 4:
								if(utn_getEntero(&nuevaEdad, 3, "Ingrese nueva edad ", "Error, invalida.\n", 1, 25) == 0)
								{
									listaM[indice].edad = nuevaEdad;
									isOk= 0;
								}
								break;
							case 5:
								if(utn_getFlotante(&nuevoPeso, 3, "Ingrese nuevo peso: ", "Error, pero invalido.\n", 1, 35) == 0)
								{
									listaM[indice].peso = nuevoPeso;
									isOk= 0;
								}
								break;
							case 6:
								printf("Ingrese nuevo sexo: ");
								scanf("%c", &nuevoSexo);
								listaM[indice].sexo = nuevoSexo;
								break;
							default:
								printf("No es una opcion valida.\n\n");
						}
						if(isOk == 0)
						{
							printf("Se han modificado los datos correctamente. \n");
							printf("ID    Nombre    Tipo     Raza     Edad     Peso      Sexo      ID duenio\n\n");
							mostrarMs(listaM, tamM, listaT, tamT);
						}
						printf("Desea seguir modificando? s/n: ");
						fpurge(stdin);
						scanf("%c", &confirmar);
						if(confirmar == 's')
						{
							continuarM = 'n';
						}
					}//if opcion a modificar == 0
				}while(continuarM == 's');
			}//if confirma
			else if(confirmar == 'n')
			{
				printf("No se han registrado modificaciones.\n");
			}
		}//else
	}//if NULL

	return isOk;
}




