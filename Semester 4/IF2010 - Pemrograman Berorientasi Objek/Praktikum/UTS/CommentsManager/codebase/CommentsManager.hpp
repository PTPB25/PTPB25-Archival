/**
 * @file CommentsManager.hpp
 * @brief Mendefinisikan kelas CommentsManager untuk mengelola log chat dan sistem moderasi otomatis.
 */

#pragma once
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include "Comment.hpp"

/**
 * @class CommentsManager
 * @brief Sistem Auto-Moderator dan pengelola interaksi chat livestream.
 * * Kelas ini bertugas menyimpan riwayat chat, mendaftar kata-kata terlarang (blacklist),
 * serta memantau reputasi pengguna. Termasuk di dalamnya terdapat fungsi-fungsi 
 * yang harus diimplementasikan menggunakan algoritma STL standar C++.
 */
class CommentsManager{
    private:
        std::vector<Comment> chat_log_;          ///< Menyimpan urutan riwayat semua chat yang masuk
        std::set<std::string> blacklist_;        ///< Menyimpan database kata-kata terlarang (unik)
        std::map<std::string, int> reputation_;  ///< Memetakan username ke skor pelanggaran/reputasi
    
    public:
        /**
         * @brief Konstruktor default untuk inisialisasi CommentsManager.
         * * Menginisialisasi kontainer chat_log, blacklist, dan reputation 
         * dalam keadaan kosong saat objek dibuat.
         */
        CommentsManager(){
            chat_log_ = std::vector<Comment>();
            blacklist_ = std::set<std::string>();
            reputation_ = std::map<std::string, int>();
        }

        /**
         * @brief Mengatur atau memperbarui skor reputasi dari seorang pengguna.
         * * @param username Nama pengguna yang akan diatur skornya.
         * @param score Skor reputasi (semakin tinggi menandakan indikasi spammer).
         */
        void setReputation(const std::string& username, int score){
            reputation_[username] = score;
        }

        /**
         * @brief Menambahkan kata baru ke dalam database kata terlarang (blacklist).
         * * @param word Kata yang dilarang untuk diketik di dalam livestream.
         */
        void addBlacklist(const std::string& word){
            blacklist_.insert(word);
        }

        /**
         * @brief Menerima komentar baru dan memasukkannya ke bagian akhir riwayat chat.
         * * @param comment Objek komentar konstan yang dikirim oleh penonton.
         */
        void acceptChat(const Comment& comment){
            chat_log_.push_back(comment);
        }

        /**
         * @brief Mencetak seluruh isi riwayat chat ke layar console.
         * * Akan menampilkan tag [VIP] atau [Normal] berdasarkan status pengirim, 
         * diikuti dengan username dan isi pesan.
         */
        void printScreen() const{
            for (const auto& comment : chat_log_) {
                std::string status = comment.isVip() ? "[VIP]" : "[Normal]";
                std::cout << status << " " << comment.getUsername() << ": ";
                
                for (const auto& kata : comment.getWords()) {
                    std::cout << kata << " ";
                }
                std::cout << std::endl;
            }
        }

        // ======================= YOUR TASK ===========================
        
        /**
         * @brief Menendang/menghapus komentar dari pengguna yang skor reputasinya melebihi batas.
         * @param threshold_score Batas maksimal skor reputasi yang diizinkan sebelum ditendang.
         * @note
         * Hint: apa hayo yang bisa menghapus secara kondisional. kombinasikan remove if
         */
        void kickSpammer(int threshold_score);

        /**
         * @brief Mencetak semua pelanggaran kata kasar ke layar.
         * * Menelusuri semua chat, dan jika ditemukan kata yang ada di dalam `blacklist_`,
         * program akan mencetak kata tersebut berserta nama pelakunya.
         * Jika tidak ada print "TIDAK ADA PELANGGARAN\n"
         * @note 
         * Hint: cuma looping aja kok, tapi sambil cek yak kemunculan elemen setnya. btw loopingnya pake stl yah, jangan pake for/while loop (nanti ngga dianggep bener yah).
         */
        void printViolation();

        /**
         * @brief Mencari pemenang kuis pertama berdasarkan kunci jawaban.
         * @param passwords Set yang berisi kumpulan variasi jawaban yang benar.
         * @return Username dari penonton PERTAMA yang menjawab dengan benar. Jika tidak ada return string "BELUM ADA PEMENANG"
         * * @note 
         * HINT: nested searching, manfaatkan algo pencarian dan pengecekan kondisi yang sesuai. Di dalam predicate stl bisa ada algo lain (dikombinasikan) yang memiliki predicate sendiri. pastikan anda memahami cara menggunakan stl beserta predicatenya.
         */
        std::string quizWinner(const std::set<std::string>& passwords);

        /**
         * @brief Memprioritaskan komentar pengguna VIP agar mudah dibaca streamer.
         * * Menggeser semua komentar dari pengguna VIP ke bagian paling atas (depan) log chat
         * tanpa merusak urutan waktu masuk dari komentar tersebut.
         * @note 
         * HINT: Lakukan partisi pada vector.
         */
        void upVIPComment();
};