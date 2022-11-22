#include "StringHelper.h"
#include <iostream>

char* StringHelper::getValue() {
    return value;
}

char* StringHelper::substring(int start, int stop) {
    if (start > stop) {
        return new char[0];
    }
    char *temp = new char[stop-start];
    for (int i = 0; i < length; i++)
    {
        if(i >= start && i <= stop) {
            temp[i] = value[i];
        }
    }
    return temp;
}

void StringHelper::append(char* newString, int newLength) {
    char* tempArray = new char[length+newLength];
    for (int i = 0; i < length; i++)
    {
        tempArray[i] = value[i];
    }
    delete value;
    for (int i = length; i < length+newLength; i++)
    {
        tempArray[i] = newString[i];
    }
    length += newLength;
    value = tempArray;
}

StringHelper::StringHelper(char* _value, int _length): value(_value), length(_length){}

StringHelper::~StringHelper() {
    remove();
}

void StringHelper::remove() {
    value = new char[0];
    length = 0;
    delete value;
}