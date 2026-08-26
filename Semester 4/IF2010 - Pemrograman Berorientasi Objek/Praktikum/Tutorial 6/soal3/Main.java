public class Main {
    public static void main(String[] args) throws InterruptedException {
        int[][] A = {
            {1, 2, 3},
            {4, 5, 6},          
            {7, 8, 9}
        };
        int[][] B = {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}       
        };
        int[][] C = MatrixMultiplication.multiply(A, B);
        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < C[0].length; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.println();  
        }
        
    }
}