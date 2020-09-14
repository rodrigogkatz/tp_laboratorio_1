#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "calculadora.h"

void saludar() {
	printf("\t\t==============================\n");
	printf("\t\t                 CALCULADORA\n");
	printf("\t\t                         v1.0.0\n");
	printf("\t\t                   BIENVENIDO\n");
	printf("\t\t==============================\n");
}

void operarMenu() {
	int primerOperando = 0;
	int segundoOperando = 0;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagDeCalculos = 0;
	char salirDelPrograma = 'n';
	int suma = 0;
	int resta = 0;
	float division = 0;
	int producto = 0;
	long int factorial1erOpe = 0;
	long int factorial2doOpe = 0;

	do {
		switch (menu()) {
		case 1:
			primerOperando = ingresarOperando();
			flagPrimerOperando = primerOperando >= 0 ? 1 : 0;
			break;
		case 2:
			segundoOperando = ingresarOperando();
			flagSegundoOperando = segundoOperando >= 0 ? 1 : 0;
			break;
		case 3:
			if(flagPrimerOperando == 1 && flagSegundoOperando == 1){
				printf("\n\t\tCalculando...");
				printf("\n\t\t(A = %d) y (B = %d)", primerOperando, segundoOperando);
				suma = calcularSumatoria(primerOperando, segundoOperando);
				resta = calcularDiferencia(primerOperando, segundoOperando);
				division = calcularDivision(primerOperando, segundoOperando);
				producto = calcularProducto(primerOperando, segundoOperando);
				factorial1erOpe = calcularFactorial(primerOperando);
				factorial2doOpe = calcularFactorial(segundoOperando);
				flagDeCalculos = 1;
				printf("\n\t\tCalculos finalizados!\n\n");
			} else {
				printf("\n\t\tERROR");
				printf("\n\t\tDebe ingresar los dos operandos antes de hacer los respectivos calculos\n\n");
			}
			break;
		case 4:
			if(flagDeCalculos == 1){
				informarResultados(primerOperando, segundoOperando, suma, resta,division, producto, factorial1erOpe, factorial2doOpe);
				flagPrimerOperando = 0;
				flagSegundoOperando = 0;
				flagDeCalculos = 0;
			} else {
				printf("\n\t\tERROR");
				printf("\n\t\tEs necesario hacer los calculos para imprimir los resultados\n\n");
			}

			break;
		case 5:
			salirDelPrograma = 's';
			flagPrimerOperando = 0;
			flagSegundoOperando = 0;
			flagDeCalculos = 0;
			break;
		default:
			printf("\n\t\tERROR");
			printf("\n\t\tIngrese alguna de las opciones numericas que proporciona el menu\n\n");
			break;
		}

	} while (salirDelPrograma == 'n' || salirDelPrograma == 'N');

	if (salirDelPrograma != 's' || salirDelPrograma != 'S') {
		salir();
	}
}

int menu() {
	int opcion = 0;
	printf("\t\tMenu\n\t\t1. Ingresar 1er operando");
	printf("\n\t\t2. Ingresar 2do operando");
	printf("\n\t\t3. Calcular todas las operaciones");
	printf("\n\t\t4. Informar resultados");
	printf("\n\t\t5. Salir");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &opcion);
	return opcion;
}

int ingresarOperando() {
	int numero = 0;
	printf("\n\t\tIngrese operando: ");
	__fpurge(stdin);
	scanf("%d", &numero);
	while (numero < 0){
		printf("\n\t\tERROR");
		printf("\n\t\tIngrese operando a partir del cero: ");
		__fpurge(stdin);
		scanf("%d", &numero);
	}
	printf("\n\t\t==============================\n");
	return numero;
}

int calcularSumatoria(int primerOperando, int segundoOperando) {
	return primerOperando + segundoOperando;
}

int calcularDiferencia(int primerOperando, int segundoOperando) {
	return primerOperando - segundoOperando;
}

float calcularDivision(int primerOperando, int segundoOperando) {
	if (segundoOperando == 0) {
		return -1;
	} else {
		float division = (float) primerOperando / segundoOperando;
		return division;
	}
}

int calcularProducto(int primerOperando, int segundoOperando) {
	return primerOperando * segundoOperando;
}

long int calcularFactorial(int operando) {
	long int factorial = 1;
	for (int i = 0; i < operando; i++) {
		factorial = factorial * (i + 1);
	}
	return factorial;
}

void informarResultados(int primerOperando, int segundoOperando, int sumatoria,
		int diferencia, float division, int producto, int primerFactorial,
		int segundoFactorial) {
	printf("\n\t\tEl resultado de %i + %i es %i", primerOperando,
			segundoOperando, sumatoria);
	printf("\n\t\tEl resultado de %i - %i es %i", primerOperando,
			segundoOperando, diferencia);
	printf("\n\t\tEl resultado de %i * %i es %i", primerOperando,
			segundoOperando, producto);
	if (segundoOperando > 0) {
		printf("\n\t\tEl resultado de %i / %i es %f", primerOperando,
				segundoOperando, division);
	}
	if (segundoOperando == 0) {
		printf("\n\t\tNo es posible dividir por 0");
	}
	printf("\n\t\tEl factorial de %i es %i y el factorial de %i es %i\n\n",
			primerOperando, primerFactorial, segundoOperando, segundoFactorial);
}

void salir() {
	printf("\n\nGracias vuelva pronto!");
	exit(0);
}
