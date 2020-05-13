/*
 * mascota.c
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascota.h"

//INICIALIZAR

//hacer tantas como estructuras haya
int inicializarM(eMascota listaM[], int tamM)
{
	if(listaM != NULL)
	{
		for(int i = 0; i < tamM; i++)
		{
			listaM[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//BUSCAR

//hacer tantas como estructuras haya
int buscarLibreM(eMascota listaM[], int tamM)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamM; i++)
	{
		if(listaM[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}

//hacer tantas como estructuras haya
int buscarMascotaPorId(int id, eMascota listaM[], int tamM)
{
	int indice = -1;

	for(int i = 0; i < tamM; i++)
	{
		if(listaM[i].id == id && listaM[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta//
		{
			indice = i;
			break;
		}
	}

	return indice;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//MOSTRAR

//hacer tantas como estructuras haya
void mostrarM(eMascota mascota, int tamM, eTipo listaT[], int tamT)
{
	char descripTipo[20];

	cargarDescripTipo(descripTipo, mascota.idTipo, listaT, tamT);
	printf("%d    %10s      %10s     %10s      %d     %.2f     %c    %d\n\n", mascota.id, mascota.nombre, descripTipo, mascota.raza, mascota.edad, mascota.peso, mascota.sexo, mascota.idDuenio);
}

//hacer tantas como estructuras haya
void mostrarMs(eMascota listaM[], int tamM, eTipo listaT[], int tamT)
{
	printf("ID        Nombre           Tipo        Raza    Edad     Peso   Sexo    ID duenio\n\n");
	for(int i = 0; i < tamM; i++)
	{
		if(listaM[i].isEmpty == 0)
		{
			mostrarM(listaM[i], tamM, listaT, tamT);
		}
	}
}


void mostrarMascotasDuenio(int idD, eMascota listaM[], int tamM, eTipo listaT[], int tamT)
{
	for(int i = 0; i < tamM; i++)
	{
		if(idD == listaM[i].idDuenio)
		{
			mostrarM(listaM[i], tamM, listaT, tamT);
		}
	}
}
