import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        Academy academy = new Academy();

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();
            String[] parts = line.split(" ", 3);
            String cmd = parts[0];

            if (cmd.equals("ADD")) {
                String type = parts[1];
                String rest = parts[2];

                if (type.equals("PLAIN")) {
                    academy.addScroll(new PlainScroll(rest));
                } else if (type.equals("CIPHER")) {
                    String[] cipherParts = rest.split(" ", 2);
                    int shift = Integer.parseInt(cipherParts[0]);
                    String word = cipherParts[1];
                    academy.addScroll(new CipherScroll(word, shift));
                } else if (type.equals("PALINDROME")) {
                    academy.addScroll(new PalindromeScroll(rest));
                }

            } else if (cmd.equals("PROCESS")) {
                int index = Integer.parseInt(parts[1]);
                System.out.println(academy.getScroll(index).process());

            } else if (cmd.equals("DECODE")) {
                int index = Integer.parseInt(parts[1]);
                Scroll s = academy.getScroll(index);
                if (s instanceof CipherScroll) {
                    System.out.println(((CipherScroll) s).decode());
                } else {
                    System.out.println("Gulungan bukan tipe CIPHER.");
                }

            } else if (cmd.equals("INFO")) {
                int index = Integer.parseInt(parts[1]);
                System.out.println(academy.getScroll(index));

            } else if (cmd.equals("CHECK")) {
                int index = Integer.parseInt(parts[1]);
                Scroll s = academy.getScroll(index);
                if (s instanceof PalindromeScroll) {
                    PalindromeScroll ps = (PalindromeScroll) s;
                    String content = ps.getContent();
                    if (ps.isPalindrome()) {
                        System.out.println("\"" + content + "\" adalah palindrom.");
                    } else {
                        System.out.println("\"" + content + "\" bukan palindrom.");
                    }
                } else {
                    System.out.println("Gulungan bukan tipe PALINDROME.");
                }

            } else if (cmd.equals("SEARCH")) {
                String keyword = parts[1];
                int count = academy.search(keyword);
                System.out.println("Ditemukan: " + count + " gulungan mengandung \"" + keyword + "\".");

            } else if (cmd.equals("COUNT")) {
                System.out.println("Total: " + academy.count() + " gulungan.");
            }
        }

        sc.close();
    }
}
