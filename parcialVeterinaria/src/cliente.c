/*
 * cliente.c
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "mascota.h"
#include "tipo.h"

//INICIALIZAR

//hacer tantas como estructuras haya
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

//--------------------------------------------------------------------------------------------------------------------------------------------------
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

//hacer tantas como estructuras haya
int buscarClientePorId(int id, eCliente listaC[], int tamC)
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


//--------------------------------------------------------------------------------------------------------------------------------------------------
//MOSTRAR

//hacer tantas como estructuras haya
void mostrarC(eCliente cliente, eMascota listaM[], int tamM, eTipo listaT[], int tamT)
{
	printf("%d    %10s      %10s     %10s      %d       %d     %c\n\n", cliente.id, cliente.nombre, cliente.apellido, cliente.localidad, cliente.telefono, cliente.edad, cliente.sexo);
	printf("Es duenio de las siguientes mascotas: \n\n");
	printf("ID          Nombre            Tipo           Raza      Edad  Peso   Sexo   ID duenio\n\n");
	mostrarMascotasDuenio(cliente.id, listaM, tamM, listaT, tamT);
	printf("___________________________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");
}

//hacer tantas como estructuras haya
void mostrarCs(eCliente listaC[], int tamC, eTipo listaT[], int tamT, eMascota listaM[], int tamM)
{

	for(int i = 0; i < tamC; i++)
	{
		if(listaC[i].isEmpty == 0)
		{
			printf("ID        Nombre         Apellido        Localidad     Telefono      Edad    Sexo\n\n");
			mostrarC(listaC[i], listaM, tamM, listaT, tamT);
		}
	}
}

