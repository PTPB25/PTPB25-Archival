import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine().trim());

        Checkout checkout = new Checkout();

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine().trim();

            if (line.isEmpty()) continue;

            String[] parts = line.split(" ");
            String cmd = parts[0];

            switch (cmd) {
                case "SET":
                    String method = parts[1];

                    switch (method) {
                        case "CARD":
                            checkout.setPaymentStrategy(new CardPayment());
                            break;

                        case "EWALLET":
                            checkout.setPaymentStrategy(new EWalletPayment());
                            break;

                        case "BANK":
                            checkout.setPaymentStrategy(new BankTransferPayment());
                            break;

                        default:
                            System.out.println("Invalid payment method");
                    }
                    break;

                case "PAY":
                    int amount = Integer.parseInt(parts[1]);
                    checkout.processPayment(amount);
                    break;

                default:
                    System.out.println("Invalid command");
            }
        }

        sc.close();
    }
}