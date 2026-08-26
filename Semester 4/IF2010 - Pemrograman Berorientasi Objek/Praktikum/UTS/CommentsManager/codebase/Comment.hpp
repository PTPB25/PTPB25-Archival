/**
 * @file Comment.hpp
 * @brief Mendefinisikan kelas Comment yang merepresentasikan pesan chat dari penonton.
 */

#pragma once
#include <string>
#include <vector>

/**
 * @class Comment
 * @brief Kelas untuk menyimpan data sebuah komentar/chat dalam livestream.
 * * Kelas ini bertugas menyimpan informasi tentang siapa pengirim chat, status VIP pengirim,
 * dan isi pesan yang sudah dipecah menjadi kumpulan kata untuk mempermudah analisis.
 */
class Comment {
    private:
        std::string username_;               /// Nama pengguna pengirim komentar
        bool is_vip_;                        /// Status VIP pengguna (true jika VIP, false jika normal)
        std::vector<std::string> words_;     /// Kumpulan kata dari isi komentar yang sudah dipisah

    public:
        /**
         * @brief Konstruktor untuk membuat objek Comment baru.
         * * @param username Nama pengguna pengirim chat.
         * @param is_vip Status VIP dari pengguna (berlangganan/tidak).
         * @param words Isi pesan yang sudah dipisah per kata ke dalam sebuah vector.
         */
        Comment(std::string username, bool is_vip, std::vector<std::string> words)
            : username_(username), is_vip_(is_vip), words_(words) {};
        
        /**
         * @brief Mengambil nama pengguna pengirim komentar.
         * @return Referensi konstan ke string username.
         */
        const std::string& getUsername() const {
            return username_;
        }

        /**
         * @brief Mengambil isi komentar yang sudah dipecah per kata.
         * @return Referensi konstan ke vector of string yang berisi kata-kata.
         */
        const std::vector<std::string>& getWords() const {
            return words_;
        }

        /**
         * @brief Mengecek apakah pengirim komentar adalah pengguna VIP.
         * @return true jika pengguna adalah VIP, false jika pengguna normal.
         */
        bool isVip() const {
            return is_vip_;
        }
};