#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "../Headers/UTN_Menu.h"
#include "../Headers/UTN_Employees.h"
#include "../Headers/UTN_Validations.h"

int utn_getString(char *pStringResult, char* message, char* errorMessage, int min, int max){
	char string[max];
	printf("\n\t\t%s", message);
	__fpurge(stdin);
	fgets(string, max, stdin);
	while(strlen(string) <= min || strlen(string) >= max) {
		printf("\n\t\t%s", errorMessage);
		__fpurge(stdin);
		fgets(string, max, stdin);
	}
	strcpy(pStringResult, string);
	//printf("El valor ingresado fue string %s pStringResult %s", string, pStringResult);
	if(strlen(pStringResult) < max){
		return 0;
	} else {
		return -1;
	}
}

int utn_getNumber(int* pResult, char* message, char* errorMessage, int min, int max){
	int number;
	printf("\n\t%s",message);
	__fpurge(stdin);
	scanf("%i", &number);
	while(number < min || number > max) {
		printf("\n\t\t%s", errorMessage);
		printf("\n\t%s",message);
		__fpurge(stdin);
		scanf("%i", &number);
	}
	*pResult = number;
	if(pResult) {
		return 0;
	} else {
		return -1;
	}
}

int utn_getFloat(float* pFloatResult, char* message, char* errorMessage, int min, int max){
	float floatNumber;
		printf("\n\t%s",message);
		__fpurge(stdin);
		scanf("%f", &floatNumber);
		while(floatNumber < min || floatNumber > max) {
			printf("\n\t\t%s", errorMessage);
			printf("\n\t%s",message);
			__fpurge(stdin);
			scanf("%f", &floatNumber);
		}
		*pFloatResult = floatNumber;
		if(pFloatResult) {
			return 0;
		} else {
			return -1;
		}
}
