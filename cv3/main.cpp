#include <iostream>

void addIntToLong(signed long *pointer, int value) {
    *pointer += value;
}

void getFirstFourBytes(signed long *addr) {
    //printf("%ld\n", addr);
    printf("%n\n", (int*) addr);
    int *p_n = (int*) addr;
    printf("%n\n", p_n);

}

int main() {
    signed long num = 111111111;
    printf("%ld\n", num);
    addIntToLong(&num, 15);
    printf("%ld\n", num);

    getFirstFourBytes(&num);
    return 0;
}
