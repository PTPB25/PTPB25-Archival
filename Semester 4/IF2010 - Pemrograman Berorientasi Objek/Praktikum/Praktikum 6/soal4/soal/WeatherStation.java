import java.util.ArrayList;
import java.util.List;

public class WeatherStation {
    // TODO:
    // Deklarasikan field berikut:
    //   private List<WeatherObserver> observers
    //   private double temperature
    //   private double humidity

    public WeatherStation() {
        // TODO:
        // Inisialisasi observers sebagai ArrayList kosong.
        // Set temperature = 0.0 dan humidity = 0.0.
    }

    public void addObserver(WeatherObserver observer) {
        // TODO:
        // Tambahkan observer ke dalam daftar observers.
    }

    public boolean removeObserver(String name) {
        // TODO:
        // Cari observer dengan nama yang sesuai di dalam daftar.
        // Jika ditemukan, hapus dan kembalikan true.
        // Jika tidak ditemukan, kembalikan false.

        return false;
    }

    public boolean hasObserver(String name) {
        // TODO:
        // Kembalikan true jika terdapat observer dengan nama tersebut
        // di dalam daftar, false jika tidak.

        return false;
    }

    public void setMeasurements(double temperature, double humidity) {
        // TODO:
        // Perbarui nilai temperature dan humidity.
        // Setelah diperbarui, panggil notifyObservers() untuk
        // memberitahu semua observer yang terdaftar.
    }

    private void notifyObservers() {
        // TODO:
        // Iterasi seluruh observer dalam daftar (sesuai urutan pendaftaran)
        // dan panggil update(temperature, humidity) pada masing-masing observer.
    }

    public double getTemperature() {
        // TODO:
        // Kembalikan nilai temperature saat ini.

        return 0.0;
    }

    public double getHumidity() {
        // TODO:
        // Kembalikan nilai humidity saat ini.

        return 0.0;
    }

    public int getObserverCount() {
        // TODO:
        // Kembalikan jumlah observer yang saat ini terdaftar.

        return 0;
    }
}
