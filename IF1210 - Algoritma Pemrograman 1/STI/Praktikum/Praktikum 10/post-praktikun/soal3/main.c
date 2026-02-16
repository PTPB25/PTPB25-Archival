#include <stdio.h>
#include "nimonsgram.h"

int main() {
    Graph G;
    CreateGraph(1, &G);

    insertEdge(&G, 1, 2);
    insertEdge(&G, 1, 3);
    insertEdge(&G, 2, 3);
    insertEdge(&G, 4, 3);
    insertEdge(&G, 5, 2);
    insertEdge(&G, 5, 3);
    insertEdge(&G, 4, 2);
    insertEdge(&G, 3, 4);
    insertEdge(&G, 3, 5);

    printf("Graph saat ini:\n");
    printGraph(G);

    int maxFollower, minFollowing;
    AdrNode npd = findNPD(G, &maxFollower);
    AdrNode misterius = findMisterius(G, &minFollowing);

    printf("\nHasil Analisis:\n");
    if (npd != NIL) {
        printf("Si NPD adalah Nimons %d dengan %d followers.\n", ID(npd), maxFollower);
    } else {
        printf("Tidak ada Nimons NPD.\n");
    }

    if (misterius != NIL) {
        printf("Si Misterius adalah Nimons %d dengan %d following.\n", ID(misterius), minFollowing);
    } else {
        printf("Tidak ada Nimons Misterius.\n");
    }

    return 0;
}