/*
 * avisos.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef AVISOS_H_
#define AVISOS_H_
#include "rubro.h"

typedef struct{
	int id; //del aviso
	int idCliente;
	int rubro;
	char texto[65];
	int estado; //1 activo, 0 pausado
	int isEmpty;

}eAviso;

int inicializarA(eAviso listaA[], int tamA);
int buscarLibreA(eAviso listaA[], int tamA);
int buscarAPorId(int id, eAviso listaA[], int tamA);
void mostrarA(eAviso aviso, eRubro rubros[], int tamR);
void mostrarAs(eAviso listaA[], int tamA, eRubro rubros[], int tamR);
int cantAvisos(int idCliente, eAviso listaA[], int tamA);
void mostrarAvisosPorCliente(int idCliente, eAviso listaA[], int tamA, eRubro rubros[], int tamR);
void eliminarAvisosPorCliente(int idCliente, eAviso listaA[], int tamA);


#endif /* AVISOS_H_ */
