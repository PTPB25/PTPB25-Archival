#ifndef CARGO_EXCEPTION_HPP
#define CARGO_EXCEPTION_HPP

#include <exception>
#include <string>

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

#endif
