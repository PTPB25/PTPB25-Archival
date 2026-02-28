#include "bintree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Deskripsi:
 *  Mengembalikan true jika kedua binary tree identik, false jika tidak.
 * 
 * Spesifikasi:
 *  I.S.  : P dan Q terdefinisi (boleh NULL)
 *  F.S.  : Mengembalikan boolean true atau false.
 * 
 * Catatan:
 *  - Dua binary tree dikatakan identik apabila memiliki struktur yang sama dan
 *    nilai pada node-node yang bersesuaian juga sama.
 *
 * =======================================================
 * ----------------------- CONTOH 1 ----------------------
 * =======================================================
 *          (1)                 (1)
 *         /   \               /   \
 *       (2)   (3)           (2)   (3)
 * 
 * Output: true (1)
 * 
 * =======================================================
 * ----------------------- CONTOH 2 ----------------------
 * =======================================================
 *         (1)                 (1)
 *        /   \               /   \
 *      (2)   (3)           (3)   (2)
 * 
 * Output: false (0)
 */

boolean isIdentical(BinTree P, BinTree Q){

    if(isTreeEmpty(P) && isTreeEmpty(Q)) return true;
    if(isTreeEmpty(P) || isTreeEmpty(Q)) return false;
    return (ROOT(P) == ROOT(Q)) && isIdentical(LEFT(P), LEFT(Q)) && isIdentical(RIGHT(P), RIGHT(Q));

}