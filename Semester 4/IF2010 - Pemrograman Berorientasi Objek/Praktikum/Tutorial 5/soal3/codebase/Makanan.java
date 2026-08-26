public class Makanan extends Barang {
    private int kalori;

    public Makanan(String nama, int harga, int kalori) {
        // TODO: implementasi
        super(nama, harga);
    }

    public int getKalori() {
        // TODO: implementasi
        return 0;
    }

    @Override
    public String info() {
        // TODO: implementasi
        // Format: "[Makanan] nama - harga IDR (kalori kal)"
        return null;
    }
}
