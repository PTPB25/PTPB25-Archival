#include "graphMultiList.h"

int main() {
    Graph G;
    CreateGraph(1, &G);
    AdrNode Temp;
    insertNode(&G, 2, &Temp);

    insertEdge(&G, 1, 2);
    insertEdge(&G, 1, 3);
    insertEdge(&G, 2, 3);
    insertEdge(&G, 4, 3);
    insertEdge(&G, 5, 2);
    insertEdge(&G, 5, 3);
    insertEdge(&G, 4, 2);
    insertEdge(&G, 3, 4);
    insertEdge(&G, 3, 5);
    
    insertNode(&G, 10, &Temp);
    
    insertEdge(&G, 5, 4);

    printf("Graph saat ini:\n");
    printGraph(G);
    
    deleteNode(&G, 5);
    
    printf("Graph saat ini:\n");
    printGraph(G);
    
    deleteNode(&G, 5);
    
    printf("Graph saat ini:\n");
    printGraph(G);

    deleteNode(&G, 3);
    
    printf("Graph saat ini:\n");
    printGraph(G);

    deleteNode(&G, 3);
    
    printf("Graph saat ini:\n");
    printGraph(G);
    return 0;
}