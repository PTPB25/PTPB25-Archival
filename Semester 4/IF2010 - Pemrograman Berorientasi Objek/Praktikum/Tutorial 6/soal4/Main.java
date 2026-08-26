import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String cmd = sc.next();
            if (cmd.equals("SCHEMA")) {
                String className = sc.next();
                Class<?> clazz = Class.forName(className);
                ORM.schema(clazz);
            } else if (cmd.equals("INSERT")) {
                String className = sc.next();
                Class<?> clazz = Class.forName(className);
                long annotatedCount = java.util.Arrays.stream(clazz.getDeclaredFields())
                        .filter(f -> f.getAnnotation(ColumnName.class) != null)
                        .count();
                String[] vals = new String[(int) annotatedCount];
                for (int i = 0; i < vals.length; i++) {
                    vals[i] = sc.next();
                }
                Object obj = ORM.createInstance(clazz, vals);
                ORM.insert(obj);
            } else if (cmd.equals("DELETE")) {
                String className = sc.next();
                Class<?> clazz = Class.forName(className);
                long annotatedCount = java.util.Arrays.stream(clazz.getDeclaredFields())
                        .filter(f -> f.getAnnotation(ColumnName.class) != null)
                        .count();
                String[] vals = new String[(int) annotatedCount];
                for (int i = 0; i < vals.length; i++) {
                    vals[i] = sc.next();
                }
                Object obj = ORM.createInstance(clazz, vals);
                ORM.delete(obj);
            }
        }
        sc.close();
    }
}
