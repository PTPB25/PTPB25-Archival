#include "graphMultiList.h"
#include <stdio.h>

/* ********* KONSTRUKTOR ********* */
/**
 * @brief Membuat graph dengan satu simpul awal
 * @param x ID simpul pertama
 * @param g Graph yang akan dibentuk
 * I.S. : Sembarang
 * F.S. : Terbentuk graph dengan satu simpul ber-ID x
 * Proses: Alokasi simpul baru dan diset sebagai simpul pertama
 */
void CreateGraph(int x, Graph *g){
    AdrNode new = malloc(sizeof(Node));
    new->id = x;
    new->nPred = 0;
    new->trail = NIL;
    new->next = NIL;
    g->first = new;
}

/* ********* MANAJEMEN MEMORI NODE (LEADER) ********* */
/**
 * @brief Mengalokasikan simpul utama (Node) baru
 * @param x ID simpul yang ingin dibuat
 * @return Alamat simpul jika berhasil, NIL jika gagal
 * I.S. : x terdefinisi
 * F.S. : Dialokasikan simpul baru dengan nilai id = x
 * Proses: Alokasi memori dan inisialisasi atribut node
 */
AdrNode newGraphNode(int x){
    AdrNode new = malloc(sizeof(Node));
    if (new == NIL) return NIL;
    new->id = x;
    new->nPred = 0;
    new->trail = NIL;
    new->next = NIL;
    return new;
}

/**
 * @brief Dealokasi simpul utama (Node)
 * @param p Pointer ke simpul yang akan didealokasi
 * I.S. : p menunjuk ke simpul yang valid
 * F.S. : Memori simpul dikembalikan ke sistem
 */
void deallocGraphNode(AdrNode p){
    if (p != NIL) {
        free(p);
    }
}

/* ********* MANAJEMEN MEMORI TRAIL (SUCCESSOR) ********* */
/**
 * @brief Mengalokasikan simpul successor baru
 * @param pn Pointer ke simpul tujuan
 * @return Alamat SuccNode jika berhasil, NIL jika gagal
 * I.S. : pn valid
 * F.S. : Dialokasikan SuccNode dengan succ menunjuk ke pn
 */
AdrSuccNode newSuccNode(AdrNode pn){
    AdrSuccNode new = malloc(sizeof(SuccNode));
    if (new == NIL) return NIL;
    new->succ = pn;
    new->next = NIL;
    return new;
}

/**
 * @brief Dealokasi simpul successor (SuccNode)
 * @param p Pointer ke successor yang akan didealokasi
 * I.S. : p valid
 * F.S. : Memori SuccNode dikembalikan ke sistem
 */
void deallocSuccNode(AdrSuccNode p){
    if (p != NIL) {
        free(p);
    }

}

/* ********* OPERASI DASAR GRAF ********* */
/**
 * @brief Mencari simpul dalam graph
 * @param g Graph yang dicari
 * @param x ID simpul yang dicari
 * @return Alamat simpul jika ditemukan, NIL jika tidak ada
 * I.S. : g dan x terdefinisi
 * F.S. : Tidak mengubah g
 * Proses: Telusuri list simpul sampai ditemukan id = x
 */
AdrNode searchNode(Graph g, int x){
    AdrNode temp = g.first;
    while(temp != NIL){
        if(temp->id == x){
            return temp;
        }
        temp = temp->next;
    }

    return NIL;
}

/**
 * @brief Mencari edge dari prec ke succ
 * @param g Graph yang diperiksa
 * @param prec ID simpul asal
 * @param succ ID simpul tujuan
 * @return Alamat SuccNode jika edge ada, NIL jika tidak ada
 * I.S. : g, prec, succ terdefinisi
 * F.S. : Tidak mengubah g
 */
AdrSuccNode searchEdge(Graph g, int prec, int succ){
    AdrNode pred = searchNode(g, prec);
    if (pred == NIL) return NIL;
    AdrSuccNode temp = pred->trail;

    while (temp != NIL){
        if(temp->succ->id == succ) return temp;
        temp = temp->next;
    }

    return (temp!=NIL) ? temp : NIL;
}

/**
 * @brief Menambahkan simpul baru ke graph
 * @param g Graph yang akan diubah
 * @param x ID simpul yang akan ditambahkan
 * @param pn Alamat simpul hasil alokasi (output)
 * I.S. : g dan x terdefinisi, x belum ada dalam g
 * F.S. : Jika alokasi berhasil, x menjadi simpul terakhir
 *        dan pn menunjuk ke simpul tersebut
 *        Jika gagal, g tetap, pn = NIL
 */
void insertNode(Graph *g, int x, AdrNode *pn){
    *pn = newGraphNode(x);
    if(*pn == NIL) return;

    if(g->first == NIL){
        g->first = (*pn);
    }else{
        AdrNode temp = g->first;
        while(temp->next != NIL){
            temp = temp->next;
        }

        temp->next = (*pn); 
    }
    
    
}

/**
 * @brief Menambahkan edge dari prec ke succ ke dalam graph
 * @param g Graph yang akan diubah
 * @param prec ID simpul asal
 * @param succ ID simpul tujuan
 * I.S. : g, prec, succ terdefinisi
 * F.S. : 
 *   - Jika edge belum ada: tambahkan edge <prec, succ>
 *   - Jika node belum ada: node ditambahkan dulu
 *   - Jika edge sudah ada: tidak melakukan apa-apa
 */
