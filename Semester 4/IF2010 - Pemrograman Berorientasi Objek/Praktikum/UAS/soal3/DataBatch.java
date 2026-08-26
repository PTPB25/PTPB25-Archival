import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// Kelas generik yang merepresentasikan satu batch data sensor berlabel.
// Kelas ini harus dapat menampung nilai numerik dari berbagai tipe.
public class DataBatch {
    private final String label;
    private final List items;

    // Membuat batch baru dengan label yang diberikan. Inisialisasi list items sebagai kosong.
    public DataBatch(String label) {
        // TODO
    }

    // Menambahkan satu item ke dalam batch.
    public void add(Object item) {
        // TODO
    }

    // Mengembalikan daftar item (tidak dapat dimodifikasi).
    public List getItems() {
        // TODO
        return null;
    }

    // Mengembalikan label batch ini.
    public String getLabel() {
        // TODO
        return null;
    }

    // Menghitung total nilai semua item sebagai double.
    // Gunakan .doubleValue() saat mengkonversi setiap item.
    public double sum() {
        // TODO
        return 0;
    }
}
