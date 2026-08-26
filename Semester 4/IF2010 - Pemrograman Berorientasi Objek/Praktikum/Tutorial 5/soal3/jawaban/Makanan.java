public class Makanan extends Barang {
    private int kalori;

    public Makanan(String nama, int harga, int kalori) {
        // TODO: implementasi
        super(nama, harga);
        this.kalori = kalori;
    }

    public int getKalori() {
        // TODO: implementasi
        return kalori;
    }

    @Override
    public String info() {
        // TODO: implementasi
        // Format: "[Makanan] nama - harga IDR (kalori kal)"
        return "[Makanan] " + nama + " - " + Integer.toString(harga) + " IDR (" + Integer.toString(kalori) + " kal)";
    }
}
