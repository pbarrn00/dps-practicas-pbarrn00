// fib.c
/**
 * ¿Podrıas decir cual es la instruccion que mas tiempo de CPU requiere la siguiente
 * traza de codigo? Adjunta uns captura y describe la razón.
*/
#include <stdio.h>
#include <stdlib.h>

int fib(int x){
    if(x == 0) return 0;
    else if (x == 1) return 1;
    return fib(x - 1) + fib(x - 2);
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 45; i++)
    {
        printf("%d\n", fib(i));
    }
    
    return 0;
}