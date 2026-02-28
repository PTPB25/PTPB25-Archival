#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mahasiswa {
    public:
        static int counter;

        Mahasiswa() {
            this->name = "NPC";
            this->nim = "135" + to_string(counter);
            this->ipk = 0;
            this->total_sks = 0;
            Mahasiswa::counter++;
        }

        Mahasiswa(string newName) {
            this->name = newName;
            this->nim = "135" + to_string(counter);
            this->ipk = 0;
            this->total_sks = 0;
            Mahasiswa::counter++;
        }

        void tambahNilai(float nilai, int sks) {
            this->ipk = (this->ipk * this->total_sks + nilai * sks) / (this->total_sks + sks);
            this->total_sks += sks;
        }

        void info(){
            printf("INFORMASI MAHASISWA\n");
            printf("Nama: %s\n", this->name.c_str());
            printf("NIM: %s\n", this->nim.c_str());
            printf("IPK: %.2f\n", this->ipk);
            printf("SKS: %d\n", this->total_sks);
        }

    private:
        string name;
        string nim;
        float ipk;
        int total_sks;
};

int Mahasiswa::counter = 0;