import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);

        // Baca N dan data array
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Baca W = panjang window
        // Baca T = jumlah thread yang diinginkan
        int W = sc.nextInt();
        int T = sc.nextInt();

        if (T <= 0) {
            System.out.println("Jumlah thread harus >= 1");
            sc.close();
            return;
        }

        int M = N - W + 1;
        if (M <= 0) {
            System.out.println("Window tidak valid");
            sc.close();
            return;
        }

        int[] sums = new int[M];
        String[] logs = new String[T];
        Thread[] threads = new Thread[T];

        // TODO
        // 1. Hitung pembagian Thread
        //    Bagi window berurutan ke dalam T threads sedemikian rupa sehingga selisih jumlah window antar thread <= 1.
        //    Jika M tidak habis dibagi T, maka thread dengan indeks lebih kecil akan mendapatkan 1 window ekstra.
        //    Contoh:
        //      N = 8
        //      Array = [1, 2, 3, 4, 5, 6, 7, 8]
        //      T = 3
        //      W = 4
        //      Maka ada 5 Window yang masing-masing mulai dari idx 0, 1, 2, 3, 4
        //      dengan banyak elemen W = 4
        //      Bagi ke 3 Threads
        //      Thread 0 (2 window)
        //          Window idx [0..4) (1, 2, 3, 4), sum = 10
        //          Window idx [1..5), sum = 14
        //      Thread 1 (2 window)
        //          Window idx [2..6), sum = 18
        //          Window idx [3..7), sum = 22
        //      Thread 2 (1 window)
        //          Window idx [4..8), sum = 26
        // 2. Start setiap thread
        // 3. Sinkronisasi semua Thread

        // Output, tidak perlu diubah
        for (int i = 0; i < T; i++) {
            System.out.println(logs[i]);
        }

        sc.close();
    }
}
