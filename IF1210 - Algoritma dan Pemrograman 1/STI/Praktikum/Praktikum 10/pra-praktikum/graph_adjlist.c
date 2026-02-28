#include "graph_adjlist.h"
#include <stdio.h>

/**
 * @brief Membuat simpul baru untuk daftar adjacency.
 *
 * @param v Nomor vertex untuk simpul baru.
 * @return Pointer ke simpul yang baru dibuat atau NULL jika alokasi gagal;
 */
Node *createNode(int v){
    Node* new = malloc(sizeof(Node));
    if(new == NULL) return NULL;

    new->vertex = v;
    new->next =NULL;
    return new;
}

/**
 * @brief Membuat graf dengan jumlah simpul tertentu.
 *
 * @param numVertices Jumlah simpul dalam graf. Vertex yang valid adalah 0
 * sampai numVertices-1.
 * @return Pointer ke graf yang baru dibuat atau NULL jika alokasi graph atau
 * simpul gagal.
 */
Graph *createGraph(int numVertices){
    //KAMUS
    //new : Graph
    Graph* new = malloc(sizeof(Graph));
    if(new == NULL) return NULL;

    new->numVertices = numVertices;
    new->adjList = malloc(numVertices * sizeof(Node*));
    for(int i = 0; i < numVertices; i++) {
        new->adjList[i] = NULL;
    }
    return new;
}

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
void addEdge(Graph *graph, int v1, int v2){
    if(graph == NULL) {
        printf("Penambahan edge gagal.\n");
        return;
    }

    if(v1 > graph->numVertices - 1 || v2 > graph->numVertices -1 || v1 < 0 || v2 < 0){
        printf("Penambahan edge gagal.\n");
        return;
    }

    Node* newNode = createNode(v2);
    if(newNode == NULL) {
        printf("Penambahan edge gagal.\n");
        return;
    }

    if(graph->adjList[v1] == NULL){
        graph->adjList[v1] = newNode;
    }else{
        Node* temp = graph->adjList[v1];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node* newNode2 = createNode(v1);
    if(newNode2 == NULL) {
        printf("Penambahan edge gagal.\n");
        return;
    }

    if(graph->adjList[v2] == NULL){
        graph->adjList[v2] = newNode2;
    }else{
        Node* temp = graph->adjList[v2];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode2;
    }
}

/**
 * @brief Membebaskan memori yang dialokasikan untuk graf.
 *
 * @param graph Pointer ke graf yang akan dibebaskan.
 */
void freeGraph(Graph *graph){
    if(graph == NULL) return;

    for(int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjList[i];
        while(current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph->adjList);
    free(graph);
}
