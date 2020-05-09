/*
 ============================================================================
 Name        : ABMGenerico.c
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
#include "menusABM.h"
#include "estructGenerica.h"
#include "estructTipo.h"

#define LENG 50 //largo vector generico
#define LENT 4 //largo vector tipo

int main(void) {
	eGenerica listaG[LENG];
	eTipoG listaT[LENT] =  {{1, ""},
							{2, ""},
							{3, ""},
							{4, ""} };

	char continueS = 's';
	char confirm;
	//Ids:
	int nextIdG = 1000; //arranca en el 1000

	//Flags Alta:
	int flagG = 0; //ponerla en 1 para HARCODEAR

	//Inicializar arrays:
	inicializarG(listaG, LENG);

	/*
	HARCODEAR
	harcodear(listaG, 13);
	*/

	do
	{
		system("clear");
		switch(menu())
		{
			case 1:
				alta(&nextIdG, &flagG, listaG, LENG, listaT, LENT);
				break;

			case 2:
				baja(flagG, listaG, LENG, listaT, LENT);
				break;

			case 3:
				modificacion(flagG, listaG, LENG, listaT, LENT);
				break;

			case 4:
				//Informes
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
