import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            String className = sc.nextLine().trim();
            if (className.isEmpty()) continue;

            try {
                Plugin plugin = PluginLoader.loadPlugin(className);
                plugin.start();
            } catch (Exception e) {
                Throwable cause = e;
                if (e instanceof java.lang.reflect.InvocationTargetException) {
                    cause = e.getCause();
                }
                System.out.println(cause.getClass().getName() + ": " + cause.getMessage());
            }
        }
        sc.close();
    }
}
