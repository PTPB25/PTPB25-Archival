import java.util.*;

public class WeatherStation {
    private List<WeatherObserver> observers;
    private double temperature;
    private double humidity;
    
    public WeatherStation(){
        this.humidity = 0;
        this.temperature = 0;
        this.observers = new ArrayList<>();
    }
    private void notifyObservers(){
        for (WeatherObserver w : observers){
            w.update(temperature, humidity);
        }
    }
    public boolean removeObserver(String name){
        if (hasObserver(name)){

            observers.removeIf(e -> e.getName().equals(name));
            return true;
        }
        return false;
    }
    public void addObserver(WeatherObserver observer){
        observers.add(observer);
    }
    public void setMeasurements(double temperature, double humidity){
        this.humidity = humidity;
        this.temperature = temperature;
        notifyObservers();
    }
    public double getTemperature(){
        return temperature;
    }
    public double getHumidity(){
        return humidity;
    }
    public int getObserverCount(){
        return observers.size();
    }
    public boolean hasObserver(String name){
        return observers.stream()
                .anyMatch(
                    o -> Objects.equals(o.getName(), name)
                );
    }
}
