import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Apel> daftarApel = new ArrayList<>();
        daftarApel.add(new Apel("Apel Fuji", 8));
        daftarApel.add(new Apel("Apel Malang", 7));

        List<Pisang> daftarPisang = new ArrayList<>();
        daftarPisang.add(new Pisang("Pisang Ambon", 9));

        List<JusApel> gelasJusApel = new ArrayList<>();
        List<JusBuah> gelasJusBuah = new ArrayList<>();

        System.out.println("=== CEK BAHAN APEL ===");
        DapurJus.cekBahan(daftarApel);

        System.out.println("\n=== CEK BAHAN PISANG ===");
        DapurJus.cekBahan(daftarPisang);

        System.out.println("\n=== TOTAL MANIS APEL ===");
        System.out.println(DapurJus.hitungTotalManis(daftarApel));

        System.out.println("\n=== BUAT JUS APEL KE DALAM GELAS APEL ===");
        DapurJus.buatJusApelDefault(gelasJusApel);
        DapurJus.cetakRakUmum(gelasJusApel);

        System.out.println("\n=== BUAT JUS APEL KE DALAM GELAS BUAH ===");
        DapurJus.buatJusApelDefault(gelasJusBuah);
        DapurJus.cetakRakUmum(gelasJusBuah);
    }
}