public class AccountNotFoundException extends Exception {
    public AccountNotFoundException(String accountId) {
        super("Akun tidak ditemukan: " + accountId);
    }
}
