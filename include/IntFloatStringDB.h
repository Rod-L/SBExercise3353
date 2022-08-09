#pragma once

#include <iostream>
#include <vector>

template<typename T1, typename T2>
struct Pair{
    T1 key;
    T2 value;
};

template<typename T1, typename T2>
std::vector<Pair<T1,T2>> database;

template<typename T1, typename T2>
void add_pair(T1 key, T2 value) {
    Pair<T1,T2> pair{.key = key, .value = value};
    database<T1, T2>.push_back(pair);
    std::cout << "Added pair to database: (" << pair.key << ", " << pair.value << ")" << std::endl;
}

template<typename T1, typename T2>
void remove_key_from_branch(T2 key) {
    auto& dict = database<T2, T1>;
    if (dict.empty()) return;
    auto it = dict.end();
    do {
        --it;
        if (it->key == key) {
            std::cout << "Entry '" << it->value << "' with key '" << key << "' have been removed from DB." << std::endl;
            dict.erase(it);
        }
    } while(it != dict.begin());
}

template<typename T>
void remove_key(T key) {
    remove_key_from_branch<int>(key);
    remove_key_from_branch<double>(key);
    remove_key_from_branch<std::string>(key);
}

#define FOR_BRANCH(KEY_TYPE,VALUE_TYPE, CODE) \
for (auto& pair : database<KEY_TYPE,VALUE_TYPE>) {CODE}

#define FOR_FAMILY(TYPE, CODE)\
FOR_BRANCH(TYPE, int, CODE)\
FOR_BRANCH(TYPE, double, CODE)\
FOR_BRANCH(TYPE, std::string, CODE)

#define FOR_DATABASE(CODE)\
FOR_FAMILY(int, CODE)\
FOR_FAMILY(double, CODE)\
FOR_FAMILY(std::string, CODE)

void print() {
    FOR_DATABASE(std::cout << pair.key << " - " << pair.value << std::endl;)
}

template<typename T>
void find_pairs(T key) {
    int count = 0;
    FOR_FAMILY(T, if (pair.key == key) {std::cout << pair.value << std::endl; ++count;})
    std::cout << "Found " << count << " values behind key '" << key << "'." << std::endl;
}
