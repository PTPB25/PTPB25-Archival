public class VendingMachine {
    private int stock;
    private int balance;
    private int price;

    public VendingMachine(int stock, int price) {
        // TODO:
        // Validasi nilai awal mesin.
        //
        // Stock awal tidak boleh bernilai negatif.
        // Jika tidak valid, hentikan pembuatan objek dengan pesan:
        // "stock tidak boleh negatif".
        //
        // Price harus bernilai positif.
        // Jika tidak valid, hentikan pembuatan objek dengan pesan:
        // "price harus bernilai positif".
        //
        // Jika semua nilai valid, simpan stock dan price ke atribut.
        // Balance awal adalah 0.
        //
        // Setelah state disimpan, pastikan invariant mesin tetap terpenuhi.
    }

    public void insertMoney(int amount) {
        // TODO:
        // Validasi jumlah uang yang dimasukkan.
        //
        // Amount harus bernilai positif.
        // Jika tidak valid, hentikan operasi dengan pesan:
        // "amount harus bernilai positif".
        //
        // Jika valid, tambahkan amount ke balance.
        //
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
    }

    public String buy() {
        // TODO:
        // Proses pembelian item dari vending machine.
        //
        // Pembelian tidak dapat dilakukan jika stock sudah kosong.
        // Jika kondisi ini terjadi, hentikan operasi dengan pesan:
        // "stock kosong".
        //
        // Pembelian juga tidak dapat dilakukan jika balance kurang dari price.
        // Jika kondisi ini terjadi, hentikan operasi dengan pesan:
        // "balance tidak cukup".
        //
        // Jika pembelian valid, kurangi stock sebanyak 1
        // dan kurangi balance sebesar price.
        //
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
        //
        // Kembalikan string:
        // "Item berhasil terbeli".

        return "";
    }

    public int refund() {
        // TODO:
        // Kembalikan seluruh balance yang tersimpan di mesin.
        //
        // Simpan nilai balance saat ini ke variabel sementara.
        // Setelah itu, ubah balance menjadi 0.
        //
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
        //
        // Kembalikan nilai uang yang dikembalikan.

        return 0;
    }

    public String status() {
        // TODO:
        // Kembalikan informasi state mesin dengan format:
        // "Stock: stock, Balance: balance, Price: price"
        //
        // Contoh:
        // "Stock: 2, Balance: 5000, Price: 3000"

        return "";
    }

    private void checkInvariant() {
        // TODO:
        // Pastikan invariant internal mesin selalu terpenuhi:
        //
        // stock tidak boleh negatif
        // balance tidak boleh negatif
        // price harus bernilai positif
        //
        // Gunakan pesan berikut jika invariant gagal:
        // "Invalid stock state"
        // "Invalid balance state"
        // "Invalid price state"
    }
}