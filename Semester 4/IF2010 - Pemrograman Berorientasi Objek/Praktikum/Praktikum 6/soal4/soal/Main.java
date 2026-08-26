import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        WeatherStation station = new WeatherStation();

        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            String command = sc.next();

            if (command.equals("REGISTER")) {
                String type = sc.next();
                String name = sc.next();

                if (station.hasObserver(name)) {
                    System.out.println("ALREADY_REGISTERED");
                } else if (type.equals("TEMP_DISPLAY")) {
                    station.addObserver(new TemperatureDisplay(name));
                    System.out.println("OK");
                } else if (type.equals("HUMIDITY_DISPLAY")) {
                    station.addObserver(new HumidityDisplay(name));
                    System.out.println("OK");
                } else {
                    System.out.println("UNKNOWN_OBSERVER_TYPE");
                }

            } else if (command.equals("REMOVE")) {
                String name = sc.next();
                if (station.removeObserver(name)) {
                    System.out.println("OK");
                } else {
                    System.out.println("NOT_FOUND");
                }

            } else if (command.equals("UPDATE")) {
                double temperature = sc.nextDouble();
                double humidity = sc.nextDouble();
                station.setMeasurements(temperature, humidity);

            } else if (command.equals("STATUS")) {
                System.out.printf("Station: Suhu=%.1f, Kelembaban=%.1f%%, Observer=%d%n",
                        station.getTemperature(), station.getHumidity(), station.getObserverCount());

            } else {
                System.out.println("UNKNOWN_COMMAND");
            }
        }

        sc.close();
    }
}
