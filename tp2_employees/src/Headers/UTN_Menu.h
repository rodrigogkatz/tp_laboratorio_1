#include "UTN_Employees.h"
#ifndef MENU_H_
#define MENU_H_

/*
 * brief function to show the menu when the app start up
 * param -
 * return void
 **/
void showMenu();

/*
 * brief select option from the menu
 * param -
 * return the integer selected option
 **/
int menu();

/*
 * brief get out of the application
 * param -
 * return void
 **/
void exitAppMenu();

/*
 * brief option from the menu to add an employee
 * param -
 * return 0 ok, -1 error
 **/
int addEmployeeMenu(Employee* list, int len, int employeeID);

/*
 * brief option from the menu to modify an employee
 * param -
 * return 0 ok, -1 error
 **/
void modifyEmployeeMenu(Employee* list, int len);

/*
 * brief option from the menu to remove an employee
 * param -
 * return 0 ok, -1 error
 **/
void removeEmployeeMenu(Employee* list, int len);

/*
 * brief option from the menu to print all employees
 * param -
 * return 0 ok, -1 error
 **/
void printEmployeesMenu(Employee* list, int len);

#endif /* MENU_H_ */
