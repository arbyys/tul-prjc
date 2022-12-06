#include <iostream>
#include "Block.h"
#include "Exception.h"

int main() {
    Exception e(divisionByZero, "divize zerem");
    Block b1(divisionByZero);
    Block b2(overflow, &b1);

    try {
        string result = b2.handle(e);
        std::cout << result << std::endl;
    }
    catch(Exception e) {
        std::cout << "Obecna vyjimka s popisem: " << e.getDescription() << std::endl;
    }
    return 0;
}
