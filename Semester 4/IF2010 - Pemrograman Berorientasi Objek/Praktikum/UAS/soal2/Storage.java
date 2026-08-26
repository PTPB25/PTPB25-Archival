import java.util.LinkedHashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

public class Storage<T> {
    private Map<String, T> data;
    private int capacity;

    public Storage(int capacity) {
        this.capacity = capacity;
        this.data = new LinkedHashMap<>();
    }

    public void store(id, item) {
        // TODO:
        // Tambahkan item ke dalam data dengan id sebagai key.
        // Jika kapasitas sudah penuh, lemparkan StorageFullException.
        // Jika kapasitas belum penuh namun id sudah ada di dalam data, lemparkan DuplicateIdException.
    }

    public retrieve(id) {
        // TODO:
        // Kembalikan item yang sesuai dengan id.
        // Jika id tidak ditemukan, lemparkan DataNotFoundException.
    }
    
    public void remove(id)  {
        // TODO:
        // Hapus item dengan id dari dalam data.
        // Jika id tidak ditemukan, lemparkan DataNotFoundException.
    }

    public List getAll() {
        // TODO:
        // Kembalikan semua item di dalam data dalam bentuk List.
    }
    
    public int getCapacity() {
        return this.capacity;
    }
    
    public int getSize() {
        if (this.data == null) {
            return 0;
        }
        return this.data.size();
    }
}
