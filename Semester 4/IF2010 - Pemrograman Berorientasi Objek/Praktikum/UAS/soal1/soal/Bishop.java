import java.util.Optional;

public class Bishop {
    public Bishop(int x, int y, int id) { 
        actions.add("2. Atas Kanan");
        actions.add("4. Atas Kiri");
        actions.add("6. Bawah Kanan");
        actions.add("8. Bawah Kiri");
    };
    public Bishop(Bishop b) { }

    // atasKanan
    // this.x += steps.orElse(1); this.y -= steps.orElse(1); 

    // atasKiri
    // this.x -= steps.orElse(1); this.y -= steps.orElse(1); 

    // bawahKanan
    // this.x += steps.orElse(1); this.y += steps.orElse(1); 

    // bawahKiri
    // this.x -= steps.orElse(1); this.y += steps.orElse(1); 
}