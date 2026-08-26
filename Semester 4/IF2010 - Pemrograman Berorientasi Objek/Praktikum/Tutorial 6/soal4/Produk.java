@TableName("produk")
public class Produk {

    @ColumnName(value = "id_produk", primaryKey = true)
    private int id;

    @ColumnName(value = "nama_produk")
    private String namaProduk;

    @ColumnName(value = "harga")
    private double harga;

    public Produk() {}

    @Hook(when = Hook.When.POST_LOAD)
    private void normalizeName() {
        this.namaProduk = this.namaProduk.toUpperCase();
    }

    @Hook(when = Hook.When.PRE_INSERT)
    private void validateHarga() {
        if (this.harga <= 0) {
            throw new IllegalArgumentException("Harga harus positif");
        }
    }

    @Hook(when = Hook.When.PRE_DELETE)
    private void validateDelete() {
        if (this.id <= 0) {
            throw new IllegalStateException("ID produk tidak valid untuk dihapus");
        }
    }
}
