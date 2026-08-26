import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Petak petak = new Petak();
        List<Bidak> daftarBidak = new ArrayList<>();

        daftarBidak.add(new Bishop(2, 4, 1)); // B di (2,4)
        daftarBidak.add(new Knight(4, 4, 2)); // K di (4,4)
        daftarBidak.add(new Rook(6, 6, 3));   // P di (6,6)

        for (Bidak b : daftarBidak) {
            petak.letakkanBidakAwal(b);
        }

        System.out.println("=== SIMULASI OOP CATUR ===");
        
        while (true) {
            petak.cetakPapan();

            System.out.println("Status Bidak:");
            for (Bidak b : daftarBidak) {
                System.out.println("[ID: " + b.getId() + "] " + b.getClass().getSimpleName() + " di kordinat (" + b.getX() + "," + b.getY() + ")");
            }
            
            System.out.println("\n[0] Keluar Aplikasi");
            System.out.print("Pilih ID Bidak yang ingin dimainkan: ");
            int pilihanId = scanner.nextInt();

            if (pilihanId == 0) {
                System.out.println("Aplikasi dihentikan.");
                break;
            }

            Bidak bidakAktif = null;
            for (Bidak b : daftarBidak) {
                if (b.getId() == pilihanId) {
                    bidakAktif = b;
                    break;
                }
            }

            if (bidakAktif == null) {
                System.out.println("[X] Error: ID Bidak tidak ditemukan!\n");
                continue;
            }

            System.out.println("Pilih Arah Pergerakan:");
            for(String s: bidakAktif.actions){
                System.out.println(s);
            }
            System.out.print("Arah Pergerakan: ");
            int aksi = scanner.nextInt();
            
            int oldX = bidakAktif.getX();
            int oldY = bidakAktif.getY();
            
            Optional<Integer> steps = Optional.empty();
            if(!(bidakAktif instanceof Knight)){
                System.out.print("Sebut berapa langkah: ");
                steps = Optional.of(scanner.nextInt());
            }

            switch (aksi) {
                case 1: bidakAktif.atas(steps); break;
                case 2: bidakAktif.atasKanan(steps); break;
                case 3: bidakAktif.kanan(steps); break;
                case 4: bidakAktif.atasKiri(steps); break;
                case 5: bidakAktif.kiri(steps); break;
                case 6: bidakAktif.bawahKanan(steps); break;
                case 7: bidakAktif.bawah(steps); break;
                case 8: bidakAktif.bawahKiri(steps); break;
                default: 
                    System.out.println("[X] Error: Pilihan arah tidak valid!"); 
                    continue;
            }

            boolean berhasil = petak.validasiDanPindah(bidakAktif, oldX, oldY);

            if (!berhasil || (bidakAktif.getX() == oldX && bidakAktif.getY() == oldY)) {
                bidakAktif.setPosisi(oldX, oldY); // Kembalikan posisi x dan y
            } else {
                System.out.println("[V] SUKSES: Bidak dipindahkan!");
            }
        }
        
        scanner.close();
    }
}