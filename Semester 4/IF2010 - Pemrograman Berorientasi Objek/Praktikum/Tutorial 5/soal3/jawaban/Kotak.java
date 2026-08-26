import java.util.ArrayList;

public class Kotak<T extends Barang> {
    private ArrayList<T> items;
    private int kapasitas;

    public Kotak(int kapasitas) {
        // TODO: implementasi
        items = new ArrayList<>(kapasitas);
        this.kapasitas = kapasitas;
    }

    public boolean tambah(T item) {
        // TODO: implementasi
        if(items.size() >= kapasitas) return false;
        items.add(item);
        return true;
    }

    public T ambil() {
        // TODO: implementasi (LIFO - ambil item terakhir)
        if(items.size() == 0) return null;
        else{ 
            T item = items.get(items.size()-1);
            items.remove(items.size() - 1);
            return item;
        }
    }

    public T lihat(int index) {
        // TODO: implementasi
        if(index < 0 || index >= items.size()) return null;
        return items.get(index);
    }

    public int jumlah() {
        // TODO: implementasi
        return items.size();
    }

    public int kapasitas() {
        // TODO: implementasi
        return kapasitas;
    }

    public boolean penuh() {
        // TODO: implementasi
        return jumlah() == kapasitas();
    }

    public boolean kosong() {
        // TODO: implementasi
        return jumlah() == 0;
    }
}
