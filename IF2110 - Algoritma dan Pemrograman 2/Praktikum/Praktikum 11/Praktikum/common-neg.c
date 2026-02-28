#include <stdio.h>
#include "graph.h"

int main(void){

    int n, m;
    scanf("%d %d", &n, &m);

    Graph g;
    g.first = NULL;

    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        insertEdge(&g, a, b);
    }

    scanf("%d %d", &a, &b);

    boolean vis[n+1];
    for(int i = 0; i <= n; i++) vis[i] = false;

    AdrAdjNode curr = TRAIL(searchNode(g, b));
    while(curr){
        vis[SUCC_ID(curr)] = true;
        curr = NEXTSUCC(curr);
    }

    boolean found = false;
    curr = TRAIL(searchNode(g, a));
    while(curr){
        if(vis[SUCC_ID(curr)]){
            if(found) printf(" %d", SUCC_ID(curr));
            else{
                printf("%d", SUCC_ID(curr)); 
                found = true;
            }
        }
        curr = NEXTSUCC(curr);
    }

    if(!found) printf("0");
    putchar('\n');

    return 0;
}