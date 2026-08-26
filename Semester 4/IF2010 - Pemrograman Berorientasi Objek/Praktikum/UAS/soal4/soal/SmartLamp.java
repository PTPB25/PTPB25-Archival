public class SmartLamp {
    private String name;
    private int brightness;
    private boolean active;

    public SmartLamp(String name, int brightness, boolean active) {
        this.name = name;
        this.brightness = brightness;
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

    public void increaseBrightness() {
        if (brightness < 100) {
            brightness += 10;

            if (brightness > 100) {
                brightness = 100;
            }
        }

        System.out.println("Brightness " + name + " menjadi " + brightness);
    }

    private void resetBrightness() {
        brightness = 0;
        System.out.println("Brightness " + name + " direset");
    }
}