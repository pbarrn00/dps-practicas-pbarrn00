/**
 * •Que hace el siguiente segmento de codigo?
 * • Comenta que reglas/recomendaciones se estan rompiendo aquı. Tambien entran
 * reglas pasadas.
 * • Instala la herramienta perf para realizar el profiling de la aplicacion. Se puede
 * instalar con apt.
 * • El programa permite mostrar el codigo desensamblado de la aplicacion, adjunta
 * alguna captura.
 * • ¿Podrıas decir cual es la instruccion que mas tiempo de CPU requiere? Adjunta
 * uns captura y describe la razon.
*/

/**
 * 1. This code segments calculates factorial of a number passed as a parameter to the program
 * If no number is passed as parameter it calculates the factorial of number 12.
 * 
 * 2. 
 *   --> (Line ) INT30-C. Ensure that unsigned integer operations do not wrap.
 *   Unsigned integer operations can wrap if the resulting value cannot be represented by the underlying representation of the integer
 *      
 *      +---------------+----------------+
 *      | Operation     | Wrap           |
 *      +---------------+----------------+
 *      |   *           | Yes            |
 *      +---------------+----------------+
 * 
 *   So when we do the recursive factor in factorial function we can wrap numbers.
 * 
 *   --> (Line )  DCL00-C. Const-qualify immutable objects
 *   Variable i = 12 is immutable in the entire programm so it must be declared as const.
 * 
 *   --> (Line )  DCL01-C. Do not reuse variable names in subscopes
 *   Variable i is called "i" in the main section and has the same name in the subscope of function factorial.
 *   It, must have somer other name like "iter" or "_i"
 * 
 *  --> (Line ) DCL04-C. Do not declare more than one variable per declaration.
 *  We have int i = 12, j = 3, f = 0; but its recommendable to declare and INTIALIZE like this:
 *  int i = 12;
 *  int j = 3;
 *  int f = 0;
 *  
 *  3. perf stat ./example2.o
 *   Factorial of 12 is   479001600
 *
 *   Performance counter stats for './example2.o':
 *
 *             2,36 msec task-clock:u              #    0,504 CPUs utilized          
 *                0      context-switches:u        #    0,000 K/sec                  
 *                0      cpu-migrations:u          #    0,000 K/sec                  
 *               45      page-faults:u             #    0,019 M/sec                  
 *  <not supported>      cycles:u                                                    
 *  <not supported>      instructions:u                                              
 *  <not supported>      branches:u                                                  
 *  <not supported>      branch-misses:u                                             
 *
 *      0,004688328 seconds time elapsed
 *
 *      0,000000000 seconds user
 *      0,005521000 seconds sys
 * 
 *  Percent│      mov   r5, #0
 *    0,06 │      ldr   r3, [fp, #-16]
 *         │      sub   r3, r3, #1
 *         │      mov   r0, r3
 *         │    → bl    factorial
 *   10,05 │      mov   r2, r0
 *         │      mov   r3, r1
 *    0,01 │      mul   r0, r2, r5
 *         │      mul   r1, r4, r3
 *    0,89 │      add   r1, r0, r1
 *         │      umull r2, r3, r4, r2
 *         │      add   r1, r1, r3
 *         │      mov   r3, r1
 *    2,83 │64:   mov   r0, r2
 *         │      mov   r1, r3
 *         │      sub   sp, fp, #12
 *   34,63 │      pop   {r4, r5, fp, pc}

    4. La instruccion que mas tiempo de CPU requiere 	
    
    Restaurar registro de la pila POP. POP carga el registro Rd con un byte de la pila.
    El puntero de pila es incrementado en uno antes del POP.
                                       
*/
#include <stdio.h>
#include <stdlib.h>

unsigned long long int factorial(unsigned int i){

    if(i <= 1){
        return 1;
    }
    return i * factorial(i-1);  //INT30-C
}

int main(int argc, char const *argv[])
{
    int i = 12, j = 3, f = 0; //DCL04-C, DCL00-C, DCL01-C

    if (argc==1){
        printf("Factorial of %d is %11lld\n", i, factorial(i)); //INT31-C ??
    } else {
        j=atoi(argv[1]);
        for ( f = 0; f < j; f++)
        {
            printf("Factorial of %d is %11lld\n", f, factorial(f));
        }
        
    }
    return 0;
}
