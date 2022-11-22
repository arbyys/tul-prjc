#include "Inputs.h"
#include <string>


std::string Input::getHTML() const {
    return "<input>Zadej text:</input>\n";
}

std::string Select::getHTML() const {
    return "<select><option>Moznost1</option><option>Moznost2></option></select>\n";
}

std::string Textarea::getHTML() const {
    return "<textarea>Zadej hodne textu:</textarea>\n";
}

