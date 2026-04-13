#ifndef __AUTHENTICATOR_HPP__
#define __AUTHENTICATOR_HPP__

#include <iostream>
#include "User.hpp"
#include "AdminUser.hpp"

using namespace std;

const int MAX_USERS = 10; // Maksimum user yang bisa terdaftar dalam sistem

class Authenticator
{
private:
  User *users[MAX_USERS]; // Array pointer untuk menyimpan objek User atau AdminUser
  int userCount;          // Jumlah user yang telah terdaftar dalam sistem
  User *currentUser;      // User yang sedang login (bisa User atau AdminUser)
  string secretResource;  // Resource rahasia yang hanya bisa diakses oleh user yang login

public:
  Authenticator();
  /* Constructor:
   * - Menginisialisasi sistem dengan resource rahasia ("Ini adalah data rahasia!")
   * - Tidak ada user yang login (nullptr)
   * - Tidak ada user yang terdaftar
   */

  void registerUser(const string &username, const string &password, bool isAdmin);
  /* Mendaftarkan user baru sebagai RegularUser atau AdminUser.
   * Input:
   * - username: Nama pengguna yang ingin didaftarkan.
   * - password: Kata sandi untuk pengguna.
   * - isAdmin: Jika true, user akan dibuat sebagai AdminUser, jika false sebagai User biasa.
   *
   * Output:
   * - "Gagal: Kapasitas user penuh!" jika jumlah user telah mencapai batas maksimum.
   * - "Gagal: Username sudah digunakan!" jika username sudah terdaftar dalam sistem.
   * - "Sukses: User <username> berhasil terdaftar!" jika pendaftaran berhasil.
   *      *<username> diganti dengan nama pengguna yang baru terdaftar.
   */

  void login(const string &username, const string &password);
  /* Mencoba login dengan username dan password yang diberikan.
   * Input:
   * - username: Nama pengguna yang ingin login.
   * - password: Kata sandi pengguna yang ingin login.
   *
   * Output:
   * - "Gagal: Username atau password salah!" jika kombinasi username dan password tidak ditemukan.
   * - "Sukses: Login berhasil! Selamat datang, <username>." jika login berhasil.
   *      *<username> diganti dengan nama pengguna yang berhasil login.
   */

  void logout();
  /* Melakukan logout dari sesi yang sedang berjalan.
   *
   * Output:
   * - "Gagal: Tidak ada user yang sedang login!" jika tidak ada user yang sedang login.
   * - "Sukses: User <username> telah logout." jika logout berhasil.
   *      *<username> diganti dengan nama pengguna yang logout.
   */

  void accessResource() const;
  /* Menampilkan resource rahasia jika user sudah login.
   *
   * Output:
   * - "Akses ditolak! Silakan login terlebih dahulu." jika tidak ada user yang login.
   * - "Resource: <secretResource>" jika user sedang login.
   *      *<secretResource> diganti dengan resource rahasia saat ini.
   */

  void setResource(const string &newResource);
  /* Mengubah resource rahasia (hanya AdminUser yang dapat melakukannya).
   * Input:
   * - newResource: Resource baru yang akan disimpan.
   *
   * Output:
   * - "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." jika tidak ada user yang login.
   * - "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." jika user yang login bukan AdminUser.
   * - "Sukses: Resource telah diperbarui oleh <username>." jika resource berhasil diubah.
   *      *<username> diganti dengan nama pengguna admin yang melakukan perubahan.
   */

  ~Authenticator();
  /* Destructor:
   * - Membersihkan semua objek User dan AdminUser yang telah dibuat.
   */
};

#endif