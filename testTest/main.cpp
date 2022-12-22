#include <iostream>
#include "Block.h"

using namespace std;

int main() {
    CRedColorSetter* red = new CRedColorSetter();
    Block* block2 = new Block("test textu", red);
    Block* block(block2);
    cout << block->getContent() << endl;
    block->setColor();
    cout << block->getContent() << endl;
}
