#include <stdlib.h>

#include "graph.h"

Graph NewGraph(int x) {
  Graph g;
  g.first = NULL;
  CreateGraph(x, &g);
  return g;
}

void CreateGraph(int x, Graph *g) {
  AdrNode node = newGraphNode(x);
  if (node != NULL) {
    g->first = node;
  } else {
    g->first = NULL;
  }
}

AdrNode newGraphNode(int x) {
  AdrNode p = (AdrNode)malloc(sizeof(GraphNode));
  if (p != NULL) {
    ID(p) = x;
    NPRED(p) = 0;
    TRAIL(p) = NULL;
    NEXT(p) = NULL;
  }
  return p;
}

void deallocGraphNode(AdrNode p) { free(p); }

AdrAdjNode newAdjNode(int succId) {
  AdrAdjNode p = (AdrAdjNode)malloc(sizeof(GraphAdjNode));
  if (p != NULL) {
    SUCC_ID(p) = succId;
    NEXTSUCC(p) = NULL;
  }
  return p;
}

void deallocAdjNode(AdrAdjNode p) { free(p); }

AdrNode searchNode(Graph g, int x) {
  AdrNode p = g.first;
  while (p != NULL && ID(p) != x) {
    p = NEXT(p);
  }
  return p;
}

AdrAdjNode searchEdge(Graph g, int prec, int succ) {
  AdrNode p = searchNode(g, prec);
  if (p == NULL) {
    return NULL;
  }

  AdrAdjNode adj = TRAIL(p);
  while (adj != NULL) {
    if (SUCC_ID(adj) == succ) {
      return adj;
    }
    adj = NEXTSUCC(adj);
  }

  return NULL;
}

void insertNode(Graph *g, int x, AdrNode *pn) {
  AdrNode newNode = newGraphNode(x);
  *pn = newNode;

  if (newNode == NULL) {
    return;
  }

  if (g->first == NULL) {
    g->first = newNode;
    return;
  }

  AdrNode last = g->first;
  while (NEXT(last) != NULL) {
    last = NEXT(last);
  }
  NEXT(last) = newNode;
}

void insertEdge(Graph *g, int prec, int succ) {
  AdrNode precNode = searchNode(*g, prec);
  if (precNode == NULL) {
    insertNode(g, prec, &precNode);
    if (precNode == NULL) {
      return;
    }
  }

  AdrNode succNode = searchNode(*g, succ);
  if (succNode == NULL) {
    insertNode(g, succ, &succNode);
    if (succNode == NULL) {
      return;
    }
  }

  if (searchEdge(*g, prec, succ) != NULL) {
    return;
  }

  AdrAdjNode adj = newAdjNode(succ);
  if (adj == NULL) {
    return;
  }

  if (TRAIL(precNode) == NULL) {
    TRAIL(precNode) = adj;
  } else {
    AdrAdjNode last = TRAIL(precNode);
    while (NEXTSUCC(last) != NULL) {
      last = NEXTSUCC(last);
    }
    NEXTSUCC(last) = adj;
  }

  NPRED(succNode)++;
}

void deleteNode(Graph *g, int x) {
  AdrNode prev = NULL;
  AdrNode curr = g->first;
  while (curr != NULL && ID(curr) != x) {
    prev = curr;
    curr = NEXT(curr);
  }

  if (curr == NULL) {
    return;
  }

  AdrNode node = g->first;
  while (node != NULL) {
    AdrAdjNode prevAdj = NULL;
    AdrAdjNode adjToCheck = TRAIL(node);
    while (adjToCheck != NULL) {
      if (SUCC_ID(adjToCheck) == x) {
        AdrAdjNode toDelete = adjToCheck;
        adjToCheck = NEXTSUCC(adjToCheck);
        if (prevAdj == NULL) {
          TRAIL(node) = adjToCheck;
        } else {
          NEXTSUCC(prevAdj) = adjToCheck;
        }
        deallocAdjNode(toDelete);
      } else {
        prevAdj = adjToCheck;
        adjToCheck = NEXTSUCC(adjToCheck);
      }
    }
    node = NEXT(node);
  }

  AdrAdjNode adj = TRAIL(curr);
  while (adj != NULL) {
    AdrNode succNode = searchNode(*g, SUCC_ID(adj));
    if (succNode != NULL) {
      NPRED(succNode)--;
    }
    AdrAdjNode toDelete = adj;
    adj = NEXTSUCC(adj);
    deallocAdjNode(toDelete);
  }
  TRAIL(curr) = NULL;

  if (prev == NULL) {
    g->first = NEXT(curr);
  } else {
    NEXT(prev) = NEXT(curr);
  }

  deallocGraphNode(curr);
}
