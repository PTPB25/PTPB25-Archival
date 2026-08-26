import java.util.List;

// Kelas utilitas dengan dua method statis untuk agregasi data.
// Method-method ini harus dapat menerima list batch dengan tipe numerik apapun
// (integer maupun desimal) tanpa duplikasi kode.
public class DataUtils {

    // Menjumlahkan hasil sum() dari semua batch. Kembalikan hasilnya sebagai double.
    public static double totalSum(List<DataBatch<? extends Number>> batches) {
        // TODO
        double sum = 0;
        for(DataBatch<? extends Number> batch : batches){
            sum += batch.sum();
        }
        return sum;
    }

    // Mencari nilai item terbesar dari seluruh batch sebagai double.
    // Iterasi semua batch dan semua item, gunakan .doubleValue().
    // Mulai dari Double.NEGATIVE_INFINITY.
    public static double findMax(List<DataBatch<? extends Number>> batches) {
        // TODO
        double max = Double.NEGATIVE_INFINITY;
        for(DataBatch<? extends Number> batch : batches){
            List<? extends Number> items = batch.getItems();
            double curmax = items.stream().map(item -> item.doubleValue()).max(Double::compare).orElse(0.0);
            if(curmax > max) max = curmax;
        }
        return max;
    }
}
