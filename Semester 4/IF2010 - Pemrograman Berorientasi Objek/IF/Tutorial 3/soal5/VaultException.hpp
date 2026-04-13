#ifndef VAULT_EXCEPTION_HPP
#define VAULT_EXCEPTION_HPP

#include <iostream>
using namespace std;

class VaultException : public exception {
protected:
    int errorCode;
    string errorMessage;
public:
    VaultException(int code, string type);
    int getErrorCode();
    string getErrorMessage();
    virtual const char* what() const noexcept override;
};

class EmptyVaultException : public VaultException {
public:
    EmptyVaultException();
};

class FullVaultException : public VaultException {
private:
    size_t capacity;
public:
    FullVaultException(size_t capacity);
    size_t getCapacity() const;
};

class InvalidRelicException : public VaultException {
private:
    string name;
public:
    InvalidRelicException(string name, int type);
    string getRelicName() const;
};

#endif