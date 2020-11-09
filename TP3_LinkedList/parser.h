/*
 * parser.h
 *
 *  Created on: Nov 1, 2020
 *      Author: root
 */

#ifndef PARSER_H_
#define PARSER_H_
/**
 * brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * param path char*
 * param pArrayListEmployee LinkedList*
 * return int
 **/
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/**
 * brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * param path char*
 * param pArrayListEmployee LinkedList*
 * return int
 **/
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
