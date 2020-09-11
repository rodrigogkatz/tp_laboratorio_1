#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/**
 * brief funcion que saluda al usuaio que ejecuta el programa
 * param no lleva parametros
 * return  la opcion seleccionada
 **/
void saludar();

/**
 * brief funcion que opera en base a la opcion seleccionada en el menu
 * param no lleva parametros
 * return 1 si esta bien 0 si esta mal
 **/
void operarMenu();

/**
 * brief opcion que ofrece un menu con opciones para elegir
 * param no lleva parametros
 * return 1 si esta bien 0 si esta mal
 **/
int menu();

/**
 * brief opcion del menu para ingresar el primer operando
 * param no lleva parametros
 * return 1 si esta bien 0 si esta mal
 **/
int ingresarOperando();


/**
 * brief opcion del menu para hacer todos los calculos indicados
 * param no lleva parametros
 * return 1 si esta bien 0 si esta mal
 **/
void calcularTodasLasOperaciones();

/**
 * brief calculo la suma entre dos operandos
 * param numero entero
 * param numero entero
 * return entero como  resultado de la sumatoria
 **/
int calcularSumatoria(int primerOperando, int segundoOperando);

/**
 * brief calculo la resta entre dos operandos
 * param numero entero
 * param numero entero
 * return entero como  resultado de la resta
 **/
int calcularDiferencia(int primerOperando, int segundoOperando);

/**
 * brief calculo la division entre dos operandos
 * param numero entero
 * param numero entero
 * return float como  resultado de la division
 **/
float calcularDivision(int primerOperando, int segundoOperando);

/**
 * brief calculo la multiplicacion entre dos operandos
 * param numero entero
 * param numero entero
 * return entero como  resultado de la multiplicacion
 **/
int calcularProducto(int primerOperando, int segundoOperando);

/**
 * brief calculo el factorial de un numero entero
 * param numero entero
 * return entero como  resultado del factorial
 **/
long int calcularFactorial(int operando);


/**
 * brief opcion  del menu para informar todos los resultados
 * param  primer operando
 * param  segundo  operando
 * param  resultado de la suma entre dos operandos
 * param  resultado de la resta entre dos operandos
 * param  resultado de la division entre dos operandos
 * param  resultado de la multiplicacion entre dos operandos
 * param  resultado del factoria del primer operando
 * param  resultado del factoria del primer operando
 * return no retorna, imprime los resultados
 **/
void informarResultados(int primerOperando, int segundoOperando, int suma, int resta, float division, int producto, int factorial1erOpe, int factorial2doOpe);

/**
 * brief opcion del menu para salir del programa
 * param no lleva parametros
 * return retorna el caracter 's'
 **/
void salir();

#endif /* CALCULADORA_H_ */
