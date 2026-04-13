// main.c
#include <stdio.h>
#include "graph.h"
void printGraph(Graph *g)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->nVertices; i++)
    {
        for (int j = 0; j < g->nVertices; j++)
        {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph g;

    // Inisialisasi graph dengan 5 simpul
    initGraph(&g, 5);

    // Tambahkan edge
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 3, 4);

    // Cetak graph
    // printf("graph\n");
    printGraph(&g);

    // Cek ketetanggaan
    printf("Apakah 0 dan 1 bertetangga? %s\n", isAdjacent(&g, 0, 1) ? "Ya" : "Tidak");
    printf("Apakah 2 dan 4 bertetangga? %s\n", isAdjacent(&g, 2, 4) ? "Ya" : "Tidak");

    // Hapus edge dan cetak ulang
    removeEdge(&g, 1, 2);
    printf("\nSetelah menghapus edge antara 1 dan 2:\n");
    printGraph(&g);

    return 0;
}