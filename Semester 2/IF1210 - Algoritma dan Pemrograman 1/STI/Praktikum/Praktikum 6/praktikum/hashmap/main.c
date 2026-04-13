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
    Delete(&M, 123); // delete element with key 123
    printf("%d\n", Value(M, 123));
    printHashMap(M); 
    Delete(&M, 10); // delete element with key 10 (not exist)
    printf("%d\n", Value(M, 10));
    printHashMap(M); 
    Insert(&M, 10, 20); // insert element with key 10
    printf("%d\n", Value(M, 10));
    Insert(&M, 10, 30);
    printf("%d\n", Value(M, 10));
    printHashMap(M);
    Insert(&M, 26, 40); // insert element with key 26 (conflict)
    printf("%d\n", Value(M, 10));
    printf("%d\n", Value(M, 11));
    printf("%d\n", Value(M, 26));
    printHashMap(M);
    Delete(&M, 11); // delete element with key 11
    printf("%d\n", Value(M, 26));
    printHashMap(M);
    Delete(&M, 26); // delete element with key 26
    printf("%d\n", Value(M, 26));
    printHashMap(M);

    return 0;
}