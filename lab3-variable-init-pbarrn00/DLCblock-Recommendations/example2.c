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
#include <stdio.h>
#include <stdlib.h>

unsigned long long int factorial(unsigned int i){

    if(i <= 1){
        return 1;
    }
    return i * factorial(i-1);
}

int main(int argc, char const *argv[])
{
    int i = 12, j = 3, f = 0;

    if (argc==1){
        printf("Factorial of %d is %11d\n", i, factorial(i));
    } else {
        j=atoi(argv[1]);
        for ( f = 0; f < j; f++)
        {
            printf("Factorial of %d is %11d\n", f, factorial(f));
        }
        
    }
    return 0;
}
