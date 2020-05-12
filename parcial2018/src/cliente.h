/*
 * cliente.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "avisos.h"



typedef struct{
	int id;
	char nombre[30];
	char apellido[30];
	int cuit;
	int isEmpty;

}eCliente;

int inicializarC(eCliente listaC[], int tamC);
int buscarLibreC(eCliente listaC[], int tamC);
int buscarCPorId(int id, eCliente listaC[], int tamC);
void mostrarC(eCliente cliente, eAviso listaA[], int tamA);
void mostrarCs(eCliente listaC[], int tamC, eAviso listaA[], int tamA);


#endif /* CLIENTE_H_ */
