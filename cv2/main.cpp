#include <stdio.h>
#include "module2.h"

int numberMatchesAsciiValue(int number, char character)
{
    return character == number;
}

int main() {
    int result = numberMatchesAsciiValue(65, 'A');
    printf("%d", result);
    return 0;
}
