#include "graph_modules.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  

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
void printGraph(Graph *graph){
    if(graph == NULL){
        printf("Graph is NULL\n");
        return;
    }
    

    for(int i = 0; i < graph->numVertices; i++){
        printf("%d: ",i);
        Node *traversal = graph->adjList[i];
        if(traversal == NULL){
            printf("Kosong");
        }else{
            while(traversal != NULL){
                printf("%d", traversal->vertex);
                if(traversal->next != NULL){
                    printf(" -> ");
                }
                traversal = traversal->next;
            }
        }
        printf("\n");
    }
}

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
void deleteEdge(Graph *graph, int v1, int v2){
    if(graph == NULL || v1 < 0 || v2 < 0 || v1 >= graph->numVertices || v2 >= graph->numVertices){
        printf("Penghapusan edge gagal.\n");
        return;
    }

    bool del1 = false;
    bool del2 = false;

    Node* prevtempEdge = NULL;
    Node* tempedge = graph->adjList[v1];

    while(tempedge != NULL){
        if(tempedge->vertex == v2){
            break;
        }
        prevtempEdge = tempedge;
        tempedge = tempedge->next;
    }

    if (tempedge == NULL) {
        del1 = false;
    } else {
        if (prevtempEdge == NULL) {
            graph->adjList[v1] = tempedge->next;
        }else {
            prevtempEdge->next = tempedge->next;
        }
        free(tempedge);
        del1 = true;
    }



    prevtempEdge = NULL;
    tempedge = graph->adjList[v2];

    while(tempedge != NULL){
        if(tempedge->vertex == v1){
            break;
        }
        prevtempEdge = tempedge;
        tempedge = tempedge->next;
    }

    if (tempedge == NULL) {
        del2 = false;
    } else {
        if (prevtempEdge == NULL) {
            graph->adjList[v2] = tempedge->next;
        }else {
            prevtempEdge->next = tempedge->next;
        }
        free(tempedge);
        del2 = true;
    }
    
    if(del1 == false || del2 == false){
        printf("Penghapusan edge gagal.\n");
    }
    
}