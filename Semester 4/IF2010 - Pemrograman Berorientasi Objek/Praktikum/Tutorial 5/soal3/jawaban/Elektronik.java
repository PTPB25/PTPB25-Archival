public class Elektronik extends Barang {
    private int watt;

    public Elektronik(String nama, int harga, int watt) {
        // TODO: implementasi
        super(nama, harga);
        this.watt = watt;
    }

    public int getWatt() {
        // TODO: implementasi
        return watt;
    }

    @Override
    public String info() {
        // TODO: implementasi
        // Format: "[Elektronik] nama - harga IDR (wattW)"
        return "[Elektronik] " + nama + " - " + Integer.toString(harga) + " IDR (" + Integer.toString(watt) + "W)";
    }
}
