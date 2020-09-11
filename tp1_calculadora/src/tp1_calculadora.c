/*
 ============================================================================
 Name        : tp1_calculadora.c
 Author      : Rodrigo Katz
 Version     : 1.0.0
 Copyright   : © Copyright RGK
 Description : Trabajo Práctico N°1 Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "calculadora.h"

int main(void) {
	setbuf(stdout, NULL);

	saludar();
	operarMenu();

	return EXIT_SUCCESS;
}


