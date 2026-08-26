public class Buah {
    private String nama;
    private int tingkatManis;

    public Buah(String nama, int tingkatManis) {
        this.nama = nama;
        this.tingkatManis = tingkatManis;
    }

    public String getNama() {
        return nama;
    }

    public int getTingkatManis() {
        return tingkatManis;
    }

    public String deskripsi() {
        return nama + " dengan tingkat manis " + tingkatManis;
    }
}