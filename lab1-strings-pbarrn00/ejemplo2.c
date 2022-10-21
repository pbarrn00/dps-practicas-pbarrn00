#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

void optionOne(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
    //OK
}

void optionTwo(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    /**
     * Needs a free. Deallocates the memory region pointed by that pointer.
     */
    free(s);
}

void optionThree(){
    char *s = (char *) malloc(100);
    //free(s);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    /**
     *  Heap use after free on address
     *  Unknown bewaviour
     *
    */
   free(s);
}

void optionFour(){
    //char *s = (char *) malloc(18);
    char *s = (char *) malloc(19);
    strcpy(s,  "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
    /**
     * Does not have in mind the escape character "\0"
     * BUFFER OVERFLOW
    */
}

int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}