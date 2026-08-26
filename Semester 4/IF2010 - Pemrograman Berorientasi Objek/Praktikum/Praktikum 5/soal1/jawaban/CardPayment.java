public class CardPayment implements PaymentStrategy {
    @Override
    public void pay(int amount){
        System.out.println("Paid $" + Integer.toString(amount) + " using Credit Card");
    }
}