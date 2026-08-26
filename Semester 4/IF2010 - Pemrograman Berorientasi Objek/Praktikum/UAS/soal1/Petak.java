public class Petak {
    private Bidak[][] papan;
    private final int SIZE = 8;

    public Petak() {
        papan = new Bidak[SIZE][SIZE];
    }

    public boolean letakkanBidakAwal(Bidak b) {
        if (isDalamBatas(b.getX(), b.getY()) && papan[b.getY()][b.getX()] == null) {
            papan[b.getY()][b.getX()] = b;
            return true;
        }
        return false;
    }

    public boolean validasiDanPindah(Bidak b, int oldX, int oldY) {
        int newX = b.getX();
        int newY = b.getY();

        if (!isDalamBatas(newX, newY)) {
            System.out.println("[X] GAGAL: Gerakan akan membuat bidak keluar dari papan!");
            return false;
        }

        if ((newX != oldX || newY != oldY) && papan[newY][newX] != null) {
            System.out.println("[X] GAGAL: Tabrakan! Petak (" + newX + "," + newY + ") sudah diisi oleh " + papan[newY][newX].getSimbol());
            return false;
        }

        papan[oldY][oldX] = null; 
        papan[newY][newX] = b;
        return true;
    }

    private boolean isDalamBatas(int x, int y) {
        return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
    }

    public void cetakPapan() {
        System.out.println("\n    0  1  2  3  4  5  6  7 (X)");
        System.out.println("  +------------------------+");
        for (int y = 0; y < SIZE; y++) {
            System.out.print(y + " | ");
            for (int x = 0; x < SIZE; x++) {
                if (papan[y][x] == null) {
                    System.out.print(".  ");
                } else {
                    System.out.print(papan[y][x].getSimbol() + "  ");
                }
            }
            System.out.println("|");
        }
        System.out.println("  +------------------------+");
        System.out.println("(Y)\n");
    }
}