public class Checkout {
    private PaymentStrategy paymentStrategy;
    public void setPaymentStrategy(PaymentStrategy newpay) {
        paymentStrategy = newpay;
    }
    public void processPayment(int amount) {
        if(paymentStrategy == null) System.out.println("No payment method selected");
        else paymentStrategy.pay(amount);
    }
}