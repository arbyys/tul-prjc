#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int* createAndFill(int size) {
    int *start = (int *)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++){
        start[i] = i;
    }

    return start;

}

int** duplicateAndCopy(int* start, int size) {
    int** new = (int **)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++){
        new[i] = &start[abs(size-i)-1];
    }
    return new;
}

int areArraysSame(int* first, int** second, int size) {
    for (int i = 0; i < size; i++) {
        if (*first == **second) {
            return 1;
        }
        first += 1;
        second += 1;
    }
    return 0;
}

int** allocate2DArray(int x, int y) {
    int** arr = (int**) malloc(x * sizeof(int*));
    for(int i = 0; i < x; i++) {
        arr[i] = (int*)malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("i, j: %d %d\n", i, j);
            arr[i][j] = 11;
        }
    }

    return arr;
}

typedef struct {
    int age;
    char* name;
} GUY;

void fillWithGuys(GUY* guys, int size){
    GUY currentGuy;
    currentGuy.name = "guy";
    currentGuy.age = size+10;
    for(int i = 0; i < size; i++){
        guys[i] = currentGuy;
    }
}

int main() {
    GUY* guys = (GUY*) malloc(SIZE * sizeof(GUY));

    fillWithGuys(guys, SIZE);

    for (int i = 0; i < SIZE; ++i) {
        printf("name: %s, age: %d\n", guys[i].name, guys[i].age);
    }

    return 0;
}
