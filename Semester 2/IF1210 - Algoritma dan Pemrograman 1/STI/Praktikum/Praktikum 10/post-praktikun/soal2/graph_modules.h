#ifndef GRAPH_ADJLIST_H
#define GRAPH_ADJLIST_H

#include <stdbool.h>

typedef struct Node {
    int vertex; /**< Nilai vertex. */
    struct Node
        *next; /**< Pointer ke simpul berikutnya dalam adjacency list. */
} Node;

typedef struct {
    int numVertices; /**< Banyak simpul (vertex) dalam graf. */
    Node **adjList;  /**< Array pointer ke daftar adjacency. */
} Graph;

/**
 * @brief Membuat simpul baru untuk daftar adjacency.
 *
 * @param v Nomor vertex untuk simpul baru.
 * @return Pointer ke simpul yang baru dibuat atau NULL jika alokasi gagal;
 */
Node *createNode(int v);

/**
 * @brief Membuat graf dengan jumlah simpul tertentu.
 *
 * @param numVertices Jumlah simpul dalam graf. Vertex yang valid adalah 0
 * sampai numVertices-1.
 * @return Pointer ke graf yang baru dibuat atau NULL jika alokasi graph atau
 * simpul gagal.
 */
Graph *createGraph(int numVertices);

/**
 * @brief Menambahkan sisi (edge) antara dua simpul dalam graf.
 *
 * Vertex yang valid adalah 0 sampai numVertices-1. Jika vertex di luar range
 * tersebut, penambahan edge akan gagal.
 *
 * Vertex baru selalu ditambahkan di akhir adjacency list. Contoh:
 * - Jika addEdge(graph, 0, 1) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1]
 * - Jika addEdge(graph, 0, 2) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1, 2]
 * - Jika addEdge(graph, 0, 3) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1, 2, 3]
 *
 * Jika penambahan gagal: keluarkan output: "Penambahan edge
 * gagal.\n"
 *
 * @param graph Pointer ke graf.
 * @param v1 Simpul pertama (harus dalam range 0 sampai numVertices-1).
 * @param v2 Simpul kedua (harus dalam range 0 sampai numVertices-1).
 */
void addEdge(Graph *graph, int v1, int v2);

/**
 * @brief Membebaskan memori yang dialokasikan untuk graf.
 *
 * @param graph Pointer ke graf yang akan dibebaskan.
 */
void freeGraph(Graph *graph);

/**
 * @brief Mencetak representasi graf dalam bentuk adjacency list.
 * 
 * Fungsi ini akan mencetak setiap vertex dan daftar vertex yang terhubung dengannya.
 * Format output: "vertex: connected_vertex1 -> connected_vertex2 -> ..."
 * Jika vertex tidak memiliki edge, akan mencetak "vertex: Kosong"
 * Jika graph adalah NULL, akan mencetak "Graph is NULL"
 * 
 * @param graph Pointer ke graf yang akan dicetak.
 */
void printGraph(Graph *graph);

/**
 * @brief Menghapus edge antara dua vertex dalam graf.
 * 
 * Fungsi ini akan menghapus edge antara vertex v1 dan v2 dari adjacency list.
 * Karena graf bersifat undirected, edge akan dihapus dari kedua vertex.
 * Jika vertex tidak valid (di luar range 0 sampai numVertices-1) atau
 * edge tidak ditemukan, akan mencetak "Penghapusan edge gagal.\n"
 * 
 * @param graph Pointer ke graf.
 * @param v1 Vertex pertama.
 * @param v2 Vertex kedua.
 */
void deleteEdge(Graph *graph, int v1, int v2);

#endif