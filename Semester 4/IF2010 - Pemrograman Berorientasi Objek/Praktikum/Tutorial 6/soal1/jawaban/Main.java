import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Bank bank = new Bank();

        while (sc.hasNextLine()) {
            String line = sc.nextLine().trim();
            if (line.isEmpty()) continue;
            String[] parts = line.split("\\s+");
            String cmd = parts[0];

            try {
                switch (cmd) {
                    case "ADD": {
                        String id = parts[1];
                        long balance = Long.parseLong(parts[2]);
                        bank.addAccount(id, balance);
                        System.out.println("Akun " + id + " dibuat dengan saldo " + balance + ".");
                        break;
                    }
                    case "DEPOSIT": {
                        String id = parts[1];
                        long amount = Long.parseLong(parts[2]);
                        bank.deposit(id, amount);
                        System.out.println("Deposit " + amount + " ke akun " + id + " berhasil.");
                        break;
                    }
                    case "WITHDRAW": {
                        String id = parts[1];
                        long amount = Long.parseLong(parts[2]);
                        bank.withdraw(id, amount);
                        System.out.println("Tarik " + amount + " dari akun " + id + " berhasil.");
                        break;
                    }
                    case "FREEZE": {
                        String id = parts[1];
                        bank.freeze(id);
                        System.out.println("Akun " + id + " dibekukan.");
                        break;
                    }
                    case "UNFREEZE": {
                        String id = parts[1];
                        bank.unfreeze(id);
                        System.out.println("Akun " + id + " diaktifkan.");
                        break;
                    }
                    case "TRANSFER": {
                        String fromId = parts[1];
                        String toId = parts[2];
                        long amount = Long.parseLong(parts[3]);
                        bank.transfer(fromId, toId, amount);
                        System.out.println("Transfer " + amount + " dari " + fromId + " ke " + toId + " berhasil.");
                        break;
                    }
                    case "STATUS": {
                        String id = parts[1];
                        BankAccount account = bank.getAccount(id);
                        System.out.println("Akun " + id + ": Saldo=" + account.getBalance()
                                + ", Status=" + (account.isFrozen() ? "Beku" : "Aktif") + ".");
                        break;
                    }
                }
            } catch (AccountNotFoundException | InsufficientFundsException | AccountFrozenException e) {
                System.out.println("Error: " + e.getMessage());
            } catch (InvalidAmountException e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        sc.close();
    }
}
