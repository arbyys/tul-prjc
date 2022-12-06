#include "Exception.h"
#include <iostream>

using namespace std;

#ifndef CV8_BLOCK_H
#define CV8_BLOCK_H


class Block {
public:
    Block* next;
    Block(ExceptionType _type, Block* _next = nullptr);
    string handle(Exception e);
private:
    ExceptionType type;
};


#endif //CV8_BLOCK_H
