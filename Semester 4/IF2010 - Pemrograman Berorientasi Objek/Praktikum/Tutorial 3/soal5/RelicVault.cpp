#include "RelicVault.hpp"

RelicVault::RelicVault(size_t capacity): cap(capacity) {}

void RelicVault::push(const string& name) {
    if(name.size() < 3) throw InvalidRelicException(name, 1);

    char const* digits = "0123456789";
    std::size_t const n = name.find_first_of(digits);
    if(n != string::npos) {
        throw InvalidRelicException(name, 2);
    }

    if(data.size() >= cap) throw FullVaultException(cap);
    
    data.push(name);
}

string RelicVault::pop(){
    if(empty()) throw EmptyVaultException();
    string value = top();
    data.pop();
    return value;
}
string RelicVault::top(){
    if(empty()) throw EmptyVaultException();
    return data.top();
}
size_t RelicVault::size(){
    return data.size();
}
size_t RelicVault::capacity(){
    return cap;
}
bool RelicVault::empty(){
    return data.empty();
}