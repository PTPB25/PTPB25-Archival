import java.util.List;
import java.util.Locale;

// Kelas yang mengimplementasikan Runnable dan memproses sebagian dari daftar batch secara paralel.
public class BatchProcessor implements Runnable {
    private final List batches;
    private final int threadIndex;
    private final String[] logs;
    private final int[] totalItems;
    private final Object lock;

    // Simpan semua parameter ke atribut.
    public BatchProcessor(List batches, int threadIndex, String[] logs,
                          int[] totalItems, Object lock) {
        // TODO
    }

    @Override
    public void run() {
        // 1. Panggil ThreadTracker.mark() sebagai baris pertama.

        // 2. Bangun string log untuk thread ini dan simpan ke logs[threadIndex].
        //    Format:
        //      Thread <threadIndex>:
        //      Batch <label>: sum = <sum>
        //      Batch <label>: sum = <sum>
        //      ...
        //    Gunakan format %.1f untuk sum dengan Locale.US.

        // 3. Hitung total elemen dari semua batch yang ditugaskan ke thread ini.

        // 4. Update totalItems[0] secara thread-safe menggunakan lock.

        // TODO
    }
}
