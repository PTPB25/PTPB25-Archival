/* =======================================================
 * File: problem.c
 * Deskripsi:
 *   Implementasi fungsi untuk menghitung jumlah "good nodes"
 *   pada sebuah binary tree.
 *
 *   Sebuah node X disebut "good" jika pada path dari root ke X,
 *   tidak ada node dengan nilai lebih besar dari X.
 *
 * ======================================================= */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


/* =======================================================
 * Fungsi Utama: countGoodNodes
 * =======================================================
 *
 * Deskripsi:
 *   Menghitung jumlah "good nodes" pada sebuah binary tree.
 *   Sebuah node X adalah "good" jika dalam path dari root ke X,
 *   tidak ada node dengan nilai yang lebih besar dari X.
 *
 * Spesifikasi:
 *   I.S.  : p terdefinisi (mungkin NULL)
 *   F.S.  : Mengembalikan jumlah good nodes (integer >= 0)
 *
 * Catatan:
 *   - Jumlah node n ∈ [1, 10^4].
 *   - Nilai node ∈ [-10^4, 10^4].
 *   - Root selalu dianggap sebagai good node.
 *   - Gunakan DFS dengan tracking nilai maksimum pada path.
 */

/* =======================================================
 * ----------------------- CONTOH 1 ------------------------
 * =========================================================
 * Misal pohon terbentuk:
 *
 *           (3)
 *          /   \
 *        (1)   (4)
 *       /     /  \
 *     (3)  (1)  (5)
 *
 * Path dan analisis:
 * - Node 3 (root): good (selalu good)
 * - Node 1 (kiri root): tidak good (3 > 1 pada path)
 * - Node 4 (kanan root): good (4 > 3)
 * - Node 3 (kiri-kiri): good (3 >= 3 pada path)
 * - Node 1 (kanan-kiri): tidak good (4 > 1 pada path)
 * - Node 5 (kanan-kanan): good (5 > 4)
 *
 * Good nodes: 3, 3, 4, 5
 * Hasil: 4
 * Output: 4
 * ======================================================= */

/*
 * ----------------------- CONTOH 2 ------------------------
 * Misal pohon 2:
 *
 *           (3)
 *          /
 *        (3)
 *       /  \
 *     (4)  (2)
 *
 * Path dan analisis:
 * - Node 3 (root): good
 * - Node 3 (kiri): good (3 >= 3)
 * - Node 4 (kiri-kiri): good (4 > 3)
 * - Node 2 (kiri-kanan): tidak good (3 > 2)
 *
 * Good nodes: 3, 3, 4
 * Hasil: 3
 * Output: 3
 * --------------------------------------------------------
 */

/* Fungsi helper untuk DFS dengan tracking maksimum */
int countGoodNodesHelper(BinTree p, int maxSoFar) {
    
    if(isTreeEmpty(p)) return 0;
    int left = countGoodNodesHelper(LEFT(p), (ROOT(p) > maxSoFar ? ROOT(p) : maxSoFar));
    int right = countGoodNodesHelper(RIGHT(p), (ROOT(p) > maxSoFar ? ROOT(p) : maxSoFar));
    return (int)(ROOT(p) >= maxSoFar) + left + right;

}

int countGoodNodes(BinTree p) {
    return countGoodNodesHelper(p, (int)(-1e4));
}
