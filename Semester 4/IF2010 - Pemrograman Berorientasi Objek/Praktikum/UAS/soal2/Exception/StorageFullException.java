public class StorageFullException extends RuntimeException {
    public StorageFullException() {
        super("Penyimpanan sudah penuh");
    }
}
