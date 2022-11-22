#include "Inputs.h"

#ifndef CV7_FORM_H
#define CV7_FORM_H


class Form {
public:
    Form();
    std::string getHTML() const;
    bool addElement(FormElement &element);
private:
    int numberOfElements = 20;
    int currentElement = 0;
    FormElement **elements;
};


#endif //CV7_FORM_H
