#ifndef ITEM_HPP
#define ITEM_HPP


template <class T>
class Item {
private:
    static int totalItems;
    int id;
    T data;
    int durability;

public:
    Item();
    Item(T data, int durability);
    int getId() const;
    T getData() const;
    int getDurability() const;

    // TODO Implementasikan Setter Durability
    // Pastikan durability berada pada rentang 0 hingga 100.
    // Di luar itu, set nilai ke batas terdekat (misal -10 jadi 0, 150 jadi 100).
    void setDurability(int newDurability);
};

// TODO Definisikan static variable totalItems
// initial value totalItems adalah 0

// Implementasi di sini (atau langsung di deklarasi methods juga bisa sih)

template <class T>
Item<T>::Item() {
    this->id = 0;
    this->durability = 100;
    this->data = T();
}

template <class T>
Item<T>::Item(T data, int durability) {
    this->id = ++totalItems;
    this->setDurability(durability);
    this->data = data;
}

template <class T>
int Item<T>::getId() const {
    return this->id;
}

template <class T>
T Item<T>::getData() const {
    return this->data;
}

template <class T>
int Item<T>::getDurability() const {
    return this->durability;
}

#endif
