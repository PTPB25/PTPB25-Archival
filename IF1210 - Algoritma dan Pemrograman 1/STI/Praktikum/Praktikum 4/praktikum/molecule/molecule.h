#ifndef MOLECULE_H
#define MOLECULE_H

#include <stdbool.h> // Untuk tipe data bool

#define MAX_ATOM_TYPES 20
#define MAX_SYMBOL_LEN 4

// Struktur untuk menyimpan informasi satu jenis atom dalam molekul
typedef struct {
    char symbol[MAX_SYMBOL_LEN]; // Simbol atom (e.g., "H", "O", "Fe")
    int count;                   // Jumlah atom jenis ini dalam molekul
} AtomInfo;

typedef struct {
    AtomInfo atoms[MAX_ATOM_TYPES];
    int numAtomTypes;
} Molecule;

/**
 * @brief Menginisialisasi sebuah molekul menjadi kosong.
 *
 * @param m Pointer ke Molecule yang akan diinisialisasi.
 * numAtomTypes diatur ke 0.
 */
void createMolecule(Molecule *m);

/**
 * @brief Menambahkan sejumlah atom dengan simbol tertentu ke dalam molekul.
 *
 * Jika atom dengan simbol tersebut sudah ada, jumlahnya akan ditambahkan.
 * Jika belum ada dan masih ada ruang (numAtomTypes < MAX_ATOM_TYPES),
 * atom baru akan ditambahkan ke dalam array atoms.
 * Jika sudah penuh, penambahan atom baru akan diabaikan.
 *
 * @param m Pointer ke Molecule yang akan ditambahkan atom.
 * @param symbol Simbol atom yang akan ditambahkan
 * @param count Jumlah atom yang akan ditambahkan.
 */
void addAtom(Molecule *m, const char *symbol, int count);

/**
 * @brief Mendapatkan perkiraan massa atom relatif (Ar).
 * (Ini adalah fungsi helper yang disediakan, JANGAN UBAH)
 * @param symbol Simbol atom.
 * @return double Massa atom relatif, atau 0.0 jika tidak diketahui.
 */
double getAtomicWeight(const char *symbol);

/**
 * @brief Menghitung perkiraan berat molekul total.
 *
 * Menggunakan fungsi helper getAtomicWeight
 * untuk mendapatkan massa atom relatif setiap jenis atom.
 *
 * @param m Pointer ke Molecule yang akan dihitung beratnya.
 * @return double Berat molekul total. Mengembalikan 0.0 jika molekul
 * kosong.
 */
double calculateMolecularWeight(const Molecule *m);

/**
 * @brief Mendapatkan jumlah atom dengan simbol tertentu dalam molekul.
 *
 * @param m Pointer ke Molecule yang akan dicari.
 * @param symbol Simbol atom yang jumlahnya ingin diketahui.
 * @return int Jumlah atom dengan simbol tersebut. Mengembalikan 0 jika
 * tidak ditemukan.
 */
int getAtomCount(const Molecule *m, const char *symbol);

/**
 * @brief Membandingkan dua molekul untuk kesetaraan komposisi.
 *
 * Dua molekul dianggap sama jika memiliki jenis atom yang sama
 * dengan jumlah yang sama untuk setiap jenis atom, *tidak peduli urutan
 * atom dalam array*.
 *
 * @param m1 Pointer ke Molecule pertama.
 * @param m2 Pointer ke Molecule kedua.
 * @return true Jika kedua molekul memiliki komposisi yang sama, false jika
 * tidak.
 */
bool areEqual(const Molecule *m1, const Molecule *m2);

/**
 * @brief Mencetak formula kimia molekul ke standar output.
 *
 * Format: Simbol diikuti jumlah jika jumlah > 1. Urutan cetak dilakukan sesuai
 * urutan indeks.
 * Contoh: C6H12O6, H2O, NaCl
 *
 * @param m Pointer ke Molecule yang akan dicetak formulanya.
 */
void printMoleculeFormula(const Molecule *m);

/**
 * @brief Menggabungkan dua molekul menjadi satu molekul baru.
 *
 * Membuat molekul baru yang berisi semua atom dari m1 dan m2.
 * Jumlah atom dengan simbol yang sama akan dijumlahkan.
 * Jika hasil penggabungan melebihi MAX_ATOM_TYPES, atom tambahan
 * dari m2 yang tidak muat akan diabaikan (sesuai perilaku addAtom).
 *
 * @param m1 Pointer ke Molecule pertama.
 * @param m2 Pointer ke Molecule kedua.
 * @return Molecule Molekul baru hasil penggabungan.
 */
Molecule combineMolecules(const Molecule *m1, const Molecule *m2);

/**
 * @brief Memeriksa apakah molekul m_sub dapat dikurangkan dari m_total.
 *
 * Pengecekan berhasil jika untuk setiap jenis atom dalam m_sub,
 * jumlah atom tersebut dalam m_total lebih besar atau sama.
 *
 * @param m_total Pointer ke Molecule total.
 * @param m_sub Pointer ke Molecule yang akan dikurangkan.
 * @return true Jika m_sub dapat dikurangkan dari m_total, false jika tidak.
 */
bool canSubtract(const Molecule *m_total, const Molecule *m_sub);

/**
 * @brief Mengurangkan molekul m_sub dari m_total dan mengembalikan hasilnya.
 *
 * Fungsi ini pertama-tama akan memanggil canSubtract.
 * Jika canSubtract mengembalikan false, fungsi ini akan mengembalikan
 * molekul kosong.
 * Jika canSubtract mengembalikan true, fungsi ini akan membuat molekul baru
 * yang merupakan salinan m_total, kemudian mengurangi jumlah setiap atom
 * yang ada di m_sub dari molekul baru tersebut. Atom dengan jumlah 0
 * setelah pengurangan sebaiknya diabaikan dalam perhitungan/pencetakan
 * selanjutnya.
 *
 * @param m_total Pointer ke Molecule total.
 * @param m_sub Pointer ke Molecule yang akan dikurangkan.
 * @return Molecule Molekul baru hasil pengurangan, atau molekul kosong jika
 * pengurangan tidak memungkinkan (canSubtract == false).
 */
Molecule subtractMolecule(const Molecule *m_total, const Molecule *m_sub);

#endif // MOLECULE_H