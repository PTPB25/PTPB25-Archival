public class AccountFrozenException extends Exception {
    /**
     * Dilempar ketika operasi dilakukan pada rekening yang sedang dibekukan.
     *
     * @param accountId ID rekening yang dibekukan
     *
     * Pesan exception yang harus dihasilkan:
     *   "Akun dibekukan: <accountId>"
     */
    public AccountFrozenException(String accountId) {
        super("Akun dibekukan: " + accountId);
        // TODO: Implementasi
    }
}
