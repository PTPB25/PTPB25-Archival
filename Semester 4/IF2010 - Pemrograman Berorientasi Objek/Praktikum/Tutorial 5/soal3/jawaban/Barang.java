public abstract class Barang {
    protected String nama;
    protected int harga;

    public Barang(String nama, int harga) {
        // TODO: implementasi
        this.nama = nama;
        this.harga = harga;
    }

    public String getNama() {
        // TODO: implementasi
        return nama;
    }

    public int getHarga() {
        // TODO: implementasi
        return harga;
    }

    public abstract String info();
}
