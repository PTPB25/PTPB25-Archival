public class DuplicateIdException extends Exception {
    public DuplicateIdException(String id) {
        super("Data dengan id " + id + " sudah ada");
    }
}
