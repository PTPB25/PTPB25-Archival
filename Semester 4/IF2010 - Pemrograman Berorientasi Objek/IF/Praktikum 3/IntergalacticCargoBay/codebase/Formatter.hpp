#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <iostream>
#include <string>
#include "CargoException.hpp"
#include "Item.hpp"

class Formatter {
public:
    static void printError(const CargoException& e) {
        std::cout << "[ERROR " << e.getErrorCode() << "] " << e.what() << std::endl;
    }

    template <class T>
    static void printItem(const std::string& prefix, const Item<T>& item) {
        std::cout << prefix << " -> ID: " << item.getId()
                  << " | Data: " << item.getData()
                  << " | Durability: " << item.getDurability() << std::endl;
    }

    static void printMessage(const std::string& msg) {
        std::cout << ">> " << msg << std::endl;
    }
};

#endif
