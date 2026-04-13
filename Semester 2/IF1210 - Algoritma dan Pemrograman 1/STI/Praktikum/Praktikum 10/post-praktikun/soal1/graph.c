#include "graph.h"

/**
 * Inisialisasi graph kosong dengan jumlah simpul tertentu.
 * Semua nilai dalam adjacency matrix akan di-set ke 0 (tidak ada edge).
 *
 * @param g Pointer ke graph yang akan diinisialisasi
 * @param nVertices Jumlah simpul dalam graph
 */
void initGraph(Graph *g, int nVertices){
    g->nVertices = nVertices;
    for(int i = 0; i < nVertices; i++){
        for(int j = 0; j<nVertices; j++){
            g->adjMatrix[i][j] = -1;
        }
    }
}

/**
 * Mengecek apakah simpul (vertex) valid, yaitu berada dalam rentang 0 hingga nVertices-1.
 *
 * @param G Graph yang diperiksa
 * @param v Simpul yang ingin divalidasi
 * @return 1 jika valid, 0 jika tidak
 */
int IsValidVertex(Graph G, int v){
    return (v >= 0) && (v < G.nVertices) ? 1 : 0;
}

/**
 * Menambahkan edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 */
void addEdge(Graph *g, int src, int dest, int weight){
    g->adjMatrix[src][dest] = weight;
    // g->adjMatrix[dest][src] = 1;
}

/**
 * Menghapus edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 */
void removeEdge(Graph *g, int src, int dest, int *weight){
    *weight = g->adjMatrix[src][dest];
    g->adjMatrix[src][dest] = -1;

}

/**
 * Mengecek apakah dua simpul saling terhubung (bersebelahan).
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @return 1 jika terdapat edge dari src ke dest, 0 jika tidak
 */
int isAdjacent(Graph *g, int src, int dest){
    return (g->adjMatrix[src][dest] != -1) ? g->adjMatrix[src][dest] : 0;
}

