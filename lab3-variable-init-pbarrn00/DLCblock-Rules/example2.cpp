/**
 * 1. ¿Que hace el siguiente segmento de codigo?
 * 2. De haber algun problema ¿Podrıas decir la lınea en la que se encuentra?
 * 3. Define la regla que se incumple y propon una alternativa correcta siguiendo el SEI
 * CERT C.
*/
#include <stdlib.h>

struct flexArrayStruct {
    int num;
    int data[1];
};

void func(size_t array_size){
    /* Space is allocated for the struct */
    struct flexArrayStruct *structP
    = (struct flexArrayStruct *)
    malloc(sizeof(struct flexArrayStruct) +
    sizeof(int) * (array_size - 1));

    if (structP == NULL){
        /* Handle malloc failure */
    }
    structP->num = array_size;

    /**
     * Access data[] as if it had been allocated
     * as data[array_size]
    */
    for (size_t i = 0; i < array_size; i++)
    {
        structP->data[i] = 1;
    }
}