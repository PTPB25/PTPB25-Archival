#include "map.h"
#include <stdio.h>

Map *create_map(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }
    Map *map = (Map *)malloc(sizeof(Map));
    if (map == NULL) {
        return NULL;
    }
    map->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);
    if (map->entries == NULL) {
        free(map);
        return NULL;
    }
    map->capacity = capacity;
    map->size = 0;
    return map;
}

bool map_insert(Map *map, int key, const char *value) {
    if (map == NULL || value == NULL) {
        return false;
    } 
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            free(map->entries[i].value);
            map->entries[i].value = strdup(value);
            return map->entries[i].value != NULL;
        }
    }
    if (map->size >= map->capacity) {
        return false;
    }
    map->entries[map->size].key = key;
    map->entries[map->size].value = strdup(value);
    if (map->entries[map->size].value == NULL) {
        return false;
    }
    map->size++;
    return true;
}

char *map_get(const Map *map, int key) {
    if (map == NULL) {
        return NULL;
    }
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return NULL;
}

bool map_delete(Map *map, int key) {
    if (map == NULL) {
        return false;
    }
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            free(map->entries[i].value);
            for (int j = i; j < map->size - 1; j++) {
                map->entries[j] = map->entries[j + 1];
            }
            map->size--;
            return true;
        }
    }
    return false;
}

int map_size(const Map *map) {
    if (map == NULL) {
        return 0;
    }
    return map->size;
}

bool map_contains_key(const Map *map, int key) {
    if (map == NULL) {
        return false;
    }
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return true;
        }
    }

    return false;
}