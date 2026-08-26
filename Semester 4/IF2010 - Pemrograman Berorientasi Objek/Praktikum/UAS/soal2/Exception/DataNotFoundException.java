public class DataNotFoundException extends Exception {
    public DataNotFoundException(String id) {
        super("Data dengan id " + id + " tidak ditemukan");
    }
}
