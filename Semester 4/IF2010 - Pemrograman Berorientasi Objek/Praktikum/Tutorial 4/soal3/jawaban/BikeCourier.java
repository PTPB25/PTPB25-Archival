public class BikeCourier extends Courier {
    // Implementasi kelas BikeCourier di sini
    BikeCourier(String name, int speed){
        super(name, speed);
    }
    public String toString(){
        return "[Bike] " + super.toString();
    }
    //  menjadi: "[Bike] " + super.toString(). 
}