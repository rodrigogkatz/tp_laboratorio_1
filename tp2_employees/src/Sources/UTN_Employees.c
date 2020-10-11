#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "../Headers/UTN_Employees.h"
#include "../Headers/UTN_Validations.h"

int initEmployees(Employee* list, int len) {
	if( list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			list[i].isEmpty = 1;
		}
		return 0;
	} else {
		printf("\n\t\tERROR:\n\t\tNo se pudo inicializar la estructura de Empleados");
		return -1;
	}
}


int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) {
	if( list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 1) {
				list[i].id = id + 1;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;
				break;
			}

		}
		return 0;
	} else {
		return -1;
	}
}

int findEmployeeById(Employee* list, int len, int id) {
	int matches = 0;
	if( list != NULL && len > 0) {
		printf("\n\t\tBuscando legajo %d...", id);
			for(int i = 0; i < len; i++){
				if(list[i].id == id){
					matches++;
					break;
				}
			}
		}
	if(matches == 1){
		printf("\n\t\tLegajo Existente");
		return 0;
	} else {
		printf("\n\t\tLegajo Inexistente");
		return -1;
	}
}

int modifyEmployee(Employee* list, int len, int id) {
	int modifiedEmployees = 0;
	int sector;
	float salary;
	char name[MAX_STR_SIZE];
	char lastName[MAX_STR_SIZE];
	int isNameOk = -1;
	int isLastNameOk = -1;
	int isSectorOk = -1;
	int isSalaryOk = -1;
	int employeeExists = findEmployeeById(list, len, id);
	int cancelModification = -1;

	if( list != NULL && len > 0 && employeeExists == 0) {
		do {
				switch (employeeModificationMenu()) {
				case 1:
					isNameOk = utn_getString(name, "Ingrese el nuevo nombre del empleado: ", "El nombre debe tener entre 2 y 50 caracteres.\n\t\tIntente nuevamente: ", MIN_STR_SIZE, MAX_STR_SIZE);
					if(isNameOk == 0){
						for(int i = 0; i < len; i++){
							if(list[i].id == id){
								strcpy(list[i].name, name);
								break;
							}
						}
					}
					break;
				case 2:
					isLastNameOk = utn_getString(lastName, "Ingrese el nuevo apellido del empleado: ", "El apellido es demasiado largo.\n\t\tIntente nuevamente: ", MIN_STR_SIZE, MAX_STR_SIZE);
					if(isLastNameOk == 0){
						for(int i = 0; i < len; i++){
							if(list[i].id == id){
								strcpy(list[i].lastName, lastName);
								break;
							}
						}
					}
					break;
				case 3:
					isSectorOk = utn_getNumber(&sector, "\n\t\tIngrese el nuevo numero de sector: ", "\n\t\tERROR:\n\t\tEl sector ingresado debe estar comprendido entre 1 y 1000", 1, QTY_EMPLOYEES);
					if(isSectorOk == 0){
						for(int i = 0; i < len; i++){
							if(list[i].id == id){
								list[i].sector = sector;
								break;
							}
						}
					}
					break;
				case 4:
					isSalaryOk = utn_getFloat(&salary, "\n\t\tIngrese el nuevo salario ", "\n\t\tERROR:\n\t\tEl salario ingresado debe estar comprendido entre $50.000,- y $500.000,-", 50000, 500000);
					if(isSalaryOk == 0){
						for(int i = 0; i < len; i++){
							if(list[i].id == id){
								list[i].salary = salary;
								break;
							}
						}
					}
					break;
				case 5:
					cancelModification = 0;
					break;
				default:
					printf("\n\t\tERROR\n\t\tIngrese una de las opciones numericas que proporciona el menu\n\n");
					break;
				}
			} while (cancelModification == -1);

			for(int i = 0; i < len; i++){
				if(list[i].id == id){
					list[i].isEmpty = 0;
					break;
				}
				modifiedEmployees++;
			}
		}
	if(modifiedEmployees == 1) {
		return 0;
	} else {
		return -1;
	}
}

int employeeModificationMenu() {
	int option = 0;
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tMenu");
	printf("\n\t\t1. Modificar Nombre");
	printf("\n\t\t2. Modificar Apellido");
	printf("\n\t\t3. Modificar Sector");
	printf("\n\t\t4. Modificar Salario");
	printf("\n\t\t5. Salir");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &option);
	return option;
}

int removeEmployee(Employee* list, int len, int id) {
	int removedEmployees = 0;
	int employeeExists = findEmployeeById(list, len, id);
	if( list != NULL && len > 0 && employeeExists == 0) {
		printf("\n\t\tEliminando legajo %d...", id);
			for(int i = 0; i < len; i++){
				if(list[i].id == id){
					list[i].isEmpty = 1;
					removedEmployees++;
					break;
				}
			}
		}
	if(removedEmployees == 1) {
		return 0;
	} else {
		return -1;
	}
}

