import java.util.List;

// Kelas utilitas dengan dua method statis untuk agregasi data.
// Method-method ini harus dapat menerima list batch dengan tipe numerik apapun
// (integer maupun desimal) tanpa duplikasi kode.
public class DataUtils {

    // Menjumlahkan hasil sum() dari semua batch. Kembalikan hasilnya sebagai double.
    public static double totalSum(List batches) {
        // TODO
        return 0;
    }

    // Mencari nilai item terbesar dari seluruh batch sebagai double.
    // Iterasi semua batch dan semua item, gunakan .doubleValue().
    // Mulai dari Double.NEGATIVE_INFINITY.
    public static double findMax(List batches) {
        // TODO
        return Double.NEGATIVE_INFINITY;
    }
}
