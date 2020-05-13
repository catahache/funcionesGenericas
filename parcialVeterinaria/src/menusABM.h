/*
 * menusABM.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef MENUSABM_H_
#define MENUSABM_H_
#include "mascota.h"
#include "tipo.h"
#include "cliente.h"

int menu();
void alta(int* nextIdM, eMascota listaM[], int tamM,  eTipo listaT[], int tamT, eCliente listaC[], int tamC);
void baja(eMascota listaM[], eCliente listaC[], int tamC, int tamM, eTipo listaT[], int tamT);
int menuModif();
void modificacion(eMascota listaM[], int tamM, eTipo listaT[], int tamT);
int altaMascota(int idX, eMascota listaM[], int tamM, eTipo listaT[], int tamT, eCliente listaC[], int tamC);
int bajaMascota(int idM,  eMascota listaM[], int tamM, eTipo listaT[], int tamT);
int modificacionMascota(eMascota listaM[], int tamM, eTipo listaT[], int tamT);


#endif /* MENUSABM_H_ */
