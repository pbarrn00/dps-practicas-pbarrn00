/**
 * 1. ¿Que hace el siguiente segmento de codigo?
 * 2. De haber algun problema ¿Podrıas decir la lınea en la que se encuentra?
 * 3. Define la regla que se incumple y propon una alternativa correcta siguiendo el SEI
 * CERT C.
*/

/**
 * What are flexible array members? 
 * 
 * Flexible array members are a special type of array in which the last element 
 * of a structure with more than one named member has an incomplete array type;
 * that is, the size of the array is not specified explicitly within the structure.
 * 
 * Flexible array members can be used to produce code with defined behavior. Some restrictions:
 * • The incomplete array type must be the last element within the structure
 * • There cannot be an array of structures that contain a flexible array member.
 * • Structures that contain a flexible array member cannot be used as a member of another structure
 * • The structure must contain at least one named member in addition to the flexible array member.
*/
/**
 * 1. attempts to allocate a flexible array-like member with a one-element array as the final member.
 *  When the structure is instantiated, the size computed for malloc() is modified to account for
 *  the actual size of the dynamic array.
 * 
 * 2. The line that fails is line 32 since being a flexible array member it must be an incomplete array type
 * 
 * 3. DCL38-C. Use the correct syntax when declaring a flexible array member
 * 
*/
#include <stdlib.h>

struct flexArrayStruct {
    int num;
    int data[]; /* This must be incomplete array type*/
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