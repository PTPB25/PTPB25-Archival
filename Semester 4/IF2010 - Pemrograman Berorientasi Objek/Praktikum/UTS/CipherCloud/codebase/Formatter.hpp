#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <string>
#include <iostream>

class Formatter
{
public:
    static void printCtor(const std::string &name)
    {
        std::cout << "[CTOR] Node " << name << " diinisialisasi.\n";
    }
    static void printCCtor(const std::string &name)
    {
        std::cout << "[CCTOR] Backup " << name << " dibuat.\n";
    }
    static void printAssign(const std::string &name)
    {
        std::cout << "[ASSIGN] Node " << name << " disinkronisasi.\n";
    }
    static void printDtor(const std::string &name)
    {
        std::cout << "[DTOR] Node " << name << " dinonaktifkan.\n";
    }
};

#endif
