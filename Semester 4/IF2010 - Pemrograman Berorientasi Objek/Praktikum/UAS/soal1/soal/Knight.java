import java.util.Optional;
public class Knight {
    public Knight(int x, int y, int id) { 
        actions.add("2. Atas Kanan");
        actions.add("4. Atas Kiri");
        actions.add("6. Bawah Kanan");
        actions.add("8. Bawah Kiri");
     }
    public Knight(Knight b) { }

    // atasKanan
    // this.x += 1; this.y -= 2;

    // atasKiri
    // this.x -= 1; this.y -= 2;

    // bawahKanan
    // this.x += 1; this.y += 2;

    // bawahKiri
    // this.x -= 1; this.y += 2;
}