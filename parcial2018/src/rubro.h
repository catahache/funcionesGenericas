/*
 * rubro.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef RUBRO_H_
#define RUBRO_H_

typedef struct{
	int id;
	char descripcion[20];
}eRubro;

int cargarDescripRubro(char descripcion[], int idRubro, eRubro rubros[], int tamR);
int mostrarRubros(eRubro rubros[], int tamR);

#endif /* RUBRO_H_ */
