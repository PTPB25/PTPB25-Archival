public class HumidityDisplay implements WeatherObserver {
    private String name;

    public HumidityDisplay(String name){
        this.name = name; 
    }
    
    @Override
    public void update(double temperature, double humidity){
        String s = "Display " + name + ": Kelembaban";
        System.out.printf("%s %.1f%%%n", s, humidity);
    }

    @Override
    public String getName(){
        return name;
    }
}
