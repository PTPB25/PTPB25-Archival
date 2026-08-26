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
    virtual const char * what() const noexcept = 0;
    // TODO: deklarasikan what() sebagai pure virtual
};


class BoxFullException : public SafeBoxException {
private:
int capacity;
string message;
public:
    BoxFullException(int cap) : capacity(cap){
        message = "Box penuh: kapasitas maks " + to_string(capacity);
    }
    const char * what() const noexcept override {
        return message.c_str();
    }
    // TODO: konstruktor menerima kapasitas (int)
    // TODO: implementasi what() -> "Box penuh: kapasitas maks N"
};


class BoxEmptyException : public SafeBoxException {
public:
    const char * what() const noexcept override {
        return "Box kosong";
    }
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
private:
    T item;
    string wrongItem;
public:
    InvalidItemException(const T& item) : item(item){
        ostringstream oss;
        oss << "Item tidak valid: " << item;
        wrongItem = oss.str();
    }
    const char * what() const noexcept override {
        return wrongItem.c_str();
    }
    // TODO: konstruktor menerima item (const T&)
    // TODO: implementasi what() -> "Item tidak valid: <item>"
};

#endif
