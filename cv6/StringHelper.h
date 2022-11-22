
#ifndef CV6_STRINGHELPER_H
#define CV6_STRINGHELPER_H

class StringHelper {
private:
    char* value;
    int length;
public:
    StringHelper(char* _value, int _length);
    ~StringHelper();

    char* getValue();
    char* substring(int start, int stop);
    void append(char* newString, int size);
    void remove();
};

#endif //CV6_STRINGHELPER_H
