/*
 * menusABM.h
 *
 *  Created on: May 9, 2020
 *      Author: catalina
 */

#ifndef MENUSABM_H_
#define MENUSABM_H_

#include "estructGenerica.h"
#include "estructTipo.h"

//MODIFICAR LAS SIGUIENTES FUNCIONES CON LAS ESTRUCTURAS NECESARIAS. CUANTAS MAS ESTRUCTURAS Y TIPOS CREE, MAS PARAMETROS LES PASO!!!

//MAIN:
int menu();


//-----------------------------------------------------------------------------------------------------------------------------------------------
//MENU ALTAS:

int menuAltas();

//esta es la funcion que llamo en main para dar de alta:
void alta(int* nextIdG, int* flagG, eGenerica listaG[], int tamG,  eTipoG listaT[], int tamT);


//-----------------------------------------------------------------------------------------------------------------------------------------------
//MENU BAJAS:

int menuBajas();

//esta es la funcion que llamo en main para dar de baja:
void baja(int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT);


//-----------------------------------------------------------------------------------------------------------------------------------------------
//MENU MODIFICACIONES:

int menuModif();

//esta es la funcion que llamo en main para modificar:
void modificacion(int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT);


//-----------------------------------------------------------------------------------------------------------------------------------------------
//FUNCIONES AUXILIARES A LOS MENUS.

//Hacer un alta por cada estructura
int altaGenerico(int idX, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT);

//Hacer una baja por cada estructura
int bajaGenerico(int idG, int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT);

//Hacer una modificacion por cada estructura
int modificacionGenerica(int flagG, eGenerica listaG[], int tamG, eTipoG listaT[], int tamT);

#endif /* MENUSABM_H_ */
