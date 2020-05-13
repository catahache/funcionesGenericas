/*
 * cliente.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "mascota.h"
#include "tipo.h"

typedef struct{
	int id;
	char nombre[30];
	char apellido[20];
	char localidad[20];
	int telefono;
	int edad;
	char sexo;
	int isEmpty;

}eCliente;

int inicializarC(eCliente listaC[], int tamC);
int buscarLibreC(eCliente listaC[], int tamC);
int buscarClientePorId(int id, eCliente listaC[], int tamC);
void mostrarC(eCliente cliente, eMascota listaM[], int tamM, eTipo listaT[], int tamT);
void mostrarCs(eCliente listaC[], int tamC, eTipo listaT[], int tamT, eMascota listaM[], int tamM);


#endif /* CLIENTE_H_ */