void insertEdge(Graph *g, int prec, int succ){
    AdrNode nPrec = searchNode(*g, prec);
    if(nPrec == NIL){
        insertNode(g, prec, &nPrec);
    }

    AdrNode nSucc = searchNode(*g,succ);
    if(nSucc == NIL){
        insertNode(g, succ, &nSucc);
    }

    if(searchEdge(*g, prec, succ) != NIL) return;

    AdrSuccNode newEdge = newSuccNode(nSucc);
    AdrSuccNode temp = nPrec->trail;

    if(temp == NIL){
        nPrec->trail = newEdge;
    }else{
        while(temp->next != NIL){
        temp = temp->next;
        }
        temp->next = newEdge;
    }

    nSucc->nPred++;
    
}

/**
 * @brief Menghapus simpul dari graph beserta seluruh edge terkait
 * @param g Graph yang akan diubah
 * @param x ID simpul yang ingin dihapus
 * I.S. : g terdefinisi, x boleh ada atau tidak di g
 * F.S. : Simpul x dan semua edge ke/dari x dihapus dari g.
 *        Jika simpul yang dihapus adalah satu-satunya simpul di graph,
 *        maka graph menjadi kosong (FIRST(*g) == NIL).
 * Proses:
 * - Menghapus semua edge yang menunjuk ke x.
 * - Menghapus semua edge keluar dari x.
 * - Menghapus simpul x dari list simpul.
 */
void deleteNode(Graph *g, int x){
    AdrNode nodeX = searchNode(*g, x);
    if (nodeX == NIL) {
        return; // Simpul yang akan dihapus tidak ditemukan
    }

    // Hapus semua edge KELUAR dari nodeX dan update nPred successor
    AdrSuccNode currentSucc = nodeX->trail;
    while (currentSucc != NIL) {
        AdrSuccNode tempSucc = currentSucc;
        currentSucc = currentSucc->next; // Maju dulu sebelum dealloc

        if (tempSucc->succ != NIL) {
            tempSucc->succ->nPred--; // Kurangi nPred dari simpul tujuan
        }
        deallocSuccNode(tempSucc); // Hapus edge
    }
    nodeX->trail = NIL; 

    // Hapus semua edge MASUK ke nodeX dari simpul lain
    AdrNode P = g->first;
    while (P != NIL) {
        if (P == nodeX) { // Lewati nodeX itu sendiri
            P = P->next;
            continue;
        }

        AdrSuccNode trailP = P->trail;
        AdrSuccNode prevTrailP = NIL;
        while (trailP != NIL) {
            if (trailP->succ == nodeX) { // Edge dari P ke nodeX ditemukan
                AdrSuccNode toDeleteEdge = trailP;
                if (prevTrailP == NIL) { 
                    P->trail = trailP->next;
                } else {
                    prevTrailP->next = trailP->next;
                }
                trailP = trailP->next; // Maju ke trail berikutnya
                deallocSuccNode(toDeleteEdge); // Hapus edge
            } else {
                prevTrailP = trailP;
                trailP = trailP->next;
            }
        }
        P = P->next;
    }

    // Hapus nodeX dari list simpul utama
    AdrNode current = g->first;
    AdrNode prev = NIL;
    while (current != NIL && current != nodeX) {
        prev = current;
        current = current->next;
    }

    if (current == nodeX) { // Seharusnya selalu ketemu karena sudah dicek di awal
        if (prev == NIL) { 
            g->first = nodeX->next;
        } else {
            prev->next = nodeX->next;
        }
        deallocGraphNode(nodeX); // Dealokasi memori nodeX
    }
}

/**
 * @brief Menampilkan isi graph berupa daftar successor dari setiap simpul.
 *
 * I.S. : Graph g sudah terdefinisi (boleh kosong).
 * F.S. : Jika graph kosong, cetak "Graph kosong".
 *        Semua simpul dicetak ke layar bersama daftar successor-nya dalam format:
 *        <id_simpul> -> <id_succ_1> -> <id_succ_2> ... 
 *        Jika simpul tidak memiliki successor, hanya ditampilkan id-nya saja
 *        Selalu akhiri setiap output dengan endline (\n).
 *
 * Proses:
 * - Jika graph kosong, cetak "Graph kosong" dan keluar.
 * - Melakukan traversal dari simpul pertama (g.first) ke simpul berikutnya
 * - Untuk setiap simpul, mencetak id-nya, lalu menelusuri dan mencetak semua trail (succNode) yang keluar darinya
 * 
 *
 * Contoh Graph:
 * Misalkan ada graph dengan edge:
 *   1 → 2
 *   1 → 3
 *   4 → 5
 *   2 → 5
 *   3 → 5
 *
 * Maka output dari printGraph(g) adalah:
 * 1 -> 2 -> 3
 * 2 -> 5
 * 3 -> 5
 * 4 -> 5
 * 5
 * 
 */
void printGraph(Graph g){
    if (g.first == NIL) {
        printf("Graph kosong\n");
        return;
    }

    AdrNode temp = g.first;

    while (temp != NIL){
        printf("%d", temp->id);
        AdrSuccNode temp2 = temp->trail;
        while(temp2 != NIL){
            printf(" -> %d", temp2->succ->id);
            temp2 = temp2->next;
        }
        printf("\n");
        temp = temp->next;
    }
}