import java.util.ArrayList;

public class Kotak<T extends Barang> {
    private ArrayList<T> items;
    private int kapasitas;

    public Kotak(int kapasitas) {
        // TODO: implementasi
    }

    public boolean tambah(T item) {
        // TODO: implementasi
        return false;
    }

    public T ambil() {
        // TODO: implementasi (LIFO - ambil item terakhir)
        return null;
    }

    public T lihat(int index) {
        // TODO: implementasi
        return null;
    }

    public int jumlah() {
        // TODO: implementasi
        return 0;
    }

    public int kapasitas() {
        // TODO: implementasi
        return 0;
    }

    public boolean penuh() {
        // TODO: implementasi
        return false;
    }

    public boolean kosong() {
        // TODO: implementasi
        return false;
    }
}
