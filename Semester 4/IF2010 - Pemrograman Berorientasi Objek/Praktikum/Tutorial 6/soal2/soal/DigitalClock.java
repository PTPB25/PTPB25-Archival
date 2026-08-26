public class DigitalClock {
    private int hour;
    private int minute;
    private int second;
    private TimeMode mode;

    public DigitalClock(int hour, int minute, int second) {
        // TODO:
        // Lakukan validasi argumen dengan beberapa pesan jika tidak sesuai berikut
        //  - hour tidak valid: "Invalid hour"
        //  - minute tidak valid: "Invalid minute"
        //  - second tidak valid: "Invalid second"

        this.hour = hour;
        this.minute = minute;
        this.second = second;
        this.mode = TimeMode.NORMAL;

        // TODO:
        // Validasi kembali objek yang sudah terbentuk untuk class invariant. Keluarkan "Invalid clock state after constructor" jika tidak valid
    }

    public void tick() {
        // TODO:
        // Tambahkan waktu sebanyak 1 detik.
        // Gunakan private method addOneSecond().
        // Validasi kembali objek yang sudah diedit untuk class invariant. Keluarkan "Invalid clock state after tick" jika tidak valid
    }

    public void addSeconds(int seconds) {
        // TODO:
        // seconds harus >= 0.
        // Validasi parameter masukan method dan keluarkan "seconds must be non-negative" jika tidak valid
        // Tambahkan waktu sebanyak seconds detik.
        // Validasi kembali objek yang sudah diedit untuk class invariant. Keluarkan "Invalid clock state after addSeconds" jika tidak valid
    }
    
    public void setMode(String modeName) {
        // TODO:
        // modeName hanya boleh NORMAL, COMPACT, VERBOSE.
        // Validasi parameter masukan method dan keluarkan "modeName cannot be null" atau "Invalid mode"
        // set mode sesuai modeName
        // Validasi kembali objek yang sudah diedit untuk class invariant. Keluarkan "Mode should never be null" jika tidak valid
    }

    public String format() {
        // TODO:
        // Gunakan switch berdasarkan mode.
        // Namun, untuk menguji penggunaan assert, 
        // kalian harus mengasumsikan DigitalClock dalam mode NORMAL atau COMPACT ketika memanggil method ini
        // Jika mode diluar itu, gunakan assert false sebagai control-flow invariant.
        //
        // - NORMAL: String.format("%02d:%02d:%02d", hour, minute, second)
        // - COMPACT: String.format("%02d%02d%02d", hour, minute, second)
        // - false: "" 
        switch (mode) {
            case value:
                
                break;
        
            default:
                break;
        }
    }

    private void addOneSecond() {
        // TODO:
        // Lakukan validasi precondition, kalau state tidak valid keluarkan "Precondition failed before addOneSecond"

        second++;

        if (second == 60) {
            second = 0;
            minute++;
        }

        if (minute == 60) {
            minute = 0;
            hour++;
        }

        if (hour == 24) {
            hour = 0;
        }

        // TODO:
        // Lakukan validasi postcondition state setelah menambahkan. Jika tidak valid keluarkan "Postcondition failed after addOneSecond"
    }

    private boolean isValidState() {
        // TODO:
        // Return true jika hour, minute, second berada pada range valid.
        return false;
    }
}