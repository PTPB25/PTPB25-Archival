public class HumidityDisplay implements WeatherObserver {
    // TODO:
    // Deklarasikan field private String name.

    public HumidityDisplay(String name) {
        // TODO:
        // Simpan nama yang diberikan ke field name.
    }

    @Override
    public void update(double temperature, double humidity) {
        // TODO:
        // Cetak baris berikut ke System.out:
        // "Display <name>: Kelembaban <humidity>%"
        //
        // Format humidity menggunakan satu angka desimal (%.1f).
        // Contoh: "Display HumidA: Kelembaban 60.0%"
    }

    @Override
    public String getName() {
        // TODO:
        // Kembalikan nama tampilan ini.

        return "";
    }
}
