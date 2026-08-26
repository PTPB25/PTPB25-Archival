import java.util.*;

public class DapurJus {
    private DapurJus(){}

    static void cekBahan(List<? extends Buah> daftarBahan){
        for(Buah buah : daftarBahan){
            System.out.println(buah.getNama() + " dengan tingkat manis " + Integer.toString(buah.getTingkatManis()));
        }
    }
    static int hitungTotalManis(List<? extends Buah> daftarBahan){
        int sum = 0;
        for(Buah buah : daftarBahan){
            sum += buah.getTingkatManis();
        } return sum;
    }
    static void buatJusApelDefault(List<? super JusApel> daftarMinuman){
        daftarMinuman.add(new JusApel("Jus Apel Original"));
        daftarMinuman.add(new JusApel("Jus Apel Madu"));
    }
    static void cetakRakUmum(List<?> rak){
        for(Object item : rak){
            System.out.println(item);
        }
    }
}