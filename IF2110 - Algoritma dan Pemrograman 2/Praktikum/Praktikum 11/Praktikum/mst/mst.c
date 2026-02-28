#include "weighted-graph.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int node;
    int weight;
} Edge;

/* Count number of nodes in graph */
int countNodes(Graph g) {

    AdrNode curr = g.first;
    int cnt = 0;
    while(curr){
        cnt++;
        curr = NEXT(curr);
    }
    return cnt;

}


/* Find index of node by ID
 * return -1 if id not found
 */
int findNodeIndex(Graph g, int nodeId) {
    AdrNode curr = g.first;
    int idx = 0;
    while(curr){
        if(ID(curr) == nodeId) return idx;
        curr = NEXT(curr);
        idx++;
    }
    return -1;
}


/* Prim's Algorithm - always starts from first node */
void primMST(Graph g) {
    int n = countNodes(g);
    if (n == 0) {
        printf("Graph is empty!\n");
        return;
    }

    boolean visited[MAX_NODES];

    /* Initialize arrays */
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    /* Start from first node (index 0) */
    visited[0] = true;
    int totalWeight = 0;
    int edgeCount = 0;

    printf("Building MST using Prim's Algorithm (starting from first node):\n");
    printf("----------------------------------------------------------\n");


    while(edgeCount != n-1){

        int mini = INT_MAX, u = -1, v = -1;
        AdrNode iter1 = g.first;
        while(iter1){

            if(visited[findNodeIndex(g, ID(iter1))]){

                AdrAdjNode iter2 = TRAIL(iter1);
                while(iter2){

                    if(SUCC_ID(iter2) != ID(iter1) && !visited[findNodeIndex(g, SUCC_ID(iter2))]){

                        int w = WEIGHT(iter2);
                        if(mini > w){
                            mini = w;
                            u = ID(iter1);
                            v = SUCC_ID(iter2);
                        }
                    }
                    iter2 = NEXTSUCC(iter2);

                }
            }
            iter1 = NEXT(iter1);
            
        }

        printf("Edge %d: Node %d -- Node %d (weight: %d)\n", ++edgeCount, u, v, mini);
        totalWeight += mini;
        visited[findNodeIndex(g, v)] = true;
    }

    printf("----------------------------------------------------------\n");
    printf("Total MST Weight: %d\n", totalWeight);
}

int main() {
    Graph g;
    int n, m;

    // Enter number of nodes
    scanf("%d", &n);

    // Enter number of edges
    scanf("%d", &m);

    /* Create graph with first node */
    // Enter node IDs (space-separated)
    int firstNode;
    scanf("%d", &firstNode);
    CreateGraph(firstNode, &g);

    /* Add remaining nodes */
    for (int i = 1; i < n; i++) {
        int nodeId;
        scanf("%d", &nodeId);
        AdrNode temp;
        insertNode(&g, nodeId, &temp);
    }

    /* Add edges */
    // Enter edges (u v weight)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        insertEdge(&g, u, v, w);
        insertEdge(&g, v, u, w); // For undirected graph
    }

    primMST(g);

    return 0;
}
