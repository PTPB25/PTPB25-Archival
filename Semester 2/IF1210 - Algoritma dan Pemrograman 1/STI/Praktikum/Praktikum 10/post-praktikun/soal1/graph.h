// graph.h
#ifndef ADJ_DIRECTED_GRAPH_H
#define ADJ_DIRECTED_GRAPH_H

#include <stdio.h>

// Maksimum jumlah simpul (vertices) dalam graph
#define MAX_VERTICES 100

/**
 * Struktur data Graph menggunakan adjacency matrix.
 *
 * - Matriks berukuran nVertices x nVertices.
 * - Nilai > 1 pada adjMatrix[i][j] berarti ada edge dari simpul i ke j.
 * - Nilai - berarti tidak ada edge.
 */
typedef struct
{
    int nVertices;                             // Jumlah simpul (vertices) dalam graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Matriks ketetanggaan (adjacency matrix)
} Graph;

/**
 * Inisialisasi graph kosong dengan jumlah simpul tertentu.
 * Semua nilai dalam adjacency matrix akan di-set ke -1 (tidak ada edge).
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
 * Menambahkan edge (sisi) antara dua simpul dalam graf berarah dengan bobot weight.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @param weight Bobot simpul
 */
void addEdge(Graph *g, int src, int dest, int weight);

/**
 * Menghapus edge (sisi) antara dua simpul dalam graf berarah.
 * Note: Mengganti nilai bobot menjadi -1
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @param weight Bobot edge yang dihapus
 */
void removeEdge(Graph *g, int src, int dest, int *weight);

/**
 * Mengecek apakah dua simpul saling terhubung (bersebelahan).
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @return bobot edge jika terdapat edge dari src ke dest, 0 jika tidak
 */
int isAdjacent(Graph *g, int src, int dest);

#endif