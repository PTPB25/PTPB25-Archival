import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in).useLocale(Locale.US);

        int N = sc.nextInt();
        int T = sc.nextInt();

        // Baca N batch, bisa campuran INT dan DOUBLE
        List<DataBatch<? extends Number>> allBatches = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String type = sc.next();
            String label = sc.next();
            int k = sc.nextInt();

            if (type.equals("INT")) {
                DataBatch<Integer> batch = new DataBatch<>(label);
                for (int j = 0; j < k; j++) {
                    batch.add(sc.nextInt());
                }
                allBatches.add(batch);
            } else {
                DataBatch<Double> batch = new DataBatch<>(label);
                for (int j = 0; j < k; j++) {
                    batch.add(sc.nextDouble());
                }
                allBatches.add(batch);
            }
        }

        // Bagi N batch ke T thread
        // Thread dengan indeks < (N % T) mendapat satu batch ekstra
        int base = N / T;
        int extra = N % T;

        String[] logs = new String[T];
        Thread[] threads = new Thread[T];
        int[] totalItems = {0};
        Object lock = new Object();

        int start = 0;
        for (int i = 0; i < T; i++) {
            int count = base + (i < extra ? 1 : 0);
            List<DataBatch<? extends Number>> sub =
                new ArrayList<>(allBatches.subList(start, start + count));
            threads[i] = new Thread(new BatchProcessor(sub, i, logs, totalItems, lock));
            start += count;
        }

        // TODO: reset ThreadTracker, jalankan semua thread secara paralel,
        // tunggu hingga seluruh pemrosesan selesai, lalu verifikasi jumlah
        // thread yang digunakan dengan ThreadTracker.

        // Output, jangan diubah bagian ini
        for (String log : logs) {
            System.out.println(log);
        }
        System.out.println("Total items processed: " + totalItems[0]);
        System.out.printf(Locale.US, "Total sum: %.1f%n", DataUtils.totalSum(allBatches));
        System.out.printf(Locale.US, "Max: %.1f%n", DataUtils.findMax(allBatches));

        sc.close();
    }
}
