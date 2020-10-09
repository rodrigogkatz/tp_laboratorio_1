#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>

void utn_initializeData(int ids[], char names[], char lastNames[], float salaries[], int sectors[], int areEmpty[], int size){
		for (int i = 0; i < size; i++){
			ids[i] = 0;
			names[i] = "";
			lastNames[i] = "";
			salaries[i] = 0;
			sectors[i] = 0;
			areEmpty[i] = 0;
		}
}
