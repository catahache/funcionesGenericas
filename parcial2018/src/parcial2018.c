/*
 ============================================================================
 Name        : parcial2018.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LENC 1000
#define LENA 1000
#define LENR 4
#include "utn.h"
#include "cliente.h"
#include "avisos.h"
#include "rubro.h"
#include "menusABM.h"


int main(void) {
	eCliente listaC[LENC];
	eAviso listaA[LENA];
	eRubro listaR [LENR] = {{1, "AAA"},
					 	 	{2, "BBB"},
							{3, "CCC"},
							{4, "DDD"} };

	char continueS = 's';
	char confirm;

	//Ids, crear tantos como estructuras existan:
	int nextIdC = 1000; //arranca en el 1000
	int nextIdA = 1; //hasta 1001

	//Flags Alta:
	int flagC = 0; //ponerla en 1 para HARCODEAR
	int flagA = 0;

	//Inicializar arrays:
	inicializarA(listaA, LENA);
	inicializarC(listaC, LENC);

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
				alta(&nextIdC, &nextIdA, &flagC, &flagA, listaC, LENC, listaA, LENA, listaR, LENR);
				break;

			case 2:
				baja(flagC, listaC, LENC, listaA, LENA, listaR, LENR);
				break;

			case 3:
				modificacion(flagC, flagA, listaC, LENC, listaA, LENA, listaR, LENR);
				break;

			case 4:
				system("clear");
				printf("***** Listar clientes *****");
				mostrarCs(listaC, LENC, listaA, LENA);
				break;
			case 5:
				//informes
				break;
			case 6:
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
