#ifndef CV7_INPUTS_H
#define CV7_INPUTS_H
#include <string>

class FormElement {
public:
    virtual std::string getHTML() const = 0;
};

class Input : public FormElement {
public:
    virtual std::string getHTML() const;
};

class Select : public FormElement {
public:
    virtual std::string getHTML() const;
};

class Textarea : public FormElement {
public:
    virtual std::string getHTML() const;
};


#endif //CV7_INPUTS_H
