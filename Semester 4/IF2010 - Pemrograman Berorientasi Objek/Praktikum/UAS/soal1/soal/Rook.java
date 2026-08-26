import java.util.*;
public class Rook {
    public Rook(int x, int y, int id) { 
        actions.add("1. Atas");
        actions.add("3. Kanan");
        actions.add("5. Kiri");
        actions.add("7. Bawah");
    }
    public Rook(Rook b) { }

    // atas
    // this.y -= steps.orElse(1);

    // kanan
    // this.x += steps.orElse(1);
    // kiri
    // this.x -= steps.orElse(1);
    // bawah
    // this.y += steps.orElse(1);
}