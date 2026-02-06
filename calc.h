#pragma once
#include "utility.h"

const int maxstack = 50;
typedef double Stack_entry;

class Stack {
public:
    Stack();
    bool empty() const;
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    Error_code push(const Stack_entry &item);
private:
    int count;
    Stack_entry entry[maxstack];
};

char get_command();
bool do_command(char command, Stack &numbers);

