import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int q = sc.nextInt();
        VendingMachine vm = null;

        for (int i = 0; i < q; i++) {
            String command = sc.next();

            try {
                if (command.equals("CREATE")) {
                    int stock = sc.nextInt();
                    int price = sc.nextInt();

                    vm = new VendingMachine(stock, price);
                    System.out.println("OK");

                } else if (command.equals("INSERT")) {
                    int amount = sc.nextInt();

                    if (vm == null) {
                        System.out.println("NO_MACHINE");
                    } else {
                        vm.insertMoney(amount);
                        System.out.println("OK");
                    }

                } else if (command.equals("BUY")) {
                    if (vm == null) {
                        System.out.println("NO_MACHINE");
                    } else {
                        System.out.println(vm.buy());
                    }

                } else if (command.equals("REFUND")) {
                    if (vm == null) {
                        System.out.println("NO_MACHINE");
                    } else {
                        System.out.println("REFUND " + vm.refund());
                    }

                } else if (command.equals("STATUS")) {
                    if (vm == null) {
                        System.out.println("NO_MACHINE");
                    } else {
                        System.out.println(vm.status());
                    }

                } else {
                    System.out.println("UNKNOWN_COMMAND");
                }

            } catch (IllegalArgumentException e) {
                System.out.println("INVALID_ARGUMENT " + e.getMessage());
            } catch (IllegalStateException e) {
                System.out.println("INVALID_STATE " + e.getMessage());
            } catch (AssertionError e) {
                System.out.println("ASSERTION_FAILED " + e.getMessage());
            }
        }

        sc.close();
    }
}