/**
 * 
 * 1. ¿Que hace el siguiente segmento de codigo si invocamos la funcion func con un 0?
 * 2. De haber algun problema ¿Podrıas decir la lınea en la que se encuentra?
 * 3. Crea un fichero con un main y ejecuta el segmento de codigo.
 * 4. Propon una solucion al ejemplo que cumpla con las normal del CMU
 * 5. Realiza un analisis est ́atico del codigo erroneo y copia en tu solucion el resultado.
 * Utiliza las herramientas:
 *   (a) rats
 *   (b) cppchecker
 *   (c) splint
 *   (d) vera++
 *   (e) valgrind
*/
#include <stdio.h>

extern void f(int i);

void func(int expr){
    switch (expr){
        int i = 4;
        f(i);
    
        case 0:
            i = 17;
        default:
        printf("%d\n",i);
    }
}