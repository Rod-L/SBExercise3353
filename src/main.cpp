#include <iostream>
#include "IntFloatStringDB.h"

enum ValueType{
    INT,
    DOUBLE,
    STRING
};

ValueType choose_value_type(std::string& input) {
    if (input.length() == 0) return ValueType::STRING;
    for (char c : input) {
        if (!std::isdigit(c) && c != '-' & c != '.') return ValueType::STRING;
    }
    if (input.find('.') < std::string::npos) return ValueType::DOUBLE;
    return ValueType::INT;
}

#define TYPE_SELECTION(VALUE_VAR, KEY_NAME, METHOD) \
    ValueType type = choose_value_type(VALUE_VAR);\
    switch(type) {\
        case INT: {\
            int (KEY_NAME) = std::stoi(VALUE_VAR);\
            METHOD;\
            break;\
        }\
        case DOUBLE: {\
            double (KEY_NAME) = std::stod(VALUE_VAR);\
            METHOD;\
            break;\
        }\
        case STRING: {\
            std::string& (KEY_NAME) = VALUE_VAR;\
            METHOD;\
            break;\
        }\
    }

int main() {
    while (true) {
        std::cout << "Enter command:" << std::endl;
        std::string command;
        std::cin >> command;

        if (command == "exit") return 0;

        if (command == "print") {
            print();
        } else if (command == "add") {
            std::cout << "Enter key and value you would like to add to database." << std::endl;
            std::string inKey, inValue;
            std::cin >> inKey >> inValue;
            TYPE_SELECTION(inKey, key, TYPE_SELECTION(inValue, value, add_pair(key, value));)
        } else if (command == "remove") {
            std::cout << "Enter key which you would like to remove from database:" << std::endl;
            std::string input;
            std::cin >> input;
            TYPE_SELECTION(input, key, remove_key(key))
        } else if (command == "find") {
            std::cout << "Enter key which you would like to find in database:" << std::endl;
            std::string input;
            std::cin >> input;
            TYPE_SELECTION(input, key, find_pairs(key))
        } else {
            std::cout << "Unknown command. Repeat input." << std::endl;
        }
    }
}
