/*
 * estructTipo.h
 *
 *  Created on: May 9, 2020
 *      Author: catalina
 */

#ifndef ESTRUCTTIPO_H_
#define ESTRUCTTIPO_H_

//EN EL CASO DE QUE HAYA MAS ESTRUCTURAS, HACER UNA DE CADA UNA DE ESTAS FUNCIONES POR CADA ESTRUCTURA CREADA!

typedef struct{
	int id;
	char descripcion[30];

}eTipoG;

//hacer tantas como tipos haya (sector, tipo de instrumento, raza)
int cargarDescripTipo(char descripcion[], int idTipo, eTipoG tipos[], int tamT);

//hacer tantas como tipos haya (sector, tipo de instrumento, raza)
int mostrarTipos(eTipoG tipos[], int tamT);

#endif /* ESTRUCTTIPO_H_ */
