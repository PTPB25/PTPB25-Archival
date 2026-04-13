/* File: palindrome.c */
/* Implementasi fungsi untuk menghitung jumlah kata palindrome */

#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>

/*
 * Fungsi untuk mengecek apakah sebuah Word adalah palindrome
 * Sebuah kata adalah palindrome jika dibaca dari depan dan belakang sama
 * I.S. w terdefinisi
 * F.S. return true jika w adalah palindrome, false jika tidak
 *
 * Contoh:
 * - "mom" adalah palindrome -> return true
 * - "dad" adalah palindrome -> return true
 * - "level" adalah palindrome -> return true
 * - "hello" bukan palindrome -> return false
 * - "a" adalah palindrome -> return true
 * - "" (kata kosong) adalah palindrome -> return true
 *
 * Catatan: Pengecekan case-sensitive (huruf besar dan kecil dianggap berbeda)
 *
 * Hint: Gunakan dua pointer, satu dari awal dan satu dari akhir
 *       Bandingkan karakter sampai bertemu di tengah
 */
boolean isPalindrome(Word w) {
    /* KAMUS LOKAL */
    int l, r;

    /* ALGORITMA */
    l = 0;
    r = w.Length - 1;
    while(l <= r){
        if(w.TabWord[l] != w.TabWord[r]) return false;
        l++;
        r--;
    }

    return true;
}

/*
 * Fungsi untuk menghitung jumlah kata palindrome dari input
 * I.S. mesin kata siap digunakan (sudah di START())
 * F.S. return jumlah kata yang merupakan palindrome
 *
 * Contoh:
 * Input: "mom dad hello level world."
 * Output: 3 (mom, dad, level adalah palindrome)
 *
 * Input: "hello world test."
 * Output: 0 (tidak ada palindrome)
 *
 * Input: "a b c d."
 * Output: 4 (semua kata 1 karakter adalah palindrome)
 *
 * Hint: Gunakan STARTWORD() untuk memulai pembacaan kata
 *       Gunakan loop dengan kondisi !EndWord
 *       Gunakan ADVWORD() untuk pindah ke kata berikutnya
 *       Gunakan isPalindrome() untuk mengecek setiap kata
 */
int countPalindromes() {
    /* KAMUS LOKAL */
    int i;
    int palindromeCnt;

    /* ALGORITMA */
    palindromeCnt = 0;
    STARTWORD();
    while(!EndWord){

        if(isPalindrome(currentWord)) palindromeCnt++;
        ADVWORD();
        
    }

    return palindromeCnt;
}
