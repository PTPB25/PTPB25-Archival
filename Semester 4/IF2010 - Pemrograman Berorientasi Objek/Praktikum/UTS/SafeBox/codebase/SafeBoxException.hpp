#ifndef SAFE_BOX_EXCEPTION_HPP
#define SAFE_BOX_EXCEPTION_HPP

#include <exception>
#include <string>
#include <sstream>
using namespace std;

// Base class untuk semua exception SafeBox.
// Turunan dari std::exception override what() di setiap subclass.
class SafeBoxException : public exception {
public:
    // TODO: deklarasikan what() sebagai pure virtual
};


class BoxFullException : public SafeBoxException {
public:
    // TODO: konstruktor menerima kapasitas (int)
    // TODO: implementasi what() -> "Box penuh: kapasitas maks N"
};


class BoxEmptyException : public SafeBoxException {
public:
    // TODO: implementasi what() -> "Box kosong"
};


// Template: item yang tidak valid dapat bertipe apa saja (int, string, dll.)
// Gunakan ostringstream untuk mengonversi T ke string di dalam what().
// Contoh penggunaan ostringstream:
// int x = 42;
// ostringstream oss;
// oss << "Nilai x: " << x;
// string msg = oss.str(); // msg = "Nilai x: 42"
template<typename T>
class InvalidItemException : public SafeBoxException {
public:
    // TODO: konstruktor menerima item (const T&)
    // TODO: implementasi what() -> "Item tidak valid: <item>"
};

#endif
