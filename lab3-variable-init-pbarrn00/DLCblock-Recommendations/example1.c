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

/**
 * DCL10-C. Maintain the contract between the writer and caller of variadic functions
*/

/**
 * 1. The code segment is a variadic function that calculates the average value of a list of numbers. It adds elements and increases the counter
 * until it reaches the va_eol variable. When it reaches the va_eol it divide the total sum by the number of elements that were introduced.
 * 
 * 2. va_eol it's like a ending flah that indicates the end of a list of variables. In this case, va_eol = -1  so that as long as i is not that value,
 * it continues adding the elements and increases the counter by 1 but when i is equal to -1 (end of the list) 
 * the loop stops because we have already reached the end of the list.
 * 
 * 3.
 * # ‘-Wctor-dtor-privacy’ is valid for C++/ObjC++ but not for C
 * # ‘-Wnoexcept’ is valid for C++/ObjC++ but not for C
 * # ‘-Wold-style-cast’ is valid for C++/ObjC++ but not for C
 * # ‘-Woverloaded-virtual’ is valid for C++/ObjC++ but not for C
 * # ‘-Wsign-promo’ is valid for C++/ObjC++ but not for C
 * # ‘-Wstrict-null-sentinel’ is valid for C++/ObjC++ but not for C
*/

#include <stdarg.h>
#include <stdio.h>

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

int main(int argc, char const *argv[])
{
    unsigned int output = average(1, 2, 3, 4, 5, va_eol);
    printf("\naverage: %d", output);
    return 0;
}
