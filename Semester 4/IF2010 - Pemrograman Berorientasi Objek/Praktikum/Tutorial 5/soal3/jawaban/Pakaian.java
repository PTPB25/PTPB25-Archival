public class Pakaian extends Barang {
    private String ukuran;

    public Pakaian(String nama, int harga, String ukuran) {
        // TODO: implementasi
        super(nama, harga);
        this.ukuran = ukuran;
    }

    public String getUkuran() {
        // TODO: implementasi
        return ukuran;
    }

    @Override
    public String info() {
        // TODO: implementasi
        // Format: "[Pakaian] nama - harga IDR (ukuran)"
        return "[Pakaian] " + nama + " - " + Integer.toString(harga) + " IDR (" + ukuran + ")";
    }
}
