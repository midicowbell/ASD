// Copyright 2024 Marina Usova

#include <stdexcept>
#include "../lib_easy_example/easy_example.h"
#include "algorithms.h"
#include "stack.h"
#include <iostream>

bool check_brackets(std::string str) {
    Stack<char> Breck(str.size());
    for (int i = 0; i < str.size(); i++) {
        char curr = str[i];
        if (curr == '(' || curr == '{' || curr == '[') {
            Breck.push(curr);
        }
        else if (curr == ')' || curr == '}' || curr == ']') {
            if (Breck.is_empty()) {
                return false;
            }
            char temp = Breck.top();
            Breck.pop();
            if ((temp != '(' && curr == ')') ||
                (temp != '[' && curr == ']') ||
                (temp != '{' && curr == '}')) {
                return false;
            }
        }
    }
    return Breck.is_empty();
}