public class BankAccount {
    private String id;
    private long balance;
    private boolean frozen;

    /**
     * Membuat rekening baru.
     * Lempar InvalidAmountException jika initialBalance < 0.
     */
    public BankAccount(String id, long initialBalance) {
        // TODO: Implementasi
    }

    /** Mengembalikan ID rekening. */
    public String getId() {
        // TODO: Implementasi
        return null;
    }

    /** Mengembalikan saldo saat ini. */
    public long getBalance() {
        // TODO: Implementasi
        return 0;
    }

    /** Mengembalikan true jika rekening sedang dibekukan. */
    public boolean isFrozen() {
        // TODO: Implementasi
        return false;
    }

    /**
     * Menambah saldo sebesar amount.
     * Urutan pengecekan:
     *   1. amount <= 0  -> InvalidAmountException
     *   2. frozen       -> AccountFrozenException
     */
    public void deposit(long amount) throws InvalidAmountException, AccountFrozenException {
        // TODO: Implementasi
    }

    /**
     * Mengurangi saldo sebesar amount.
     * Urutan pengecekan:
     *   1. amount <= 0        -> InvalidAmountException
     *   2. frozen             -> AccountFrozenException
     *   3. amount > balance   -> InsufficientFundsException
     */
    public void withdraw(long amount) throws InvalidAmountException, InsufficientFundsException, AccountFrozenException {
        // TODO: Implementasi
    }

    /** Membekukan rekening. */
    public void freeze() {
        // TODO: Implementasi
    }

    /** Mengaktifkan kembali rekening yang dibekukan. */
    public void unfreeze() {
        // TODO: Implementasi
    }
}
