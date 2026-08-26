public class TemperatureDisplay implements WeatherObserver {
    private String name;

    public TemperatureDisplay(String name){
        this.name = name; 
    }
    
    @Override
    public void update(double temperature, double humidity){
        String s = "Display " + name + ": Suhu";
        System.out.printf("%s %.1f%n", s, temperature);
    }

    @Override
    public String getName(){
        return name;
    }
}
