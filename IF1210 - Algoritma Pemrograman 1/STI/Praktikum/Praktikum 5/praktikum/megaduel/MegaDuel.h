// NIM    : <Tulis NIM Anda>
// Nama   : <Tulis Nama Anda>
// Tanggal: <Tulis tanggal pengerjaan>

#ifndef MEGA_DUEL_H
#define MEGA_DUEL_H

#include "MegaNimons.h"

/**
 * Anda boleh menambahkan fungsi/prosedur tambahan jika diperlukan
 */

/**
 * Menjalankan turnamen pertarungan antar MegaNimons dalam LabTrack.
 * Pertarungan dilakukan secara berpasangan dari ujung list:
 *   - MegaNimons pertama vs terakhir
 *   - Pemenang tetap, yang kalah dieliminasi dari list
 *   - Proses berlanjut dengan MegaNimons berikutnya di sisi yang masih hidup
 *   - Berlangsung hingga hanya tersisa satu MegaNimons sebagai pemenang
 *
 * Aturan penentuan pemenang diatur oleh fungsi resolveDuel.
 *
 * I.S. LabTrack L berisi ≥ 1 MegaNimons
 * F.S. Semua MegaNimons tersingkir kecuali satu pemenang.
 *      Ditampilkan log setiap duel dan pemenang akhir.
 *
 * Contoh:
 *
 * Input List (nEff = 3):
 *   0: Kevzilla (800.0)
 *   1: Bobzilla (850.0)
 *   2: Melatron (780.0)
 *
 * Output:
 *   <endline>
 *   == DUEL ROUND ==
 *   Duel: Kevzilla (800.0) vs Melatron (780.0)
 *   Winner: Kevzilla
 *   <endline>
 *   == DUEL ROUND ==
 *   Duel: Kevzilla (800.0) vs Bobzilla (850.0)
 *   Winner: Bobzilla
 *   <endline>
 *   == The Champion: Bobzilla ==
 */
void runMegaDuel(LabTrack *L);

#endif
