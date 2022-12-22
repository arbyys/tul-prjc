//
// Created by Adam on 19.12.2022.
//

#include "Block.h"

IColorSetter::IColorSetter() = default;

std::string CRedColorSetter::setColor(std::string* content) {
    return "<span style='color: red;'>" + *content + "</span>";
}

std::string CBlueColorSetter::setColor(std::string* content) {
    return "<span style='color: blue;'>" + *content + "</span>";
}

Block::Block(std::string content, IColorSetter *colorSetter){
    this->content = content;
    this->colorSetter = colorSetter;
}

std::string Block::getContent() {
    return content;
}

void Block::setColor() {
    content = colorSetter->setColor(&content);
}

Block& Block::operator=(const Block& other){
    if (this == &other) return *this;
    delete colorSetter;
    this->colorSetter = other.colorSetter;
    this->content = other.content;

}