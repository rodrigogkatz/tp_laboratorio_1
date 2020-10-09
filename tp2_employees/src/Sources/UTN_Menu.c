#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "../Headers/UTN_Menu.h"
#include "../Headers/UTN_Employees.h"
#include "../Headers/UTN_Validations.h"

void showMenu() {
	setbuf(stdout, NULL);
	int isEmployeeAdded = -1;
	int employeeID = 0;
	Employee aEmployee[QTY_EMPLOYEES];
	initEmployees(aEmployee, QTY_EMPLOYEES);

	do {
		switch (menu()) {
		case 1:
			isEmployeeAdded = addEmployeeMenu(aEmployee, QTY_EMPLOYEES, employeeID);
			if(isEmployeeAdded == 0) employeeID++;
			break;
		case 2:
			isEmployeeAdded == 0 ? modifyEmployeeMenu(aEmployee, QTY_EMPLOYEES) : printf("\n\t\tERROR\n\t\tNo se puede modificar sin agregar empleados\n\n");
			break;
		case 3:
			isEmployeeAdded == 0 ? removeEmployeeMenu(aEmployee, QTY_EMPLOYEES) : printf("\n\t\tERROR\n\t\tNo se puede borrar sin agregar empleados\n\n");
			break;
		case 4:
			isEmployeeAdded == 0 ? printEmployeesMenu(aEmployee, QTY_EMPLOYEES) : printf("\n\t\tERROR\n\t\tNo se puede informar sin agregar empleados\n\n");
			break;
		case 5:
			exitAppMenu();
			break;
		default:
			printf("\n\t\tERROR\n\t\tIngrese una de las opciones numericas que proporciona el menu\n\n");
			break;
		}
	} while (1 == 1);
}

int addEmployeeMenu(Employee* list, int len, int employeeID){
	int sector = 0;
	float salary = 0;
	char name[MAX_STR_SIZE];
	char lastName[MAX_STR_SIZE];
	int additionStatus;

	if( list != NULL && len > 0){
		int isNameOk = utn_getString(name, "Ingrese el nombre del empleado: ", "El nombre debe tener entre 2 y 50 caracteres.\n\t\tIntente nuevamente: ", MIN_STR_SIZE, MAX_STR_SIZE);
		int isLastNameOk = utn_getString(lastName, "Ingrese el apellido del empleado: ", "El apellido es demasiado largo.\n\t\tIntente nuevamente: ", MIN_STR_SIZE, MAX_STR_SIZE);
		int isSectorOk = utn_getNumber(&sector, "\n\t\tIngrese el numero de sector: ", "\n\t\tERROR:\n\t\tEl sector ingresado debe estar comprendido entre 1 y 1000", 1, QTY_EMPLOYEES);
		int isSalaryOk = utn_getFloat(&salary, "\n\t\tIngrese el salario: ", "\n\t\tERROR:\n\t\tEl salario ingresado debe estar comprendido entre $50.000,- y $5.00.000,-", 50000, 5000000);

		if(isNameOk == 0 && isLastNameOk == 0 && isSectorOk == 0 && isSalaryOk == 0){
			additionStatus = addEmployee(list, len, employeeID, name, lastName, salary, sector);
			return additionStatus;
		} else {
			printf("\n\t\tERROR:\n\t\tAlguno de los campos ingresados no es correcto");
			return -1;
		}
	} else {
		return -1;
	}
}

void modifyEmployeeMenu(Employee* list, int len){
	int modificationStatus = -1;
	int idToModify = 0;
	if( list != NULL && len > 0){
		int isIDToModify = utn_getNumber(&idToModify, "\n\t\tIngrese el nro de legajo que desea modificar: ", "\n\t\tERROR:\n\t\tEl legajo ingresado debe estar comprendido entre 1 y 1000", 1, QTY_EMPLOYEES);
		if(isIDToModify == 0 ){
			modificationStatus  = modifyEmployee(list, QTY_EMPLOYEES, idToModify);
		}
		modificationStatus  == 0 ? printf("\n\t\tLegajo Modificado") : printf("\n\t\tNo se modificaron legajos");
	}
}

void removeEmployeeMenu(Employee* list, int len){
	int deletionStatus = -1;
	int idToDelete = 0;
	if( list != NULL && len > 0){
		int isIDToDelete = utn_getNumber(&idToDelete, "\n\t\tIngrese el nro de legajo que desea eliminar: ", "\n\t\tERROR:\n\t\tEl legajo ingresado debe estar comprendido entre 1 y 1000", 1, QTY_EMPLOYEES);
		if(isIDToDelete == 0 ){
			deletionStatus = removeEmployee(list, QTY_EMPLOYEES, idToDelete);
		}
		deletionStatus == 0 ? printf("\n\t\tLegajo Eliminado") : printf("\n\t\tNo se borraron legajos");
	}
}

void printEmployeesMenu(Employee* list, int len){
	if( list != NULL && len > 0){
		int printableStatus = -1;
		printf("\n\t\tREPORTE DE EMPLEADOS");
		printableStatus  = printEmployees(list, len);
		printableStatus  == 0 ? printf("\n\t\t=============================\n\t\tFIN DEL REPORTE") : printf("\n\t\tERROR:\n\t\tNo se puede imprimir el listado de empleados!");
	}
}

int menu() {
	int option = 0;
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tMenu");
	printf("\n\t\t1. ALTA EMPLEADO");
	printf("\n\t\t2. MODIFICAR EMPLEADO");
	printf("\n\t\t3. BAJA EMPLEADO");
	printf("\n\t\t4. INFORME");
	printf("\n\t\t5. SALIR");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &option);
	return option;
}

void exitAppMenu() {
	printf("\n\n------------------------------");
	printf("\nGracias vuelva pronto!");
	exit(0);
}
