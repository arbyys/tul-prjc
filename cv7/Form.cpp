#include "Form.h"

std::string Form::getHTML() const {
    std::string returnString;

    for (int i = 0; i < currentElement; i++) {
        returnString += elements[i]->getHTML();
    }

    return returnString;
}

bool Form::addElement(FormElement &element) {
    if(currentElement >= numberOfElements) {
        return false;
    }
    elements[currentElement++] = &element;
    return true;
}

Form::Form() {
    elements = new FormElement*[numberOfElements];
}