/*
 * rubro.c
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubro.h"
#include "utn.h"

//hacer tantas como tipos haya (sector, tipo de instrumento, raza)
int cargarDescripRubro(char descripcion[], int idRubro, eRubro rubros[], int tamR)
{
	int isOk = 0;

	for(int i = 0; i < tamR; i++)
	{
		if(rubros[i].id == idRubro) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
		{
			strcpy(descripcion, rubros[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
			isOk = 1; //exito
			break;
		}
	}

	return isOk;
}

//hacer tantas como tipos haya (sector, tipo de instrumento, raza)
int mostrarRubros(eRubro rubros[], int tamR)
{
	int isOk = 0;
	if(rubros != NULL)
	{
		isOk = 1;
		printf("*** Rubros ***\n");
		printf("  ID     Descripcion\n\n");

		for(int i = 0; i < tamR; i++)
		{
			printf("%d   %10s \n", rubros[i].id, rubros[i].descripcion);
		}
	}
	return isOk;
}
