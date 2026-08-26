import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        if (scanner.hasNextInt()) {
            int tc = scanner.nextInt();
            Object[] things = new Object[]{};

            switch (tc) {
                case 1:
                    things = new Object[]{new Fish()};
                    break;
                case 2:
                    things = new Object[]{new Dog()};
                    break;
                case 3:
                    things = new Object[]{new Human()};
                    break;
                case 4:
                    things = new Object[]{new Fish(), new Dog(), new Human()};
                    break;
                default:
                    break;
            }

            for (Object obj : things) {
                // Check if the object can run
                if (obj instanceof CanRun) {
                    ((CanRun) obj).run();
                }
                // Check if the object can swim
                if (obj instanceof CanSwim) {
                    ((CanSwim) obj).swim();
                }
            }
        }
        
        scanner.close();
    }
}