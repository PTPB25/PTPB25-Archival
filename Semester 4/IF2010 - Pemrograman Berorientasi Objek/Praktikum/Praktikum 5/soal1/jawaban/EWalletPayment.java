public class EWalletPayment implements PaymentStrategy {
    @Override
    public void pay(int amount){
        System.out.println("Paid $" + Integer.toString(amount) + " using E-Wallet");
    }
}