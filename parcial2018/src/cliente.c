/*
 * cliente.c
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "avisos.h"
#include "cliente.h"


//INICIALIZAR

int inicializarC(eCliente listaC[], int tamC)
{
	if(listaC != NULL)
	{
		for(int i = 0; i < tamC; i++)
		{
			listaC[i].isEmpty = 1;
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
int buscarLibreC(eCliente listaC[], int tamC)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamC; i++)
	{
		if(listaC[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}

int buscarCPorId(int id, eCliente listaC[], int tamC)
{
	int indice = -1;

	for(int i = 0; i < tamC; i++)
	{
		if(listaC[i].id == id && listaC[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}


//MOSTRAR

//hacer tantas como estructuras haya
void mostrarC(eCliente cliente, eAviso listaA[], int tamA)
{
	int cantidadAvisos;
	cantidadAvisos = cantAvisos(cliente.id, listaA, tamA);
	printf("%d    %10s      %10s     %d      %d\n\n", cliente.id, cliente.nombre, cliente.apellido, cliente.cuit, cantidadAvisos);
}

//hacer tantas como estructuras haya
void mostrarCs(eCliente listaC[], int tamC, eAviso listaA[], int tamA)
{
	printf("ID    Nombre    Apellido    CUIT     Cantidad de avisos\n\n");
	for(int i = 0; i < tamC; i++)
	{
		if(listaC[i].isEmpty == 0)
		{
			mostrarC(listaC[i], listaA, tamA);
		}
	}
}
