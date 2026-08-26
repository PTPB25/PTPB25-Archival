import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int q = sc.nextInt();
        DigitalClock clock = null;

        for (int i = 0; i < q; i++) {
            String command = sc.next();

            try {
                if (command.equals("CREATE")) {
                    int h = sc.nextInt();
                    int m = sc.nextInt();
                    int s = sc.nextInt();

                    clock = new DigitalClock(h, m, s);
                    System.out.println("OK");

                } else if (command.equals("TICK")) {
                    if (clock == null) {
                        System.out.println("NO_CLOCK");
                    } else {
                        clock.tick();
                        System.out.println("OK");
                    }

                } else if (command.equals("ADD")) {
                    int seconds = sc.nextInt();

                    if (clock == null) {
                        System.out.println("NO_CLOCK");
                    } else {
                        clock.addSeconds(seconds);
                        System.out.println("OK");
                    }

                } else if (command.equals("SET_MODE")) {
                    String mode = sc.next();

                    if (clock == null) {
                        System.out.println("NO_CLOCK");
                    } else {
                        clock.setMode(mode);
                        System.out.println("OK");
                    }

                } else if (command.equals("PRINT")) {
                    if (clock == null) {
                        System.out.println("NO_CLOCK");
                    } else {
                        System.out.println(clock.format());
                    }

                } else {
                    System.out.println("UNKNOWN_COMMAND");
                }

            } catch (IllegalArgumentException e) {
                System.out.println("INVALID_ARGUMENT " + e.getMessage());
            } catch (AssertionError e) {
                System.out.println("ASSERTION_FAILED " + e.getMessage());
            }
        }

        sc.close();
    }
}