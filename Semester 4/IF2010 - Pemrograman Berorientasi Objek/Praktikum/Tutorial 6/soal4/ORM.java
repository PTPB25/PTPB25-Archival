import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

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
        return null;
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
    }
}
