#include <iostream>
#include "CommentsManager.hpp"

int main() {
    CommentsManager cm;

    cm.setReputation("budi_baik", 0);
    cm.setReputation("toxic_boy", 50);
    cm.setReputation("spam_bot1", 999);

    cm.addBlacklist("bodoh");
    cm.addBlacklist("anjing");
    cm.addBlacklist("bangsat");
    
    cm.acceptChat(Comment("budi_baik", false, {"s3m4ng4t", "ya", "ganteng", "mwah"}));
    cm.acceptChat(Comment("toxic_boy1", false, {"woy", "anjing", "bangsat"}));
    cm.acceptChat(Comment("spam_bot1", false, {"klik", "link", "ini"})); 
    cm.acceptChat(Comment("sultan_99", true,  {"s3mAng4t", "bang", "streamingnya"}));
    cm.acceptChat(Comment("toxic_boy", false, {"mainnya", "bodoh", "banget"}));
    
    std::cout << "--- Chat Masuk ---" << std::endl;
    cm.printScreen();

    std::cout << "\n--- Setelah Spammer Ditendang (Batas Skor > 100) ---" << std::endl;
    cm.kickSpammer(100);
    cm.printScreen();

    std::cout << "\n--- Deteksi Kata Kasar ---" << std::endl;
    cm.printViolation();

    std::cout << "\n--- Pengumuman Kuis ---" << std::endl;
    std::cout << "Pemenang: " << cm.quizWinner({"s3mAng4t", "s3m4ng4t"}) << std::endl;
    
    std::cout << "\n--- Mode Slowchat: VIP Naik Ke Atas ---" << std::endl;
    cm.upVIPComment();
    cm.printScreen();
    
    std::cout << "\n--- Pengumuman Kuis ---" << std::endl;
    std::cout << "Pemenang: " << cm.quizWinner({"s3mAng4t", "s3m4ng4t"}) << std::endl;
    return 0;
}