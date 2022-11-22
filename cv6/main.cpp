#include <iostream>
#include "StringHelper.h"
using namespace std;

int main() {
    char* stre = "test";
    StringHelper str(stre, 4);
    cout << "string: " << str.getValue() << endl;
    return 0;
}
