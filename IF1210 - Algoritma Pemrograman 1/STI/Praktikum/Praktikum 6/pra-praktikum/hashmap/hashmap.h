#ifndef HASHMAP_H
#define HASHMAP_H
#include "Boolean.h"
#include <stdio.h>

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
 */

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 16
#define Undefined -9999

// typedef int bool;
typedef int keytype;   // Tipe data untuk key
typedef int valuetype; // Tipe data untuk value
typedef int address;   // Tipe data untuk alamat penyimpanan

typedef struct
{
    keytype key;
    valuetype value;
} infotype;

typedef struct
{
    infotype Elements[MaxEl];
    int Count;
} HashMap;

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
// TODO: 1. CreateEmpty
void CreateEmpty(HashMap *h);

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
// TODO: 2. Value
int Value(HashMap h, keytype key);

// TODO: 3. Insert
void Insert(HashMap *h, keytype key, valuetype value);

// TODO: 4. printHashMap
void printHashMap(HashMap h);

#endif