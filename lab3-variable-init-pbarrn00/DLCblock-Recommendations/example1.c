/**
 * 
 * • ¿Qué hace el siguiente segmento de código?
 * • ¿Para que se utiliza la variable va_eol?
 * • Incorpora el segmento de código en un programa .c de tal
 * forma que no encontremos ningún warning cuando compilamos en gcc
 * los siguientes parámetros (std=c11). Dado que es C elimina aquellos
 * que no aplican. Escribe en la respuesta los que se ven afectados y son
 * eliminados.
*/
#include <stdarg.h>

enum {va_eol=-1};

unsigned int average(int first, ...){
    unsigned int count = 0;
    unsigned int sum = 0;
    int i = first;
    va_list args;

    va_start(args, first);

    while (i != va_eol)
    {
        sum+= i;
        count++;
        i = va_arg(args, int);
    }

    va_end(args);
    return (count ? (sum /count) : 0);
}