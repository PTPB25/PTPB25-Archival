/* File : graph.h */
/* ADT Graph berarah yang direpresentasikan dengan adjacency list */
/* Representasi simpul dan successor menggunakan pointer */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"

/* Selektor simpul */
#define ID(p) (p)->id
#define NPRED(p) (p)->nPred
#define TRAIL(p) (p)->trail
#define NEXT(p) (p)->next

/* Selektor adjacency */
#define SUCC_ID(p) (p)->succId
#define NEXTSUCC(p) (p)->next

typedef struct graphNode *AdrNode;
typedef struct graphAdjNode *AdrAdjNode;

typedef struct graphNode {
  int id;
  int nPred;
  AdrAdjNode trail; /* adjacency list (successors) */
  AdrNode next;     /* next vertex in leader list */
} GraphNode;

typedef struct graphAdjNode {
  int succId;
  AdrAdjNode next;
} GraphAdjNode;

/* Definisi Graph: first menyimpan address simpul pertama */
typedef struct {
  AdrNode first;
} Graph;

Graph NewGraph(int x);
/* Menghasilkan Graph dengan satu simpul ber-id x jika alokasi berhasil.
   Menghasilkan Graph kosong jika alokasi gagal. */

void CreateGraph(int x, Graph *g);
/* I.S. Sembarang
   F.S. Terbentuk Graph dengan satu simpul dengan Id = x */

AdrNode newGraphNode(int x);
/* Mengembalikan address hasil alokasi simpul x.
   Jika alokasi berhasil, maka address tidak NULL, misalnya menghasilkan p,
   maka p↑.id = x, p↑.nPred = 0, p↑.trail = NULL, dan p↑.next = NULL.
   Jika alokasi gagal, mengembalikan NULL. */

void deallocGraphNode(AdrNode p);
/* I.S. p terdefinisi
   F.S. p terdealokasi */

AdrAdjNode newAdjNode(int succId);
/* Mengembalikan address hasil alokasi adjacency.
   Jika alokasi berhasil, maka address tidak NULL, misalnya menghasilkan pt,
   maka pt↑.succId = succId dan pt↑.next = NULL.
   Jika alokasi gagal, mengembalikan NULL. */

void deallocAdjNode(AdrAdjNode p);
/* I.S. p terdefinisi
   F.S. p terdealokasi */

AdrNode searchNode(Graph g, int x);
/* Mengembalikan address simpul dengan id = x jika sudah ada pada graph g,
   NULL jika belum */

AdrAdjNode searchEdge(Graph g, int prec, int succ);
/* Mengembalikan address adjacency yang menyimpan info edge <prec, succ>
   jika sudah ada pada graph g, NULL jika belum */

void insertNode(Graph *g, int x, AdrNode *pn);
/* Menambahkan simpul x ke dalam graph g, jika alokasi x berhasil.
   I.S. g terdefinisi, x terdefinisi dan belum ada pada g.
   F.S. Jika alokasi berhasil, x menjadi elemen terakhir g, pn berisi address
   simpul x. Jika alokasi gagal, g tetap, pn berisi NULL. */

void insertEdge(Graph *g, int prec, int succ);
/* Menambahkan edge dari prec menuju succ ke dalam g.
   I.S. g, prec, succ terdefinisi.
   F.S. Jika belum ada edge <prec, succ> di g, maka tambahkan edge <prec, succ>
   ke g (NPRED(succ) otomatis bertambah). Jika simpul prec/succ belum ada pada g,
   tambahkan simpul tersebut dahulu. Jika sudah ada edge <prec, succ> di g,
   maka g tetap. */

void deleteNode(Graph *g, int x);
/* Menghapus simpul x dari g.
   I.S. g terdefinisi, x terdefinisi dan ada pada g, jumlah simpul pada g
   lebih dari 1.
   F.S. Simpul x dan semua edge yang terhubung ke x dihapus dari g. */

#endif
