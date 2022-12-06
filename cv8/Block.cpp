#include "Block.h"
#include <iostream>

using namespace std;

Block::Block(ExceptionType _type, Block* _next) {
    type = _type;
    next = _next;
}

string Block::handle(Exception e) {
    if (e.getType() == type)
        return "Zachycena vyjimka s popisem: " + e.getDescription();

    if(next == nullptr) {
        throw e;
    }
    return next->handle(e);
}