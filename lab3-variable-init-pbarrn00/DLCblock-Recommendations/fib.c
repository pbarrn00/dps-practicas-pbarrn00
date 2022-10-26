// fib.c
/**
 * ¿Podrıas decir cual es la instruccion que mas tiempo de CPU requiere la siguiente
 * traza de codigo? Adjunta uns captura y describe la razón.
*/

/**
 * Percent│
 *        │
 *        │
 *        │    Desensamblado de la sección .text:
 *        │
 *        │    00010408 <fib>:
 *        │    fib():
 *   2,07 │      push {r4, fp, lr}
 *        │      add  fp, sp, #8
 *        │      sub  sp, sp, #12
 *   8,03 │      str  r0, [fp, #-16]
 *  37,47 │      ldr  r3, [fp, #-16]
 *        │      cmp  r3, #0
 *        │    ↓ bne  24
 *   2,22 │      mov  r3, #0
 *        │    ↓ b    64
 *  12,50 │24:   ldr  r3, [fp, #-16]
 *   0,00 │      cmp  r3, #1
 *        │    ↓ bne  38
 *   2,12 │      mov  r3, #1
 *        │    ↓ b    64
 *   9,91 │38:   ldr  r3, [fp, #-16]
 *        │      sub  r3, r3, #1
 *        │      mov  r0, r3
 *        │    → bl   fib
 *   4,32 │      mov  r4, r0
 *   6,02 │      ldr  r3, [fp, #-16]
 *        │      sub  r3, r3, #2
 *        │      mov  r0, r3
 *        │    → bl   fib
 *   2,46 │      mov  r3, r0
 *        │      add  r3, r4, r3
 *   0,50 │64:   mov  r0, r3
 *   0,00 │      sub  sp, fp, #8
 *  12,38 │      pop  {r4, fp, pc}
 * 
 * 
 *  The instruccion that consume more CPU is ldr  r3, [fp, #-16]
 * 
 *  The load (LDR) instructions are used to load data from memory onto a register into the local stack frame at address fp-16.
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