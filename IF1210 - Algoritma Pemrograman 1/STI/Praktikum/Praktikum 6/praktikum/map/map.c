#define _POSIX_C_SOURCE 200809L
#include "map.h"
#include <stdio.h>
#include <string.h>

Map *create_map(int capacity){
    //capacity selalu > 0, tetapi ada NULL bila kapasitas tidak valid
    if (capacity <= 0) return NULL;

    Map *m =(Map *)malloc(sizeof(Map));
    if(m == NULL) return NULL;

    m->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);
    if(m->entries == NULL) {
        free(m);
        return NULL;
    }
    m->capacity = capacity;
    m->size = 0;
    return m;
}

int binarySearch(const Map *map, int key){
    int start = 0;
    int end = map->size-1;
    while(start <= end){
        int mid = start + (end-start)/2;

        if(map->entries[mid].key == key) return mid;

        if(map->entries[mid].key < key){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}

bool map_insert(Map *map, int key, const char *value){
    //cek ada yang sama
    for(int i = 0; i<map->size ; i++){
        if(map->entries[i].key == key){
            free(map->entries[i].value);
            map->entries[i].value = strdup(value); //malloc, copy
            return map->entries[i].value != NULL;
        }
    }

    if(map->size == map->capacity) return false;

    char *copied = strdup(value);
    if (copied == NULL) return false;

    map->entries[map->size].key = key;
    map->entries[map->size].value = copied;
    map->size++;


    int i = map->size - 1;
    while(i > 0 && map->entries[i].key < map->entries[i-1].key){
        MapEntry temp = map->entries[i];
        map->entries[i] = map->entries[i-1];
        map->entries[i-1] = temp;
        i--;
    }

    // for(int i = map->size -1; i > 0; i--){
    //     if(map->entries[i].key < map->entries[i-1].key){
    //         MapEntry temp = map->entries[i];
    //         map->entries[i] = map->entries[i-1];
    //         map->entries[i-1] = temp;
    //     }else{
    //         break;
    //     }
    // }
    return true;
}

char *map_get(const Map *map, int key) {
    if (map == NULL) return NULL;
    int index = binarySearch(map, key);

    if(index != -1){
        return map->entries[index].value;
    }else{
        return NULL;
    }
}

bool map_delete(Map *map, int key) {
    if (map == NULL) return false;
    int index = binarySearch(map, key);

    if(index != -1){
        free(map->entries[index].value);
        for (int j = index; j < map->size - 1; j++) {
            map->entries[j] = map->entries[j + 1];
        }
        map->size--;
        return true;
    }else{
        return false;
    }
}

int map_size(const Map *map) {
    if (map == NULL) return 0;
    return map->size;
}

bool map_contains_key(const Map *map, int key) {
    if (map == NULL) return false;
    int index = binarySearch(map, key);

    if(index!=-1){
        return true;
    }else{
        return false;
    }
    
}