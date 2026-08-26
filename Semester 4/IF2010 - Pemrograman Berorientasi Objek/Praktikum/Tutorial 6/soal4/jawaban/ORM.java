import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

public class ORM {

    /**
     * Mencetak skema (nama tabel dan kolom-kolom) dari kelas yang diberikan.
     * Hanya field yang beranotasi @ColumnName yang ditampilkan.
     *
     * Format output:
     *   Table: <nama_tabel>
     *   Columns:
     *     - <nama_kolom> [PRIMARY KEY]   <- jika primaryKey = true
     *     - <nama_kolom>
     */
    public static void schema(Class<?> clazz) {
        // TODO: Implementasi
        TableName tableAnnot = clazz.getAnnotation(TableName.class);
        if (tableAnnot == null) {
            return;
        }
        System.out.println("Table: " + tableAnnot.value());
        System.out.println("Columns:");
        Field[] attr = clazz.getDeclaredFields();
        for(Field field : attr){
            if(field.isAnnotationPresent(ColumnName.class)){
                ColumnName relAttr = field.getAnnotation(ColumnName.class);
                System.out.print("  - " + relAttr.value());
                if(relAttr.primaryKey()) System.out.println(" [PRIMARY KEY]");
                else System.out.println();
            }
        }
    }

    /**
     * Membuat instance dari kelas yang diberikan menggunakan Reflection.
     * values[] berisi nilai-nilai untuk field beranotasi @ColumnName sesuai urutan deklarasi.
     * Tipe yang perlu didukung: String, int, double.
     *
     * Setelah semua field diisi, panggil semua method yang beranotasi
     * @Hook(when = Hook.When.POST_LOAD) menggunakan method.invoke().
     */
    public static Object createInstance(Class<?> clazz, String[] values) throws Exception {
        // TODO: Implementasi
        Object obj = clazz.getDeclaredConstructor().newInstance();
        Field[] attr = clazz.getDeclaredFields();
        int i = 0;
        for(Field field : attr){
            if(field.isAnnotationPresent(ColumnName.class)){
                field.setAccessible(true);
                Class<?> type = field.getType();
                if (type == String.class){
                    field.set(obj, values[i]);
                } else if (type == Integer.class || type == int.class){
                    field.set(obj, Integer.parseInt(values[i]));
                } else if (type == Double.class || type == double.class){
                    field.set(obj, Double.parseDouble(values[i]));
                }
                i++;
            }
        }

        Method[] meths = clazz.getDeclaredMethods();
        for(Method meth : meths){
            if(meth.isAnnotationPresent(Hook.class)){
                Hook leHook = meth.getAnnotation(Hook.class);
                if(leHook.when() == Hook.When.POST_LOAD){
                    meth.setAccessible(true);
                    meth.invoke(obj);
                }
            }
        }
        return obj;
    }

    /**
     * Mencetak pernyataan INSERT SQL berdasarkan objek yang diberikan.
     *
     * Sebelum mencetak SQL, panggil semua method yang beranotasi
     * @Hook(when = Hook.When.PRE_INSERT) menggunakan method.invoke().
     * Jika salah satu method tersebut melempar exception (InvocationTargetException),
     * cetak "Gagal insert: <pesan exception>" dan JANGAN cetak SQL INSERT.
     *
     * Format output (jika tidak ada exception):
     *   INSERT INTO <nama_tabel> (<col1>, <col2>, ...) VALUES (<val1>, <val2>, ...)
     * Keterangan: nilai String diapit tanda kutip satu (' '),
     *             nilai numerik (int/double) ditulis apa adanya.
     */
    public static void insert(Object obj) throws Exception {
        // TODO: Implementasi
        Method[] meths = obj.getClass().getDeclaredMethods();
        for(Method meth : meths){
            Hook leHook = meth.getAnnotation(Hook.class);
            if(leHook == null) continue;
            if(leHook.when() == Hook.When.PRE_INSERT){
                try {
                    meth.setAccessible(true);
                    meth.invoke(obj);
                } catch (InvocationTargetException e) {
                    System.out.println("Gagal insert: " + e.getCause().getLocalizedMessage());
                    return;
                }
            }
        }
        Field[] attr = obj.getClass().getDeclaredFields();
        List<String> colName = new ArrayList<>();
        List<String> value = new ArrayList<>();
        for(Field ladang : attr){
            if(ladang.isAnnotationPresent(ColumnName.class)){
                ColumnName padi = ladang.getAnnotation(ColumnName.class);
                colName.add(padi.value());
                ladang.setAccessible(true);
                if(ladang.getType() == String.class){
                    value.add("'" + ladang.get(obj) + "'");
                } else if(ladang.getType() == Integer.class || ladang.getType() == int.class || ladang.getType() == Double.class || ladang.getType() == double.class){
                    value.add(ladang.get(obj).toString());
                }
            }
        }
        System.out.print("INSERT INTO " + obj.getClass().getAnnotation(TableName.class).value());
        System.out.print(" " + colName.toString().replace("[", "(").replace("]", ")"));
        System.out.println(" VALUES " + value.toString().replace("[", "(").replace("]", ")"));
        // INSERT INTO <nama_tabel> (<col1>, <col2>, ...) VALUES (<val1>, <val2>, ...)
    }

    /**
     * Mencetak pernyataan DELETE SQL berdasarkan objek yang diberikan.
     *
     * Sebelum mencetak SQL, panggil semua method yang beranotasi
     * @Hook(when = Hook.When.PRE_DELETE) menggunakan method.invoke().
     * Jika salah satu method tersebut melempar exception (InvocationTargetException),
     * cetak "Gagal delete: <pesan exception>" dan JANGAN cetak SQL DELETE.
     *
     * Format output (jika tidak ada exception):
     *   DELETE FROM <nama_tabel> WHERE <pk_kolom> = <pk_nilai>
     * Keterangan: pk_nilai bertipe String diapit tanda kutip satu (' '),
     *             pk_nilai bertipe numerik ditulis apa adanya.
     * Gunakan field pertama yang memiliki @ColumnName(primaryKey = true) sebagai WHERE clause.
     */
    public static void delete(Object obj) throws Exception {
        // TODO: Implementasi
        Method[] meths = obj.getClass().getDeclaredMethods();
        for(Method meth : meths){
            Hook zaHook = meth.getAnnotation(Hook.class);
            if (zaHook == null) continue;
            if (zaHook.when() == Hook.When.PRE_DELETE){
                try {
                    meth.setAccessible(true);
                    meth.invoke(obj);
                } catch (InvocationTargetException e) {
                    System.out.println("Gagal delete: " + e.getCause().getLocalizedMessage());
                    return;
                }
            }
        }
        Field[] attr = obj.getClass().getDeclaredFields();
        String peka = "";
        String valu = "";
        for(Field ladang : attr) {
            if(ladang.isAnnotationPresent(ColumnName.class)){
                ColumnName padi = ladang.getAnnotation(ColumnName.class);
                if(padi.primaryKey()){
                    ladang.setAccessible(true);
                    peka = padi.value();
                    if(ladang.getType() == String.class){
                        valu = "'" + ladang.get(obj) + "'";
                    } else valu = ladang.get(obj).toString();
                }
            }
        }
        System.out.println("DELETE FROM " + obj.getClass().getAnnotation(TableName.class).value() + " WHERE " + peka + " = " + valu);
    }
}
