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
        if(stock < 0){
            throw new IllegalArgumentException("stock tidak boleh negatif");
        }
        // assert stock >= 0 : "stock tidak boleh negatif";
        //
        // Price harus bernilai positif.
        // Jika tidak valid, hentikan pembuatan objek dengan pesan:
        // "price harus bernilai positif".

        if(price <= 0){
            throw new IllegalArgumentException("price harus bernilai positif");
        }
        // assert price > 0 : "price harus bernilai positif";
        //
        // Jika semua nilai valid, simpan stock dan price ke atribut.
        // Balance awal adalah 0.   
        this.balance = 0;
        this.price = price;
        this.stock = stock;
        checkInvariant();
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

        if(amount <= 0){
            throw new IllegalArgumentException("amount harus bernilai positif");
        } 

        // assert amount > 0 : "amount harus bernilai positif";
        this.balance += amount;
        //
        // Jika valid, tambahkan amount ke balance.
        //
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
        checkInvariant();
    }

    public String buy() {
        // TODO:
        // Proses pembelian item dari vending machine.
        //
        // Pembelian tidak dapat dilakukan jika stock sudah kosong.
        // Jika kondisi ini terjadi, hentikan operasi dengan pesan:
        // "stock kosong".
        
        // assert stock > 0 : "stock kosong";
        if(stock <= 0){
            throw new IllegalStateException("stock kosong");
        }

        //
        // Pembelian juga tidak dapat dilakukan jika balance kurang dari price.
        // Jika kondisi ini terjadi, hentikan operasi dengan pesan:
        // "balance tidak cukup".
        // assert balance >= price : "balance tidak cukup"
        if(balance < price){
            throw new IllegalStateException("balance tidak cukup");
        }

        //
        // Jika pembelian valid, kurangi stock sebanyak 1
        // dan kurangi balance sebesar price.
        this.stock -= 1;
        this.balance -= this.price;
        //
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
        checkInvariant();
        //
        // Kembalikan string:
        // "Item berhasil terbeli".

        return "Item berhasil terbeli";
    }

    public int refund() {
        // TODO:
        // Kembalikan seluruh balance yang tersimpan di mesin.
        //
        // Simpan nilai balance saat ini ke variabel sementara.
        // Setelah itu, ubah balance menjadi 0.
        int temp = balance;
        balance = 0;
        checkInvariant();
        //
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
        //
        // Kembalikan nilai uang yang dikembalikan.

        return temp;
    }

    public String status() {
        // TODO:
        // Kembalikan informasi state mesin dengan format:
        // "Stock: stock, Balance: balance, Price: price"
        //
        // Contoh:
        // "Stock: 2, Balance: 5000, Price: 3000"

        return "Stock: " + Integer.toString(stock) + ", Balance: " + Integer.toString(balance) + ", Price: " + Integer.toString(price);
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
        assert stock >= 0 : "Invalid stock state";
        assert balance >= 0 : "Invalid balance state";
        assert price > 0 : "Invalid price state";
    }
}