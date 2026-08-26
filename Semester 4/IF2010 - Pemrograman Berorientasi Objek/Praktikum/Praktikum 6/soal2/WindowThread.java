/**
 * Worker untuk menghitung sum sliding window rentang indeks tertentu.
 *
 * Objek ini menerima array data lengkap, array output untuk hasil window,
 * serta rentang indeks window [startWin, endWin) yang harus dihitung.
 * Hasil per window ditulis ke sums[i] dan ringkasan hasil per thread
 * disimpan ke logs[threadIndex] dengan format yang sudah ditentukan.
 */
public class WindowThread {
    private final int[] data;
    private final int[] sums;
    private final int startWin;
    private final int endWin;
    private final int windowSize;
    private final int threadIndex;
    private final String[] logs;

    /**
     * Membuat worker untuk menghitung jumlah window rentang tertentu.
     *
     * @param data array input berisi N angka
     * @param sums array output untuk menyimpan hasil window (ukuran M)
     * @param startWin indeks window awal (inklusif)
     * @param endWin indeks window akhir (eksklusif)
     * @param windowSize ukuran window (W)
     * @param threadIndex indeks thread untuk penempatan log
     * @param logs array untuk menyimpan log tiap thread
     */
    public WindowThread(int[] data, int[] sums, int startWin, int endWin, int windowSize,
                        int threadIndex, String[] logs) {
        this.data = data;
        this.sums = sums;
        this.startWin = startWin;
        this.endWin = endWin;
        this.windowSize = windowSize;
        this.threadIndex = threadIndex;
        this.logs = logs;
    }

    /**
     * Menghitung jumlah setiap window pada rentang yang diberikan dan menyimpan
     * hasilnya ke array output, lalu menyusun log hasil untuk thread ini.
     */
    @Override
    public void run() {
        // TODO: hitung window sum untuk indeks [startWin, endWin) lalu simpan di array sums

        // Format output, jangan diubah. Hanya baris sebelum ini yang dapat diubah
        StringBuilder sb = new StringBuilder();
        sb.append("Thread ").append(threadIndex).append(":\n");
        for (int i = startWin; i < endWin; i++) {
            sb.append("window idx ").append(i).append(", sum = ").append(sums[i]).append("\n");
        }
        logs[threadIndex] = sb.toString();
    }
}
