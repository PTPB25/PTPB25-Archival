public class SmartFan {
    private String name;
    private int speed;
    private boolean active;

    public SmartFan(String name, int speed, boolean active) {
        this.name = name;
        this.speed = speed;
        this.active = active;
    }

    public void turnOn() {
        active = true;
        System.out.println(name + " dinyalakan");
    }

    public void turnOff() {
        active = false;
        System.out.println(name + " dimatikan");
    }

    public void increaseSpeed() {
        speed++;
        System.out.println("Kecepatan " + name + " menjadi " + speed);
    }

    private void resetSpeed() {
        speed = 0;
        System.out.println("Kecepatan " + name + " direset");
    }
}