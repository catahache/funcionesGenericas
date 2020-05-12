/*
 * avisos.c
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avisos.h"
#include "utn.h"

//INICIALIZAR

//hacer tantas como estructuras haya
int inicializarA(eAviso listaA[], int tamA)
{
	if(listaA != NULL)
	{
		for(int i = 0; i < tamA; i++)
		{
			listaA[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

//BUSCAR

//hacer tantas como estructuras haya
int buscarLibreA(eAviso listaA[], int tamA)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamA; i++)
	{
		if(listaA[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}

int buscarAPorId(int id, eAviso listaA[], int tamA)
{
	int indice = -1;

	for(int i = 0; i < tamA; i++)
	{
		if(listaA[i].id == id && listaA[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}

//MOSTRAR

//hacer tantas como estructuras haya
void mostrarA(eAviso aviso, eRubro rubros[], int tamR)
{
	char descripRubro[20];

	cargarDescripRubro(descripRubro, aviso.rubro, rubros, tamR);
	printf("%d    %d      %10s     %60s     %d\n\n", aviso.id, aviso.idCliente, descripRubro, aviso.texto, aviso.estado);
}

//hacer tantas como estructuras haya
void mostrarAs(eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	printf("ID    ID cliente    Rubro         Texto      Estado \n\n");
	for(int i = 0; i < tamA; i++)
	{
		if(listaA[i].isEmpty == 0)
		{
			mostrarA(listaA[i], rubros, tamR);
		}
	}
}

int cantAvisos(int idCliente, eAviso listaA[], int tamA)
{
	int cantidadA = 0;

	for(int i = 0; i < tamA; i++)
	{
		if(idCliente == listaA[i].idCliente)
		{
			cantidadA++;
		}
	}
	return cantidadA;
}

void mostrarAvisosPorCliente(int idCliente, eAviso listaA[], int tamA, eRubro rubros[], int tamR)
{
	for(int i = 0; i < tamA; i++)
	{
		if(idCliente == listaA[i].idCliente)
		{
			mostrarA(listaA[i], rubros, tamR);
		}
	}
}

void eliminarAvisosPorCliente(int idCliente, eAviso listaA[], int tamA)
{
	for(int i = 0; i < tamA; i++)
	{
		if(idCliente == listaA[i].idCliente)
		{
			listaA[i].isEmpty = 1;
		}
	}
}
