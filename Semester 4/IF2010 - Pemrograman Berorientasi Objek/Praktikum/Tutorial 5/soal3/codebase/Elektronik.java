public class Elektronik extends Barang {
    private int watt;

    public Elektronik(String nama, int harga, int watt) {
        // TODO: implementasi
        super(nama, harga);
    }

    public int getWatt() {
        // TODO: implementasi
        return 0;
    }

    @Override
    public String info() {
        // TODO: implementasi
        // Format: "[Elektronik] nama - harga IDR (wattW)"
        return null;
    }
}
