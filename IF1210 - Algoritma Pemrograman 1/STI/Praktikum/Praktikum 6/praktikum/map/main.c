#include "map.h"
#include <stdio.h>
int main() { 
    Map *map = create_map(5);
    char *nimons[] = {"Kebin", "Stuart", "Dave", "Pop", "Larry", "Mel"};
    for (int i = 0; i <= 5; i++) {
        if (!map_insert(map, i, nimons[i])) {
            printf("Terjadi error ketika memasukkan %s ke bilik %d\n",
                   nimons[i], i);
        }
    }

    for(int i = 0; i < map->size; i++){
        printf("%d%s ",map->entries[i].key, map->entries[i].value);
    }
    printf("\n");

    for (int i = 0; i <= 5; i++) {
        const char *nimon = map_get(map, i);
        if (nimon != NULL) {
            printf("Bilik ke-%d diisi oleh %s\n", i, nimon);
        } else {
            printf("Terjadi error ketika melakukan pengecekan ke bilik %d\n",
                   i);
        }
    }
    if (map_delete(map, 1)) {
        printf("Bilik ke-1 berhasil dikosongkan\n");
    }
    // Mencoba melakukan delete ke key yang sudah dihapus
    if (!map_delete(map, 1)) {
        printf("Terjadi error ketika ingin melakukan pengosongan bilik ke 1\n");
    }
    printf("Ukuran map saat ini %d\n", map_size(map));
    return 0;
}