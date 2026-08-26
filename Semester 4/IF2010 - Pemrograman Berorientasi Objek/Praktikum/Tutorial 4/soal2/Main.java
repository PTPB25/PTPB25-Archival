import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine(); // buang newline

        Character[] daftar = new Character[n];

        int i = 0;
        while (i < n) {
            String jenis = sc.next();
            String nama = sc.next();
            int level = sc.nextInt();
            double powerBase = sc.nextDouble();

            if (jenis.equals("M")) {
                int magicalAtk = sc.nextInt();
                daftar[i] = new Mage(nama, level, powerBase, magicalAtk);
                i++;
            } else if (jenis.equals("F")) {
                int physicalAtk = sc.nextInt();
                daftar[i] = new Fighter(nama, level, powerBase, physicalAtk);
                i++;
            } else {
                // kalau input tidak valid
                System.out.println("Unknown Character Role");
            }
        }

        System.out.println("\n=== Character List ===");
        for (int j = 0; j < n; j++) {
            daftar[j].printInfo();
            System.out.println();
        }

        sc.close();
    }
}