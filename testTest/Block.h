//
// Created by Adam on 19.12.2022.
//

#ifndef TESTTEST_BLOCK_H
#define TESTTEST_BLOCK_H

#include <string>

class IColorSetter {
public:
    IColorSetter();
    virtual std::string setColor(std::string* content) = 0;

};

class CRedColorSetter: public IColorSetter {
public:
    std::string setColor(std::string* content) override;
};

class CBlueColorSetter: public IColorSetter {
public:
    std::string setColor(std::string* content) override;
};

class Block {
private:
    std::string content;
    IColorSetter* colorSetter;
public:
    Block(std::string content, IColorSetter *colorSetter);
    Block(Block& other);
    Block& operator=(const Block& other);
    std::string getContent();
    void setColor();
    ~Block();

};


#endif //TESTTEST_BLOCK_H