int sortEmployees(Employee* list, int len, int order) {
	int toReturn = -1;
	float auxSalary = 0;
	int auxSector = 0;
	char auxName[MAX_STR_SIZE] = "";
	char auxLastName[MAX_STR_SIZE] = "";
	int countEmployeesToSort = 0;

	if( list != NULL && len > 0) {
		for(int i = 0; i < len; i++){
			 if(list[i].isEmpty == 0) {
				 countEmployeesToSort++;
			 }
		}
		switch (order) {
			case 1:
				for(int i = 0; i < countEmployeesToSort -1; i++){
					for(int j = i +1; j < countEmployeesToSort; j++){
						if(strcmp(list[i].lastName, list[j].lastName) > 0){
							strcpy(auxName, list[i].name);
							strcpy(list[i].name, list[j].name);
							strcpy(list[j].name, auxName);
							strcpy(auxLastName, list[i].lastName);
							strcpy(list[i].lastName, list[j].lastName);
							strcpy(list[j].lastName, auxLastName);
							auxSector = list[i].sector;
							list[i].sector = list[j].sector;
							list[j].sector = auxSector;
							auxSalary = list[i].salary;
							list[i].salary = list[j].salary;
							list[j].salary = auxSalary;
						} else if(strcmp(list[i].lastName, list[j].lastName) == 0){
							if(list[i].sector >= list[j].sector){
								strcpy(auxName, list[i].name);
								strcpy(list[i].name, list[j].name);
								strcpy(list[j].name, auxName);
								strcpy(auxLastName, list[i].lastName);
								strcpy(list[i].lastName, list[j].lastName);
								strcpy(list[j].lastName, auxLastName);
								auxSector = list[i].sector;
								list[i].sector = list[j].sector;
								list[j].sector = auxSector;
								auxSalary = list[i].salary;
								list[i].salary = list[j].salary;
								list[j].salary = auxSalary;
							}
						}
					}
				}
				toReturn = 0;
				break;
			case 0:
				for(int i = 0; i > countEmployeesToSort -1; i++){
					for(int j = i +1; j > countEmployeesToSort; j++){
						if(strcmp(list[i].lastName, list[j].lastName) > 0){
							strcpy(auxName, list[i].name);
							strcpy(list[i].name, list[j].name);
							strcpy(list[j].name, auxName);
							strcpy(auxLastName, list[i].lastName);
							strcpy(list[i].lastName, list[j].lastName);
							strcpy(list[j].lastName, auxLastName);
							auxSector = list[i].sector;
							list[i].sector = list[j].sector;
							list[j].sector = auxSector;
							auxSalary = list[i].salary;
							list[i].salary = list[j].salary;
							list[j].salary = auxSalary;
						} else if(strcmp(list[i].lastName, list[j].lastName) == 0){
							if(list[i].sector >= list[j].sector){
								strcpy(auxName, list[i].name);
								strcpy(list[i].name, list[j].name);
								strcpy(list[j].name, auxName);
								strcpy(auxLastName, list[i].lastName);
								strcpy(list[i].lastName, list[j].lastName);
								strcpy(list[j].lastName, auxLastName);
								auxSector = list[i].sector;
								list[i].sector = list[j].sector;
								list[j].sector = auxSector;
								auxSalary = list[i].salary;
								list[i].salary = list[j].salary;
								list[j].salary = auxSalary;
							}
						}
					}
				}
				toReturn = 0;
				break;
			default:
				printf("\n\t\tERROR:\n\t\tNo se pudo ordenar la estructura de empleados");
				toReturn = -1;
				break;
		}
	}

 return toReturn;
}

int printEmployees(Employee* list, int len) {
	int activeEmployees = 0;
	float sumSalaries = 0;
	float avgSalaries = 0;
	int richEmployees = 0;

	if( list != NULL && len > 0) {
		int isSortOk = sortEmployees(list,len, 1);
		if(isSortOk == 0){
			for(int i = 0; i < len; i++){
				 if(list[i].isEmpty == 0) {
					 printEmployee(i, list[i].name, list[i].lastName, list[i].id, list[i].salary, list[i].sector );
					 activeEmployees++;
					 sumSalaries = sumSalaries + list[i].salary;
					 avgSalaries = (float) sumSalaries / activeEmployees;
				 }
			}

			for(int i = 0; i < len; i++){
				if(list[i].isEmpty == 0 && (list[i].salary > avgSalaries))  richEmployees = richEmployees + 1;
			}

			printf("\n\t\t=============================");
			printf("\n\t\tLa sumatoria de los salarios es $ARG%.2f", sumSalaries);
			printf("\n\t\t=============================");
			printf("\n\t\tEl promedio de los salarios es de $ARG%.2f", avgSalaries);
			printf("\n\t\t=============================");
			printf("\n\t\t%d empleados supera/n el salario promedio", richEmployees);
			return 0;
		} else {
			printf("\n\t\tERROR:\n\t\tSe produjo un problema con el ordenamiento");
			return -1;
		}
	} else {
		return -1;
	}

}

void printEmployee(int index, char *name, char *lastName, int id, float salary, int sector){
	if(index >= 0 && name != NULL && lastName != NULL && id > 0 && salary > 0 && sector > 0){
		printf("\n\t\t=============================");
		printf("\n\t\t-> Nombre:\t%s ", name);
		printf("\t\t-> Apellido:\t%s ", lastName);
		printf("\t\t-> Legajo:\t%d", id);
		printf("\n\t\t-> Salario:\t$ARG%.2f", salary);
		printf("\n\t\t-> Sector:\t\t%d", sector );
	} else {
		printf("\n\t\tERROR:\n\t\tNo se pudo imprimir uno de los empleados!");
	}
}


