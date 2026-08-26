@TableName("mahasiswa")
public class Mahasiswa {

    @ColumnName(value = "nim", primaryKey = true)
    private String nim;

    @ColumnName(value = "nama_mahasiswa")
    private String nama;

    @ColumnName(value = "angkatan")
    private int angkatan;

    private String catatan;

    public Mahasiswa() {}

    @Hook(when = Hook.When.POST_LOAD)
    private void onLoad() {
        this.catatan = "loaded:" + this.nim;
    }

    @Hook(when = Hook.When.PRE_INSERT)
    private void validateNIM() {
        if (this.nim == null || this.nim.length() != 8) {
            throw new IllegalArgumentException("NIM harus 8 digit");
        }
    }

    @Hook(when = Hook.When.PRE_DELETE)
    private void validateDelete() {
        if (this.angkatan < 2020) {
            throw new IllegalStateException("Mahasiswa lama tidak dapat dihapus");
        }
    }
}
