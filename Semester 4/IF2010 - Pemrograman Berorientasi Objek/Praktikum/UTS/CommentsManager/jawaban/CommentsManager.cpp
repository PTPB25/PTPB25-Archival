#include "CommentsManager.hpp"
#include <algorithm>

void CommentsManager::kickSpammer(int threshold_score){
    auto it = std::remove_if(chat_log_.begin(), chat_log_.end(), [&](const Comment& e){
        auto it = reputation_.find(e.getUsername());
        int score;
        if(it == reputation_.end()) score = 0;
        else score = it->second;
        return score > threshold_score;
    });
    chat_log_.erase(it, chat_log_.end());
}

void CommentsManager::printViolation(){
    int count = 0;
    std::for_each(chat_log_.begin(), chat_log_.end(), [&](const Comment& e){
        std::for_each(e.getWords().begin(), e.getWords().end(), [&](const std::string &word){
            auto it = blacklist_.find(word);
            if(it != blacklist_.end()){
                count++;
                std::cout << "kata \"" << word << "\" oleh akun \"" << e.getUsername() << "\"\n";
            }
        });
    });

    if(count == 0) std::cout << "TIDAK ADA PELANGGARAN" << std::endl;
}

/**
 * @brief Mencari pemenang kuis pertama berdasarkan kunci jawaban.
 * @param passwords Set yang berisi kumpulan variasi jawaban yang benar.
 * @return Username dari penonton PERTAMA yang menjawab dengan benar. Jika tidak ada return string "BELUM ADA PEMENANG"
 * * @note 
 * HINT: nested searching, manfaatkan algo pencarian dan pengecekan kondisi yang sesuai. Di dalam predicate stl bisa ada algo lain (dikombinasikan) yang memiliki predicate sendiri. pastikan anda memahami cara menggunakan stl beserta predicatenya.
 */
std::string CommentsManager::quizWinner(const std::set<std::string>& passwords){
    auto it = 
    std::find_if(chat_log_.begin(), chat_log_.end(), [&](const Comment &e){
        return std::find_if(e.getWords().begin(), e.getWords().end(), [&](const std::string &word){
            return passwords.find(word) != passwords.end();
        }) != e.getWords().end();
    });

    if(it != chat_log_.end()) return it->getUsername();
    return "BELUM ADA PEMENANG";
}

/**
 * @brief Memprioritaskan komentar pengguna VIP agar mudah dibaca streamer.
 * * Menggeser semua komentar dari pengguna VIP ke bagian paling atas (depan) log chat
 * tanpa merusak urutan waktu masuk dari komentar tersebut.
 * @note 
 * HINT: Lakukan partisi pada vector.
 */
void CommentsManager::upVIPComment(){
    std::stable_partition(chat_log_.begin(), chat_log_.end(), [&](const Comment& e){
        return e.isVip();
    });
}