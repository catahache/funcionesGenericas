/*
 * dataWarehouse.c
 *
 *  Created on: May 9, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "estructGenerica.h"
#include "estructTipo.h"

//HACER TANTAS FUNCIONES COMO ESTRUCTURAS A HARCODEAR:

void harcodearGenerico(eGenerica listaG[], int cant)
{
	for(int i = 0; i < cant; i++)
	{
		listaG[i].id = ids[i];
		strcpy(listaG[i].nombre, nombres[i]);
		strcpy(listaG[i].apellido, apellidos[i]);
		listaG[i].edad = edades[i];
		listaG[i].idTipo = ids1a5[i]; //ejemplo
		listaG[i].isEmpty = 0;
	}
}
