#ifndef CARGO_EXCEPTION_HPP
#define CARGO_EXCEPTION_HPP

#include <exception>
#include <string>

using namespace std;

// TODO Implementasikan CargoException (Base)
// CargoException inherit std::exception
// Member: errorCode (int), errorMessage (string).
// Sediakan Constructor, getter, dan override what().
// override what() return errorMessage tapi dalam bentuk C-string (char *)

// TODO Implementasikan CargoFullException (errorCode = 1, errorMessage = "Cargo is full!")
// TODO Implementasikan CargoEmptyException (errorCode = 2, errorMessage = "Cargo is empty!")
// TODO Implementasikan ItemNotFoundException (errorCode = 3, errorMessage = "Item not found!")
// TODO Implementasikan NotEnoughItemsException (errorCode = 4, errorMessage = "Not enough items in cargo!")
// TODO Implementasikan TransferFailedException (errorCode = 5, errorMessage = "Transfer failed due to destination capacity!")

class CargoException : public std::exception {
protected: 
    int errorCode;
    string errorMessage;
public:
    CargoException(const int& errorCode, const string& errorMessage) 
    : errorCode(errorCode), errorMessage(errorMessage) {}
    const char* what() const noexcept override;
    int getErrorCode() const;
};

int CargoException::getErrorCode() const {
    return errorCode;
}

class CargoFullException : public CargoException {
public:
    CargoFullException()
    : CargoException(1, "Cargo is full!") {};
};
class CargoEmptyException : public CargoException {
public:
    CargoEmptyException()
    : CargoException(2, "Cargo is empty!") {};
}; 
class ItemNotFoundException : public CargoException {
public:
    ItemNotFoundException()
    : CargoException(3, "Item not found!") {};
}; 
class NotEnoughItemsException : public CargoException {
public:
    NotEnoughItemsException()
    : CargoException(4, "Not enough items in cargo!") {};
}; 

class TransferFailedException : public CargoException {
public:
    TransferFailedException()
    : CargoException(5, "Transfer failed due to destination capacity!") {};
};

const char* CargoException::what() const noexcept {
    return errorMessage.c_str();
}

#endif
