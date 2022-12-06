#include "Exception.h"

Exception::Exception(ExceptionType _type, string _description) {
    type = _type;
    description = _description;
}

ExceptionType Exception::getType() {
    return type;
}

string Exception::getDescription() {
    return description;
};