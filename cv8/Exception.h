#ifndef CV8_EXCEPTION_H
#define CV8_EXCEPTION_H
#include <iostream>

using namespace std;

enum ExceptionType { overflow, divisionByZero, notNull };

class Exception {
public:
    Exception(ExceptionType _type, string _description);
    ExceptionType getType();
    string getDescription();
private:
    ExceptionType type;
    string description;
};


#endif //CV8_EXCEPTION_H
