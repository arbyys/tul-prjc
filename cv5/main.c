#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char* value;
    char* oldValue;
    //char* history[10];
} stringWithHistory;

void undo(stringWithHistory* string) {

}

void redo(stringWithHistory* string) {

}

void setString(stringWithHistory* string, char* newValue) {
    strcpy(string->oldValue, string->value);
    strcpy(string->value, newValue);
}

void initString(stringWithHistory* string, int size) {
    string->value = (char*)malloc(size*sizeof(char));
    string->oldValue = (char*)malloc(size*sizeof(char));
    strcpy(string->value, "");
}

void editChar(stringWithHistory* string, char newChar, int position) {
    for (int i = 0;; i++) {
        if(string->value[i] == '\0'){
            break;
        }
        if(i == position) {
            strcpy(string->oldValue, string->value);
            string->value[i] = newChar;
        }
    }
}

void alloc(char** array) {
    *array = (char*)malloc(10*sizeof(char));
}

int main() {

    int i = 10;
    char* array;
    alloc(&array);
    return 0;
}

int oldmain() {
    stringWithHistory string;
    initString(&string, 10);
    setString(&string, "Pirko");
    editChar(&string, 'v', -5);
    printf("%s\n", string.value);
    printf("%s\n", string.oldValue);
    //printf("%s\n", string.oldValue);
    return 0;
}
