/**
 * 
 * 1. ¿Que hace el siguiente segmento de codigo si invocamos la funcion func con un 0?
 * 2. De haber algun problema ¿Podrıas decir la lınea en la que se encuentra?
 * 3. Crea un fichero con un main y ejecuta el segmento de codigo.
 * 4. Propon una solucion al ejemplo que cumpla con las normal del CMU
 * 5. Realiza un analisis estatico del codigo erroneo y copia en tu solucion el resultado.
 * Utiliza las herramientas:
 *   (a) rats
 *   (b) cppchecker
 *   (c) splint
 *   (d) vera++
 *   (e) valgrind
*/

/**
 *  DCL41-C. Do not declare variables inside a switch statement before the first case label
 * 
 *  PROBLEM: If we declare variables, initialize them before the first case statement
 *  ant try to use them inside of the case statement, they will have scope inside the
 *  switch but will not be initialized and will contain indeterminated values.
 * 
 *  SOLUTION: Declare and initialize variables before the switch and cases.
*/
/**
 * 1. The function func with arg 0 prints a '17' value of i. 
 * But the problem is when case i is different to 0 that returrns an indeterminate value.
 * 
 *  +----------------+----------------+
 *  | Value of expr  | Output         |
 *  +----------------+----------------+
 *  | 0              | 17             |
 *  +----------------+----------------+
 *  | Nonzero        | Indeterminated |
 *  +----------------+----------------+
 * 
 * 2. The problem is in lines 49 and 50 in the declaration and initialization 
 * of the variables inside the switch.
 * 
 * 3. // DONE
 * 
 * 4. The solution is to move the initialization outside of the switch block
 * so the statementes can be executed.
 * 
 * 5.
*/
#include <stdio.h>

extern void f(int i); 

void func(int expr){
    int i = 4;
    f(i);
    
    switch (expr){
        /*
            int i = 4;
            f(i);
        */   
        case 0:
            /* indeterminate values */
            i = 17;
        default:
        printf("%d\n",i);
    }
}

