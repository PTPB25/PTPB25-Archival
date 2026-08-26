import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());

        LaciAngka<Integer> laciInt = new LaciAngka<>("Integer");
        LaciAngka<Double> laciDbl = new LaciAngka<>("Double");
        Laci<String> laciStr = new Laci<>("String");

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();
            String[] parts = line.split(" ");
            String cmd = parts[0];

            if (cmd.equals("SIMPAN")) {
                String tipe = parts[1];
                if (tipe.equals("INT")) {
                    int val = Integer.parseInt(parts[2]);
                    laciInt.simpan(val);
                    System.out.println("Disimpan: " + val);
                } else if (tipe.equals("DBL")) {
                    double val = Double.parseDouble(parts[2]);
                    laciDbl.simpan(val);
                    System.out.println("Disimpan: " + val);
                } else if (tipe.equals("STR")) {
                    String val = parts[2];
                    laciStr.simpan(val);
                    System.out.println("Disimpan: " + val);
                }

            } else if (cmd.equals("AMBIL")) {
                String tipe = parts[1];
                int idx = Integer.parseInt(parts[2]);
                if (tipe.equals("INT")) {
                    Integer val = laciInt.ambil(idx);
                    System.out.println(val != null ? val : "null");
                } else if (tipe.equals("DBL")) {
                    Double val = laciDbl.ambil(idx);
                    System.out.println(val != null ? val : "null");
                } else if (tipe.equals("STR")) {
                    String val = laciStr.ambil(idx);
                    System.out.println(val != null ? val : "null");
                }

            } else if (cmd.equals("TOTAL")) {
                String tipe = parts[1];
                if (tipe.equals("INT")) {
                    System.out.println("Total: " + laciInt.total());
                } else if (tipe.equals("DBL")) {
                    System.out.println("Total: " + laciDbl.total());
                }

            } else if (cmd.equals("RATA")) {
                String tipe = parts[1];
                if (tipe.equals("INT")) {
                    System.out.println("Rata-rata: " + laciInt.rataRata());
                } else if (tipe.equals("DBL")) {
                    System.out.println("Rata-rata: " + laciDbl.rataRata());
                }

            } else if (cmd.equals("TUKAR")) {
                String tipe = parts[1];
                int i1 = Integer.parseInt(parts[2]);
                int j1 = Integer.parseInt(parts[3]);
                if (tipe.equals("INT")) {
                    LaciUtil.tukar(laciInt, i1, j1);
                } else if (tipe.equals("STR")) {
                    LaciUtil.tukar(laciStr, i1, j1);
                }

            } else if (cmd.equals("TERBESAR")) {
                String tipe = parts[1];
                if (tipe.equals("INT")) {
                    Integer val = LaciUtil.terbesar(laciInt);
                    System.out.println(val != null ? val : "Laci kosong");
                } else if (tipe.equals("STR")) {
                    String val = LaciUtil.terbesar(laciStr);
                    System.out.println(val != null ? val : "Laci kosong");
                }

            } else if (cmd.equals("INFO")) {
                String tipe = parts[1];
                if (tipe.equals("INT")) {
                    System.out.println(laciInt);
                } else if (tipe.equals("DBL")) {
                    System.out.println(laciDbl);
                } else if (tipe.equals("STR")) {
                    System.out.println(laciStr);
                }
            }
        }

        sc.close();
    }
}
