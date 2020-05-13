/*
 * tipo.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int id;
	char descripcion[20];
}eTipo;

int cargarDescripTipo(char descripcion[], int idTipo, eTipo tipos[], int tamT);
int mostrarTipos(eTipo tipos[], int tamT);

#endif /* TIPO_H_ */
