/**
 * Author: Pablo Javier Barrio Navarro
*/

/**
 * Revisa y evalua la siguiente traza de codigo.
 * Define la regla que se incumple y pro pon una alternativa más adecuada según el SEI CERT C.
*/
#include <stdio.h>
#include <stddef.h>

const char *p;
const char c_str[] = "Todo va bien";

/**
 * DCL30-C. Declare objects with appropriate storage durations
 * 
 * PROBLEM: the function function1 returns a pointer to a character array with automatic storage duration, which is accessible to the caller.
 * 
 * SOLUTION: Depends on the intention. If the intent is to use an array and persist outside of the 
 * scope of the function 1 this can be done by declaring the array in main and passin it as an argument.
*/
const char* funcion1(const char * arr, size_t len){
    /* Initialize array */
    arr = "Mi Cadena";
    return arr;
}

/**
 * Storage Duration
 * 
 * Automatic: The storage for the object is allocated at the beginning of the enclosing code block and deallocated at the end.
 * Static: The storage for the object is allocated when the program begins and deallocated when the program ends.
 * Thread: The storage for the object is allocated when the thread begins and deallocated when the thread ends.
 * Dynamic: The storage for the object is allocated and deallocated upon request by using dynamic memory allocation functions.
*/
/**
 * DCL30-C. Declare objects with appropriate storage durations
 * 
 * PROBLEM: the address of the variable c_str with automatic storage duration 
 * is assigned to the variable p, which has static storage duration.
 * 
 * SOLUTION: 
 * 
 *  (1) Same Storage: p is declared with the same storage duration as c_str,
 *  preventing p from taking on an indeterminate value outside of function2()
 * 
 *  (static) const char *p;
 *  (static) const char c_str[] = "Todo va bien";
 * 
 *  (2) Differing Storage Durations: If it is necessary for p to be defined 
 *  with static storage duration but c_str with a more limited duration,
 *  then p can be set to NULL before c_str is destroyed.
 * 
 *  p = c_str;
 *  / Do something /
 *  p = NULL   (c_str is destroyed)
 * 
*/
void funcion2(void){
    p = c_str;
}

void funcion3(void){
    printf("%c \n", *p);
}

int main(void){
    char array[10];
    p = funcion1(array, sizeof(array) / sizeof(array[0])); /* See this size calculation*/
    printf("%c \n", *p);
    funcion2();
    funcion3();
    printf("%s \n", p);

    return 0;
}