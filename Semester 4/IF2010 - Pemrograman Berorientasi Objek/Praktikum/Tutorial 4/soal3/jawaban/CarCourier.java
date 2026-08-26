public class CarCourier extends Courier {
    // Implementasi kelas CarCourier di sini
    CarCourier(String name, int speed){
        super(name, speed);
    }
    public String toString(){
        return "[Car] " + super.toString();
    }
    //  menjadi: "[Car] " + super.toString(). 
}