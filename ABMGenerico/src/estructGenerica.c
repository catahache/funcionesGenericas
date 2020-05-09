/*
 * estructGenerica.c
 *
 *  Created on: May 9, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructGenerica.h"
#include "estructTipo.h"

//EN ESTE EJEMPLO, SOLO HAY UNA ESTRUCTURA
//EN EL CASO DE QUE HAYA MAS ESTRUCTURAS, HACER UNA DE CADA UNA DE ESTAS FUNCIONES POR CADA ESTRUCTURA CREADA! (COLOCAR EN SU RESPECTIVA LIBRERIA)

//hacer tantas como estructuras haya
int inicializarG(eGenerica listaG[], int tamG)
{
	if(listaG != NULL)
	{
		for(int i = 0; i < tamG; i++)
		{
			listaG[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

//hacer tantas como estructuras haya
int buscarLibre(eGenerica listaG[], int tamG)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamG; i++)
	{
		if(listaG[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}

//hacer tantas como estructuras haya
int buscarGenericoPorId(int id, eGenerica listaG[], int tamG)
{
	int indice = -1;

	for(int i = 0; i < tamG; i++)
	{
		if(listaG[i].id == id && listaG[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}

//hacer tantas como estructuras haya
void mostrarGenerico(eGenerica generico, eTipoG listaT[], int tamT)
{
	char descripTipo[20];

	cargarDescripTipo(descripTipo, generico.idTipo, listaT, tamT);
	printf("%d    %10s      %10s     %d      %10s\n\n", generico.id, generico.nombre, generico.apellido, generico.edad, descripTipo);
}

//hacer tantas como estructuras haya
void mostrarGenericos(eGenerica listaG[], eTipoG listaT[], int tamT)
{
	printf("ID    Nombre    Apellido    Edad     Tipo\n\n");
	for(int i = 0; i < tamT; i++)
	{
		if(listaG[i].isEmpty == 0)
		{
			mostrarGenerico(listaG[i], listaT, tamT);
		}
	}
}
