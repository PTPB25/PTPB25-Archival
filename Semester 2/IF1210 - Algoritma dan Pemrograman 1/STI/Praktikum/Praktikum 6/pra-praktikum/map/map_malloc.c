#include "map.h"
#include <stdio.h>

char *_strdup(const char *s) {
    char *copy = malloc(strlen(s) + 1);
    if (copy) strcpy(copy, s);
    return copy;
}

Map *create_map(int capacity){
    if(capacity <= 0) return NULL;

    Map *map = malloc(sizeof(Map));

    map->entries = malloc(sizeof(MapEntry) * capacity);
    if (!map->entries) {
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size = 0;
    return map;
}

bool map_insert(Map *map, int key, const char *value){
    //Checl mem alloc
    if (!map || !value || map->size >= map->capacity) return false;

    //update
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            free(map->entries[i].value); 
            map->entries[i].value = _strdup(value); // Allocate new copy
            return true;
        }
    }

    map->entries[map->size].key = key;
    map->entries[map->size].value = _strdup(value); // _strdup allocates memory
    if (!map->entries[map->size].value) return false;
    map->size++;
    return true;    
}

char *map_get(const Map *map, int key){
    for(int i = 0; i<map->size; i++){
        if(map->entries[i].key == key){
            return map->entries[i].value;
        }
    }
    return NULL;
}

bool map_delete(Map *map, int key) {
    if (!map) return false;

    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            free(map->entries[i].value);
            //geser
            for (int j = i; j < map->size - 1; j++) {
                map->entries[j] = map->entries[j + 1];
            }
            map->size--;
            return true;
        }
    }
    return false;
}


int map_size(const Map *map){
    return map->size;
}

bool map_contains_key(const Map *map, int key){
    for(int i = 0; i<map->size; i++){
        if(map->entries[i].key == key){
            return true;
        }
    }
    return false;
}