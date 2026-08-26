public class Pakaian extends Barang {
    private String ukuran;

    public Pakaian(String nama, int harga, String ukuran) {
        // TODO: implementasi
        super(nama, harga);
    }

    public String getUkuran() {
        // TODO: implementasi
        return null;
    }

    @Override
    public String info() {
        // TODO: implementasi
        // Format: "[Pakaian] nama - harga IDR (ukuran)"
        return null;
    }
}
