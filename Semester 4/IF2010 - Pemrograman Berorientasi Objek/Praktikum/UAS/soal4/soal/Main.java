import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        SmartLamp lamp = new SmartLamp("Lampu Kamar", 80, false);
        SmartFan fan = new SmartFan("Kipas Ruang Tamu", 2, false);

        int q = sc.nextInt();

        for (int i = 0; i < q; i++) {
            String command = sc.next();
            String deviceCode = sc.next();

            Object device;

            if (deviceCode.equals("LAMP")) {
                device = lamp;
            } else if (deviceCode.equals("FAN")) {
                device = fan;
            } else {
                System.out.println("UNKNOWN_DEVICE");
                continue;
            }

            if (command.equals("STATUS")) {
                SmartHomeController.printStatus(device);

            } else if (command.equals("COMMANDS")) {
                SmartHomeController.printCommands(device);

            } else if (command.equals("EXECUTE")) {
                String methodName = sc.next();
                SmartHomeController.execute(device, methodName);

            } else {
                System.out.println("UNKNOWN_COMMAND");
            }
        }

        sc.close();
    }
}