// graph.h
#ifndef GRAPH_H
#define GRAPH_H

// Maksimum jumlah simpul (vertices) dalam graph
#define MAX_VERTICES 100

/**
 * Struktur data Graph menggunakan adjacency matrix.
 *
 * - Matriks berukuran nVertices x nVertices.
 * - Nilai 1 pada adjMatrix[i][j] berarti ada edge antara simpul i dan j.
 * - Nilai 0 berarti tidak ada edge.
 */
typedef struct
{
    int nVertices;                             // Jumlah simpul (vertices) dalam graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Matriks ketetanggaan (adjacency matrix)
} Graph;

/**
 * Inisialisasi graph kosong dengan jumlah simpul tertentu.
 * Semua nilai dalam adjacency matrix akan di-set ke 0 (tidak ada edge).
 *
 * @param g Pointer ke graph yang akan diinisialisasi
 * @param nVertices Jumlah simpul dalam graph
 */
void initGraph(Graph *g, int nVertices);

/**
 * Mengecek apakah simpul (vertex) valid, yaitu berada dalam rentang 0 hingga nVertices-1.
 *
 * @param G Graph yang diperiksa
 * @param v Simpul yang ingin divalidasi
 * @return 1 jika valid, 0 jika tidak
 */
int IsValidVertex(Graph G, int v);

/**
 * Menambahkan edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 */
void addEdge(Graph *g, int src, int dest);

/**
 * Menghapus edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 */
void removeEdge(Graph *g, int src, int dest);

/**
 * Mengecek apakah dua simpul saling terhubung (bersebelahan).
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @return 1 jika terdapat edge dari src ke dest, 0 jika tidak
 */
int isAdjacent(Graph *g, int src, int dest);

#endif