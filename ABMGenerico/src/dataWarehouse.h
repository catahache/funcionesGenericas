/*
 * dataWarehouse.h
 *
 *  Created on: May 4, 2020
 *      Author: catalina
 */

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_

#include "estructGenerica.h"

//HACER TANTAS FUNCIONES COMO ESTRUCTURAS A HARCODEAR:

void harcodearGenerico(eGenerica listaG[], int cant);


//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//ESTRUCTURAS:

//Empleado
typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;
	char nombre[30];
	char apellido[30];
	int edad;
	eFecha fechaDeIngreso;
	int idSector;
	int isEmpty;

}eEmpleado;

typedef struct{
	int id;
	char descripcion[30];
	int isEmpty;

}eSector;

//------------------------------------------------------------------------------------------------------------------------------------------
//Alumno

typedef struct{
	int id;
	char nombre[30];
	char apellido[30];
	int edad;
	int idCurso;
	int isEmpty;

}eAlumno;

typedef struct{
	int id;
	char descripcion[30];
	int isEmpty;

}eCurso;

//------------------------------------------------------------------------------------------------------------------------------------------
//Mascota

typedef struct{
	int id;
	char nombre[30];
	int edad;
	int idRaza;
	int isEmpty;

}eMascota;

typedef struct{
	int id;
	char descripcion[30];
	int isEmpty;

}eRaza;

//------------------------------------------------------------------------------------------------------------------------------------------
//Musica

typedef struct{
	int id;
	char nombre[30];
	int idTipo;
	char lugar[30];
	int isEmpty;

}eOrquesta;

typedef struct{
	int id;
	char nombre[30];
	char apellido[30];
	int edad;
	int idO; //orquesta
	int idI; //instrumento
	int isEmpty;

}eMusico;

typedef struct{
	int id;
	char descripcion[30];
	int isEmpty;

}eInstrumento;


//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//ARRAYS:

int legajos [] = {1234, 2222, 3234, 8197, 5611, 1993, 1045, 1866, 5467, 9387};

char nombres[][20] = {"Juan", "Alberto", "Lucia", "martina", "sofia", "miguel", "daniela", "luciana", "Martin", "diego", "Camila", "Lucia", "Marcos", "octavio"};
char apellidos[][20] = {"Perez", "Sanchez", "Torres", "Alvarez", "Fernandez", "Gonzalez", "Juarez", "Greco", "Bassi", "Blanco", "Tchaikovsky", "DiBiase", "Sandoval", "Picone"};

char sexos[] = {'m', 'm', 'f', 'f', 'f', 'm', 'f', 'f', 'm', 'm', 'f', 'm', 'm'};

int edades[] = {32, 34, 21, 20, 33, 27, 27, 20, 40, 31, 25, 22, 24, 30};

float sueldos [] = {20000, 34000, 45000, 21000, 25400, 38100, 29700, 23200, 40200, 37900};

int dias[] = {21, 1, 2, 6, 8, 19, 21, 29, 20, 5};
int meses[] = {12, 3, 5, 7, 2, 2, 12, 9, 8, 7};
int anios[] = {2010, 2010, 2013, 2019, 2018, 2016, 2017, 2016, 2014, 2015};

int ids[] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014}; //en orden

int idsMezclados[] = {1001, 1003, 1005, 1010, 1009, 1008, 1009, 1005, 1004, 1001, 1000, 1007, 1006};//mezclados para asignar

int ids1a5[] = {1, 4, 2, 3, 5, 1, 2, 1, 5, 2}; //mezclados para asignar

char nombresOrquestas[][30]= {"Orquesta Entre Rios","Orquesta La Plata", "Sinfonica nacional","Camerata Bariloche", "Camerata lazarte", "Camerata Exaudi", "Filarmonica mendoza", "Sinfonica de Salta", "Sinfonica Uncuyo", "Orquesta Chascomus", "Orquesta Rosario", "Orquesta Camara BSAS", "Orquesta Facultad Medicina"};
int tiposOrquestas[] = {2, 2, 1, 3, 3, 3, 2, 1, 1, 3, 3, 3, 1}; //para asignar a musico
char instrumentos[][30] = {"Flauta madera", "Flauta traversa", "Piano", "Celo", "Celo", "Violin" "Violonchelo", "Saxo", "Tuba", "Trombon", "Triangulo", "Timbal", "Violin"};
int tiposInstrumentos[] = {2, 3, 1, 1, 1, 1, 1, 3, 3, 3, 4, 4, 1}; //para asignar a musico


char lugares[][30] = {"Entre Rios", "La Plata", "CABA", "Bariloche", "Buenos Aires", "Buenos Aires", "Mendoza", "Salta", "Uncuyo", "Chascomus", "Rosario", "Buanos Aires", "CABA"};
char paises[][30] = {"Brasil", "Colombia", "Venezuela", "Argentina", "Estados Unidos", "Argentina", "Inglaterra", "Brasil", "Noruega", "Suecia", "Argentina", "Francia", "Italia", "Canada", "Argentina", "Brasil"};
char provincias[][30] = {"La Pampa", "Tierra del Fuego", "Buenos Aires", "Cordoba", "Entre Rios", "Buenos Aires", "Tucuman", "Formosa", "Buenos Aires", "Salta", "Tierra del Fuego"};

char nombresMascota[][30] = {"Pupi", "Cacho", "Manchas", "Blanca", "Flor", "Akira", "Kira", "Gala", "Luis", "Ulises", "Orejas", "Salchi"};
char razas[][30] = {"salchicha", "san bernardo", "golden retriver", "beagle", "caniche", "caniche", "dalmata", "gran danes", "salchicha", "golden retriever"};

#endif /* DATAWAREHOUSE_H_ */
