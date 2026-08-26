public interface WeatherObserver {
    void update(double temperature, double humidity);
    String getName();
}
