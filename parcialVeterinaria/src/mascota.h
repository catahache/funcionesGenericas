/*
 * mascota.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef MASCOTA_H_
#define MASCOTA_H_
#include "tipo.h"

typedef struct{
	int id;
	char nombre[30];
	int idTipo;
	char raza[20];
	int edad;
	float peso;
	char sexo;
	int idDuenio;
	int isEmpty;

}eMascota;

int inicializarM(eMascota listaM[], int tamM);
int buscarLibreM(eMascota listaM[], int tamM);
int buscarMascotaPorId(int id, eMascota listaM[], int tamM);
void mostrarM(eMascota mascota, int tamM, eTipo listaT[], int tamT);
void mostrarMs(eMascota listaM[], int tamM, eTipo listaT[], int tamT);
void mostrarMascotasDuenio(int idD, eMascota listaM[], int tamM, eTipo listaT[], int tamT);


#endif /* MASCOTA_H_ */
