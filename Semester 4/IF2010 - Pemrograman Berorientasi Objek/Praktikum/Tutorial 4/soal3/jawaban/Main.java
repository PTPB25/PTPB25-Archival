import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Implementasi program utama di sini
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        String[] items = new String[n];
        Courier[] couriers = new Courier[n];
        for(int i = 0; i < n; i++){
            char type = scanner.next().charAt(0);
            String name = scanner.next();
            int speed = scanner.nextInt();
            String item = scanner.next();
            Courier temp = new Courier();
            if(type == 'B'){
                temp = new BikeCourier(name, speed);
            } else if (type == 'C'){
                temp = new CarCourier(name, speed);
            }
            couriers[i] = temp;
            items[i] = item;
        }
        float average = 0;
        Boolean fast = false;
        for(int i = 0; i < n; i++){
            average += couriers[i].getSpeed();
            if(couriers[i].getSpeed() > 40) fast = true;
            System.out.println(couriers[i]);
            System.out.println(couriers[i].deliver(items[i]));
        }
        if(n != 0) average /= n;
        System.out.printf("Average speed: %.2f\n", average);
        System.out.printf("Fast? %b\n", fast);
    }
}