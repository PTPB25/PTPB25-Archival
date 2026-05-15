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
    int count = 0;
    AdrNode p = g.first;
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

/* Get node ID by index 
 * return -1 if index invalid
 */
int getNodeIdByIndex(Graph g, int index) {
    int i = 0;
    AdrNode p = g.first;
    while (p != NULL) {
        if (i == index)
            return ID(p);
        i++;
        p = NEXT(p);
    }
    return -1;
}

/* Find index of node by ID
 * return -1 if id not found
 */
int findNodeIndex(Graph g, int nodeId) {
    int index = 0;
    AdrNode p = g.first;
    while (p != NULL) {
        if (ID(p) == nodeId)
            return index;
        index++;
        p = NEXT(p);
    }
    return -1;
}

/* Get weight of edge from u to v */
int getEdgeWeight(Graph g, int u, int v) {
    AdrNode node = searchNode(g, u);
    if (node == NULL)
        return -1;

    AdrAdjNode adj = TRAIL(node);
    while (adj != NULL) {
        if (SUCC_ID(adj) == v) {
            return WEIGHT(adj);
        }
        adj = NEXTSUCC(adj);
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
    int parent[MAX_NODES];
    int key[MAX_NODES];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    /* Start from first node */
    key[0] = 0;

    int totalWeight = 0;
    int edgeCount = 0;

    printf("Building MST using Prim's Algorithm (starting from first node):\n");
    printf("----------------------------------------------------------\n");

    for (int step = 0; step < n; step++) {
        int u = -1;
        int minKey = INT_MAX;

        /* Step 4: Cari simpul minimum */
        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        if (parent[u] != -1) {
            int uId = getNodeIdByIndex(g, parent[u]);
            int vId = getNodeIdByIndex(g, u);

            printf("Edge %d: Node %d -- Node %d (weight: %d)\n",
                   ++edgeCount, uId, vId, key[u]);
            totalWeight += key[u];
        }

        /* Step 3: Cari seluruh simpul dari titik yang sudah terjangkau */
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int uId = getNodeIdByIndex(g, u);
                int vId = getNodeIdByIndex(g, v);
                int weight = getEdgeWeight(g, uId, vId);

                /* Step 4 & 5 */
                if (weight != -1 && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
    }

    printf("----------------------------------------------------------\n");
    printf("Total MST Weight: %d\n", totalWeight);
}

int main() {
    Graph g;
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    int firstNode;
    scanf("%d", &firstNode);
    CreateGraph(firstNode, &g);

    for (int i = 1; i < n; i++) {
        int nodeId;
        scanf("%d", &nodeId);
        AdrNode temp;
        insertNode(&g, nodeId, &temp);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        insertEdge(&g, u, v, w);
        insertEdge(&g, v, u, w);
    }

    primMST(g);
    return 0;
}

/*
Step 1: Mulai dari node pertama.
Step 2: Ulangi step 3-5 sampai seluruh node terjangkau.
Step 3: Cari seluruh simpul dari titik-titik yang sudah terjangkau.
Step 4: Cari simpul paling minimum.
Step 5: Tambahkan simpul terpilih ke MST.
Step 6: Selesai. Yeay.



Test Case



Masukan	Keluaran
5
7
0 1 2 3 4
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
Building MST using Prim's Algorithm (starting from first node):
----------------------------------------------------------
Edge 1: Node 0 -- Node 1 (weight: 2)
Edge 2: Node 1 -- Node 2 (weight: 3)
Edge 3: Node 1 -- Node 4 (weight: 5)
Edge 4: Node 0 -- Node 3 (weight: 6)
----------------------------------------------------------
Total MST Weight: 16
6
9
0 1 2 3 4 5
0 1 4
0 2 3
1 2 1
1 3 2
2 3 4
2 4 5
3 4 1
3 5 6
4 5 2
Building MST using Prim's Algorithm (starting from first node):
----------------------------------------------------------
Edge 1: Node 0 -- Node 2 (weight: 3)
Edge 2: Node 2 -- Node 1 (weight: 1)
Edge 3: Node 1 -- Node 3 (weight: 2)
Edge 4: Node 3 -- Node 4 (weight: 1)
Edge 5: Node 4 -- Node 5 (weight: 2)
----------------------------------------------------------
Total MST Weight: 9




Notes:

- apabila ada edge yang memiliki bobot sama, maka pastikan node yang lebih awal yang diutamakan.
*/