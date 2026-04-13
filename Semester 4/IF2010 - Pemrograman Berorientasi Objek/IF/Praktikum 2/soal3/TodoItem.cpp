#include "TodoItem.hpp"
#include <iostream>

TodoItem::TodoItem(const std::string& name): Activity(name), isDone(false){}
    
int TodoItem::complete() {
    if(!isDone) {
        isDone = true;
        return 10;
    }
    else {
        return 0;
    }
}
std::string TodoItem::getStatus() const {
    if(isDone) {
        return "[TODO] " + name + " - Selesai";
    }
    else {
        return "[TODO] " + name + " - Belum";
    } 
}

TodoItem::~TodoItem() {
    std::cout << "Menghapus TodoItem " << name << "\n";
}