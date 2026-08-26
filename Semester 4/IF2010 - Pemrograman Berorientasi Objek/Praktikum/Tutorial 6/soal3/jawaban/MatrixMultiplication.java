import java.util.ArrayList;
import java.util.List;

public class MatrixMultiplication implements Runnable {
    
    // Di dalam method run() dalam runnable WAJIB panggil ThreadTracker.mark();
    // Misal :
    // new Thread(() -> {
    //     ThreadTracker.mark(); <- tambahkan ini ketika ingin submit jawaban
    //     //kode lainnya
    // });
    //
    // Atau
    //
    // run(){
    //   ThreadTracker.mark(); <- tambahkan ini ketika ingin submit jawaban
    //   //kode lainnya
    // }
    private final int[][] A, B, C;
    private final List<Integer> rows;
    public MatrixMultiplication(int[][] A, int[][] B, int[][] C, List<Integer> rows) {
        this.A = A;
        this.B = B;
        this.C = C;
        this.rows = rows;
    }
    public void run(){
        ThreadTracker.mark();
        if(rows.size() == 0) return;
        for(int row : rows){
            for(int i = 0; i < B[0].length; i++){
                C[row][i] = 0;
                for(int j = 0; j < A[row].length; j++){
                    C[row][i] += A[row][j] * B[j][i];
                }
            }
        }
    }
    
    public static int[][] multiply(int[][] A, int[][] B) throws InterruptedException {
        int m = A.length;
        int p = B[0].length;

        int[][] C = new int[m][p];
        ThreadTracker.reset();
        Thread[] threads = new Thread[10];

        for (int i = 0; i < 10; i++) {
            List<Integer> rows = new ArrayList<>();
            for (int j = i; j < m; j += 10) {
                rows.add(j);
            }
            threads[i] = new Thread(new MatrixMultiplication(A, B, C, rows));
            threads[i].start();
        }
        for (int j = 0; j < 10; j++){
            threads[j].join();
        }
        ThreadTracker.verifyUsedMultipleThreads();
        return C;
    }
}
