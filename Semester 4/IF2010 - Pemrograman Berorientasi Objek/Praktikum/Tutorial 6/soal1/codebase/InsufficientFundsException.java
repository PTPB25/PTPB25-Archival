public class InsufficientFundsException extends Exception {
    /**
     * Dilempar ketika saldo rekening tidak mencukupi untuk melakukan penarikan.
     *
     * @param accountId ID rekening yang bersangkutan
     * @param balance   saldo saat ini
     * @param amount    jumlah yang ingin ditarik
     *
     * Pesan exception yang harus dihasilkan:
     *   "Saldo tidak cukup di akun <accountId> (saldo: <balance>, diperlukan: <amount>)"
     */
    public InsufficientFundsException(String accountId, long balance, long amount) {
        // TODO: Implementasi
    }
}
