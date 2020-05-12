/*
 * menusABM.h
 *
 *  Created on: May 12, 2020
 *      Author: catalina
 */

#ifndef MENUSABM_H_
#define MENUSABM_H_
#include "avisos.h"
#include "cliente.h"
#include "rubro.h"


int menu();
int menuAltas();
void alta(int* nextIdC, int* nextIdA, int* flagC, int* flagA, eCliente listaC[], int tamC,  eAviso listaA[], int tamA, eRubro rubros[], int tamR);
int altaC(int idX, eCliente listaC[], int tamC);
int altaA(int idX, eAviso listaA[], int tamA, eRubro rubros[], int tamR, eCliente listaC[], int tamC, int* flagC);
void baja(int flagC, eCliente listaC[], int tamC, eAviso listaA[], int tamA, eRubro rubros[], int tamR);
int bajaC(int idC, int flagC, eCliente listaC[], int tamC, eAviso listaA[], int tamA, eRubro rubros[], int tamR);
int menuModif();
void modificacion(int flagC, int flagA, eCliente listaC[], int tamC, eAviso listaA[], int tamA, eRubro rubros[], int tamR);
int modificacionCliente(int flagC, eCliente listaC[], int tamC, eAviso listaA[], int tamA);
int pausaPublicacion(int flagA, eAviso listaA[], int tamA, eRubro rubros[], int tamR);
int reanudarPublicacion(int flagA, eAviso listaA[], int tamA, eRubro rubros[], int tamR);


#endif /* MENUSABM_H_ */
