import java.util.LinkedHashMap;
import java.util.Map;

public class Bank {
    private Map<String, BankAccount> accounts = new LinkedHashMap<>();

    /**
     * Membuat rekening baru dan menyimpannya.
     * InvalidAmountException dari konstruktor BankAccount akan ter-propagate secara otomatis
     * karena merupakan unchecked exception.
     */
    public void addAccount(String id, long initialBalance) {
        // TODO: Implementasi
    }

    /**
     * Mengembalikan BankAccount dengan ID yang diberikan.
     * Lempar AccountNotFoundException jika tidak ditemukan.
     */
    public BankAccount getAccount(String id) throws AccountNotFoundException {
        // TODO: Implementasi
        return null;
    }

    /**
     * Memanggil deposit() pada rekening yang sesuai.
     * Propagate AccountNotFoundException dan exception dari BankAccount.deposit().
     */
    public void deposit(String id, long amount) throws AccountNotFoundException, AccountFrozenException {
        // TODO: Implementasi
    }

    /**
     * Memanggil withdraw() pada rekening yang sesuai.
     * Propagate AccountNotFoundException dan exception dari BankAccount.withdraw().
     */
    public void withdraw(String id, long amount)
            throws AccountNotFoundException, InsufficientFundsException, AccountFrozenException {
        // TODO: Implementasi
    }

    /**
     * Membekukan rekening.
     * Lempar AccountNotFoundException jika tidak ditemukan.
     */
    public void freeze(String id) throws AccountNotFoundException {
        // TODO: Implementasi
    }

    /**
     * Mengaktifkan rekening.
     * Lempar AccountNotFoundException jika tidak ditemukan.
     */
    public void unfreeze(String id) throws AccountNotFoundException {
        // TODO: Implementasi
    }

    /**
     * Mentransfer amount dari rekening fromId ke toId.
     * Panggil withdraw() pada rekening asal, lalu deposit() pada rekening tujuan.
     * Propagate semua exception yang mungkin terjadi.
     */
    public void transfer(String fromId, String toId, long amount)
            throws AccountNotFoundException, InsufficientFundsException, AccountFrozenException {
        // TODO: Implementasi
    }
}
