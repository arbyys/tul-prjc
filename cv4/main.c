#include <malloc.h>
#include <stdio.h>

#define SIZE 4

long* makeArrayDouble(long *p_int, int arraySize) {
    long *new;
    new = (long *)malloc(arraySize*2*sizeof(long));

    for (long i = 0; i < arraySize; i++) {
        new[i] = p_int[i];
        new[arraySize+i] = p_int[i];
    }

    free((void *)p_int);
    p_int = NULL;

    return new;
}

void swapElements(long *p_int, int arraySize) {
    long *p2_int = p_int+arraySize-1;
    for (long i = 0; i < arraySize/2; i++) {
        long temp = *p_int;
        *p_int = *p2_int;
        *p2_int = temp;

        p_int+=1;
        p2_int-=1;
    }
}

int main(){
    long *p_int;
    long *new;
    p_int = (long *)malloc(SIZE*sizeof(long));
    p_int[0] = 1;
    p_int[1] = 2;
    p_int[2] = 3;
    p_int[3] = 4;

    for (long i = 0; i < SIZE; i++) {
        printf("%ld\n", p_int[i]);
    }

    printf("==========\n");

    new = makeArrayDouble(p_int, SIZE);

    for (long i = 0; i < SIZE*2; i++) {
        printf("%ld\n", new[i]);
    }

    printf("==========\n");

    swapElements(new, SIZE*2);

    for (long i = 0; i < SIZE*2; i++) {
        printf("%ld\n", new[i]);
    }

    free((void *)new);
    new = NULL;
    return 0;
}
