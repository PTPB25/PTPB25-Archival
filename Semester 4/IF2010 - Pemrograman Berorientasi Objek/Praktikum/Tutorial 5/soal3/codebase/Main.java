import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int capE = sc.nextInt();
        int capM = sc.nextInt();
        int capP = sc.nextInt();
        int capC = sc.nextInt();

        Kotak<Elektronik> kotakE = new Kotak<>(capE);
        Kotak<Makanan> kotakM = new Kotak<>(capM);
        Kotak<Pakaian> kotakP = new Kotak<>(capP);
        Kotak<Barang> kotakC = new Kotak<>(capC);

        int Q = sc.nextInt();
        sc.nextLine();

        while (Q-- > 0) {
            String line = sc.nextLine();
            String[] parts = line.split(" ");
            String cmd = parts[0];

            switch (cmd) {
                case "ADDE": {
                    String nama = parts[1];
                    int harga = Integer.parseInt(parts[2]);
                    int watt = Integer.parseInt(parts[3]);
                    Elektronik e = new Elektronik(nama, harga, watt);
                    if (kotakE.tambah(e)) {
                        System.out.println("Ditambahkan: " + e.info());
                    } else {
                        System.out.println("Gagal: Kotak penuh!");
                    }
                    break;
                }
                case "ADDM": {
                    String nama = parts[1];
                    int harga = Integer.parseInt(parts[2]);
                    int kalori = Integer.parseInt(parts[3]);
                    Makanan m = new Makanan(nama, harga, kalori);
                    if (kotakM.tambah(m)) {
                        System.out.println("Ditambahkan: " + m.info());
                    } else {
                        System.out.println("Gagal: Kotak penuh!");
                    }
                    break;
                }
                case "ADDP": {
                    String nama = parts[1];
                    int harga = Integer.parseInt(parts[2]);
                    String ukuran = parts[3];
                    Pakaian p = new Pakaian(nama, harga, ukuran);
                    if (kotakP.tambah(p)) {
                        System.out.println("Ditambahkan: " + p.info());
                    } else {
                        System.out.println("Gagal: Kotak penuh!");
                    }
                    break;
                }
                case "PRINT": {
                    int n = Integer.parseInt(parts[1]);
                    switch (n) {
                        case 1: KotakUtils.tampilkanSemua(kotakE); break;
                        case 2: KotakUtils.tampilkanSemua(kotakM); break;
                        case 3: KotakUtils.tampilkanSemua(kotakP); break;
                        case 4: KotakUtils.tampilkanSemua(kotakC); break;
                    }
                    break;
                }
                case "TOTAL": {
                    int n = Integer.parseInt(parts[1]);
                    int total = 0;
                    switch (n) {
                        case 1: total = KotakUtils.totalHarga(kotakE); break;
                        case 2: total = KotakUtils.totalHarga(kotakM); break;
                        case 3: total = KotakUtils.totalHarga(kotakP); break;
                        case 4: total = KotakUtils.totalHarga(kotakC); break;
                    }
                    System.out.println("Total: " + total);
                    break;
                }
                case "MAHAL": {
                    int n = Integer.parseInt(parts[1]);
                    Barang b = null;
                    switch (n) {
                        case 1: b = KotakUtils.termahal(kotakE); break;
                        case 2: b = KotakUtils.termahal(kotakM); break;
                        case 3: b = KotakUtils.termahal(kotakP); break;
                        case 4: b = KotakUtils.termahal(kotakC); break;
                    }
                    if (b == null) {
                        System.out.println("Kotak kosong");
                    } else {
                        System.out.println(b.info());
                    }
                    break;
                }
                case "COUNT": {
                    int n = Integer.parseInt(parts[1]);
                    int count = 0;
                    switch (n) {
                        case 1: count = KotakUtils.hitungItem(kotakE); break;
                        case 2: count = KotakUtils.hitungItem(kotakM); break;
                        case 3: count = KotakUtils.hitungItem(kotakP); break;
                        case 4: count = KotakUtils.hitungItem(kotakC); break;
                    }
                    System.out.println("Jumlah: " + count);
                    break;
                }
                case "TRANSFER": {
                    int n = Integer.parseInt(parts[1]);
                    int moved = 0;
                    switch (n) {
                        case 1: moved = KotakUtils.pindahkan(kotakE, kotakC); break;
                        case 2: moved = KotakUtils.pindahkan(kotakM, kotakC); break;
                        case 3: moved = KotakUtils.pindahkan(kotakP, kotakC); break;
                    }
                    System.out.println("Dipindahkan: " + moved + " item");
                    break;
                }
            }
        }
    }
}
