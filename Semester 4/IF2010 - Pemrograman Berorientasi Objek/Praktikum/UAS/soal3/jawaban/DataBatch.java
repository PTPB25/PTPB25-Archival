import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// Kelas generik yang merepresentasikan satu batch data sensor berlabel.
// Kelas ini harus dapat menampung nilai numerik dari berbagai tipe.
public class DataBatch<T extends Number> {
    private final String label;
    private final List<T> items;

    // Membuat batch baru dengan label yang diberikan. Inisialisasi list items sebagai kosong.
    public DataBatch(String label) {
        this.label = label;
        this.items = new ArrayList<T>();
        // TODO
    }

    // Menambahkan satu item ke dalam batch.
    public void add(T item) {
        items.add(item);
        // TODO
    }

    // Mengembalikan daftar item (tidak dapat dimodifikasi).
    public List<T> getItems() {
        // TODO
        return items;
    }

    // Mengembalikan label batch ini.
    public String getLabel() {
        // TODO
        return label;
    }

    // Menghitung total nilai semua item sebagai double.
    // Gunakan .doubleValue() saat mengkonversi setiap item.
    public double sum() {
        // TODO
        return items.stream().map(item -> item.doubleValue()).reduce((a, b) -> a + b).orElse(0.0);
    }
}
