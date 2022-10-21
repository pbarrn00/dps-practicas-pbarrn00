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

char *funcion1(void){
    char array[10] = "Mi Cadena";
    /* Initialize array */
    return array;
}

void funcion2(void){
    const char c_str[] = "Todo va bien";
    p = c_str;
}

void funcion3(void){
    printf("%c \n", p);
}

int main(void){
    p = funcion1();
    printf("%c \n", p);
    funcion2();
    funcion3();
    printf("%s \n", p);

    return 0;

}