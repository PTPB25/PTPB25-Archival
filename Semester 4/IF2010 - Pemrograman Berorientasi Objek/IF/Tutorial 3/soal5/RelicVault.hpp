#ifndef RELIC_VAULT_HPP
#define RELIC_VAULT_HPP

#include <iostream>
#include <vector>
#include <stack>
#include "VaultException.hpp"
using namespace std;

class RelicVault {
private:
    stack<string> data;
    size_t cap;
public:
    RelicVault(size_t capacity);
    void push(const string& name);
    string pop();
    string top();
    size_t size();
    size_t capacity();
    bool empty();
};

#endif