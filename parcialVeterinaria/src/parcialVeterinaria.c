/*
 ============================================================================
 Name        : parcialVeterinaria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "tipo.h"
#include "mascota.h"
#include "cliente.h"
#include "menusABM.h"

#define LENC 10
#define LENM 20
#define LENT 3

int main(void) {

	eCliente listaC[LENC] = {
			{1000, "Maria", "Rodriguez", "Ituzaingo", 43221445, 45, 'f', 0},
			{1001, "Roberto", "Alonso", "Lanus", 43221335, 40, 'm', 0},
			{1002, "Julia", "Alfonso", "Lanus", 43224545, 15, 'f', 0},
			{1003, "Rodrigo", "Maquez", "Moreno", 43221565, 18, 'm', 0},
			{1004, "Carlos", "Heredia", "Quilmes", 46721445, 35, 'm', 0}
			};
	eMascota listaM[LENM] = {
			{1000, "Bigotes", 1, "Persa", 3, 4.8, 'f', 1000, 0},
			{1001, "Clara", 1, "Siames", 2, 4.6, 'f', 1000, 0},
			{1002, "Luis", 2, "Labrador", 5, 15, 'm', 1001, 0},
			{1003, "Felipe", 2, "Ovejero", 7, 20, 'm', 1001, 0},
			{1004, "Paris", 1, "Persa", 6, 4.2, 'm', 1001, 0},
			{1005, "Pocho", 2, "Pitbull", 3, 18, 'm', 1002, 0},
			{1006, "Rebeca", 3, "Verde", 1, 2.8, 'f', 1002, 0},
			{1007, "Manchas", 2, "Labrador", 5, 14, 'f', 1003, 0},
			{1008, "Gala", 1, "Ragdoll", 5, 4, 'f', 1004, 0},
			{1009, "Alba", 1, "Bengala", 1, 3.8, 'f', 1004, 0},
			{1010, "Florencia", 2, "Bulldog", 8, 22, 'f', 1004, 0},
			};
	eTipo tipos[LENT] = {{1, "Gato"}, {2, "Perro"}, {3, "Raro"}};

	//inicializarM(listaM, LENM);
	//inicializarC(listaC, LENC);

	//ocupo los lugares hardcodeados:
	for(int i = 6; i < LENC; i++)
	{
		listaC[i].isEmpty = 1;
	}

	for(int i = 11; i < LENM; i++)
	{
		listaM[i].isEmpty = 1;
	}


	char continueS = 's';
	char confirm;

	//Ids, crear tantos como estructuras existan:
	int nextIdM = 1011;




	/*
	HARCODEAR
	harcodearGenerico(listaG, 13);
	//para harcodear mas estructuras, crear la estructura y crear la funcion de harcodeo para la funcion especifica
	*/

	do
	{
		system("clear");
		switch(menu())
		{
			case 1:
				alta(&nextIdM, listaM, LENM, tipos, LENT, listaC, LENC);
				break;

			case 2:
				baja(listaM, listaC, LENC, LENM, tipos, LENT);
				break;

			case 3:
				modificacion(listaM, LENM, tipos, LENT);
				break;

			case 4:
				mostrarCs(listaC, LENC,tipos, LENT, listaM, LENM);
				break;

			case 5:
				system("clear");
				printf("\n***** Salir *****\n\n ");
				printf("Confirma salida? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					continueS = 'n';
				}
				break;
			default:
				printf("No es una opcion valida.\n");
		}
		pause();


	}while(continueS == 's');

	return EXIT_SUCCESS;
}
