public class InvalidAmountException extends RuntimeException {
    /**
     * Dilempar ketika jumlah yang diberikan tidak valid.
     * Ini adalah UNCHECKED exception (extends RuntimeException).
     *
     * @param amount jumlah yang tidak valid
     *
     * Pesan exception yang harus dihasilkan:
     *   "Jumlah tidak valid: <amount>"
     */
    public InvalidAmountException(long amount) {
        super("Jumlah tidak valid: " + Long.toString(amount));
        // TODO: Implementasi
    }
}
