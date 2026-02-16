#include <stdio.h>
#include <stdlib.h>
#include "../listlinier.h"


#ifndef UI_H
#define UI_H

/**
 * @brief Mendealokasi semua elemen list dan mengatur list menjadi kosong.
 * @param l Pointer ke list yang akan di-dealokasi.
 * I.S. l terdefinisi, mungkin kosong.
 * F.S. Semua elemen list di-dealokasi. *l menjadi NULL.
 */
void dealokasiList(List *l);

/**
 * @brief Melakukan insert val ke list l secara terurut
 * @param *l adalah list yang dituju.
 * @param val adalah data yang ingin dimasukkan.
 * I.S. l terdefinisi, mungkin kosong.
 * F.S. val sudah ada di dalam l dengan semua elemen l terurut membesar.
 */
void insertSorted(List *l, ElType val);

/**
 * @brief Mengeluarkan hasil union dari 2 buah list
 * @param l1 adalah list pertama.
 * @param l2 adalah list kedua.
 * I.S. l1 dan l2 terdefinisi, mungkin kosong.
 * F.S. l1 dan l2 tetap, tidak berubah
 * @return list yang merupakan hasil union antara list pertama dan kedua
 */
List getUnion(List l1, List l2);

/**
 * @brief Mengeluarkan hasil intersect dari 2 buah list
 * @param l1 adalah list pertama.
 * @param l2 adalah list kedua.
 * I.S. l1 dan l2 terdefinisi, mungkin kosong.
 * F.S. l1 dan l2 tetap, tidak berubah
 * @return list yang merupakan hasil intersect antara list pertama dan kedua
 */
List getIntersect(List l1, List l2);

/**
 * @brief Melakukan input untuk mendapatkan n (hari). Kemudian untuk setiap n akan menerima input x (jumlah nimons pada hari itu) dan melakukan input list dengan elemen sebanyak x untuk setiap n. Berikan Union dan Intersect akhir yang disimpan ke dalam variabel "Union" dan "Irisan".
 * @param *Union adalah pointer list Union.
 * @param *Irisan adalah pointer list Irisan.
 * I.S. Union dan Irisan terdefinisi dengan elemen awal kosong.
 * F.S. Union dan Irisan berisi hasil union dan intersect seluruh data yang diinputkan.
 */
void getData(List *Union, List *Irisan);

#endif