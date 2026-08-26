public class Minuman {
    private String nama;

    public Minuman(String nama) {
        this.nama = nama;
    }

    public String getNama() {
        return nama;
    }

    public String deskripsi() {
        return "Minuman: " + nama;
    }

    @Override
    public String toString() {
        return deskripsi();
    }
}