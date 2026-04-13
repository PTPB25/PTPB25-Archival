#include "hashmap.h"

int main() {
    HashMap M;
    CreateEmpty(&M); // init with undefined values
    Insert(&M, 1, 2); // map, key, value
    Insert(&M, 2, 3);
    Insert(&M, 3, 4);
    Insert(&M, 123, 123);
    printf("%d\n", Value(M, 1)); // get value with key 1
    printf("%d\n", Value(M, 2));
    printHashMap(M); // print all elements in the map

    return 0;
}