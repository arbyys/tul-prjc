#include <iostream>
#include "Inputs.h"
#include "Form.h"
#include <iostream>

int main() {
    Form f;

    Input i;
    f.addElement(i);
    Input i2;
    f.addElement(i2);
    Input i3;
    f.addElement(i3);
    Select s;
    f.addElement(s);

    std::cout << f.getHTML() << std::endl;

    return 0;
}
