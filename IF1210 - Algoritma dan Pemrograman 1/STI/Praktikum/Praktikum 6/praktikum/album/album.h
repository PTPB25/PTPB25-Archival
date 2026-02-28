// NIM     : <Tulis NIM Anda>  ; <Tulis NIM Partner Anda>
// NAMA    : <Tulis Nama Anda> ; <Tulis Nama Partner Anda>
// Tanggal : <Tulis tanggal praktikum>

#ifndef ALBUM_H
#define ALBUM_H

#include <stdio.h>
#include <stdlib.h>  // untuk qsort
#include <string.h>  // untuk strcmp dan strcpy
#include "boolean.h"

#define Nil 0
#define MaxElSong 300         // Maksimum jumlah lagu dalam satu album
#define MaxStringLength 50    // Maksimum panjang judul lagu

typedef struct
{
    char Songs[MaxElSong][MaxStringLength];   // Songs[i] menyimpan judul lagu
    int Count;                                // Banyaknya lagu dalam album
} Album;

/* Definisi Album A kosong : A.Count = Nil */
/* A.Count = jumlah element Album */
/* A.Songs = tempat penyimpanan element Album */

/* ********* Prototype ********* */

/* ********* Konstruktor/Kreator ********* */
void CreateEmptyAlbum(Album *A);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Album A kosong berkapasitas MaxElSong */
/* Ciri Album kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan Album ********* */
boolean IsEmptyAlbum(Album A);
/* Mengirim true jika Album A kosong*/
/* Ciri Album kosong : count bernilai Nil */

boolean IsFullAlbum(Album A);
/* Mengirim true jika Album A penuh */
/* Ciri Album penuh : count bernilai MaxElSong */

/* ********** Operator Dasar Album ********* */
boolean IsSongInAlbum(Album A, char SongTitle[]);
/* Mengembalikan true jika SongTitle sudah ada di dalam album A. Anda bisa memanfaatkan fungsi strcmp.
   strcmp bernilai 0 apabila dua string sama. */

/* ********* Comparator untuk qsort ********* */
int cmpstr(const void *a, const void *b);
/* Fungsi pembanding string untuk digunakan oleh qsort */
// const char *sa = (const char *)a;
// const char *sb = (const char *)b;
// return strcmp(sa, sb);

void SortAlbum(Album *A);
/* Mengurutkan Album secara leksikografis menggunakan qsort */
// qsort((*A).Songs, (*A).Count, sizeof((*A).Songs[0]), cmpstr);

void InsertSong(Album *A, char SongTitle[]);
/* Menambahkan SongTitle sebagai elemen Album A. */
/* I.S. A mungkin kosong, A mungkin penuh
        A mungkin sudah beranggotakan SongTitle */
/* F.S. Jika A belum penuh, SongTitle menjadi anggota dari A. Bisa memanfaatkan fungsi strcpy.
        Jika SongTitle sudah merupakan anggota atau album sudah penuh, operasi tidak dilakukan
        Judul lagu dalam album akan tetap terurut secara alfabetik/leksikografis menggunakan SortAlbum() */

void DeleteSong(Album *A, char SongTitle[]);
/* Menghapus SongTitle dari Album A. */
/* I.S. A tidak kosong
        SongTitle mungkin anggota / bukan anggota dari A */
/* F.S. SongTitle bukan anggota dari A */
/* Bisa memanfaatkan strcmp dan strcpy */

/* ********* Operator Album Tambahan ********* */
Album UnionAlbum(Album A1, Album A2);
/* Menghasilkan Album baru yang berisi gabungan lagu dari A1 dan A2 tanpa duplikat lagu */
/* Contoh: 
   A1.Songs = ["abc", "def"]
   A2.Songs = ["def", "ghi"]
   newAlbum = A1 U A2
   newAlbum.Songs = ["abc", "def", "ghi"] */

Album IntersectionAlbum(Album A1, Album A2);
/* Menghasilkan Album baru yang berisi lagu-lagu yang terdapat di A1 dan A2 secara bersamaan */
/* Contoh:
   A1.Songs = ["abc", "def"]
   A2.Songs = ["def", "ghi"]
   newAlbum = A1 ∩ A2
   newAlbum.Songs = ["def"] */

Album DifferenceAlbum(Album A1, Album A2);
/* Menghasilkan Album berisi lagu-lagu yang terdapat di A1 tetapi tidak di A2 */
/* Contoh:
   A1.Songs = ["abc", "def"]
   A2.Songs = ["def", "ghi"]
   newAlbum = A1 - A2
   newAlbum.Songs = ["abc"] */

/* ********* Utility Function ********* */
void PrintAlbum(Album A);
/* Menampilkan semua lagu dalam Album dalam format {lagu1, lagu2, lagu3} */
/* Jika Album kosong, menampilkan {} */
/* Tampilkan juga dalam urutan judul lagu yang terurut */

#endif