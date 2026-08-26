import java.util.Optional;
public class Knight extends Bidak {
    public Knight(int x, int y, int id) { 
        super(x, y, 'K', id);
        actions.add("2. Atas Kanan");
        actions.add("4. Atas Kiri");
        actions.add("6. Bawah Kanan");
        actions.add("8. Bawah Kiri");
     }
    public Knight(Knight b) { }

    @Override
    public void atasKanan(Optional<Integer> steps){
        this.x += 1; this.y -= 2;
    }

    @Override
    public void atasKiri(Optional<Integer> steps){
        this.x -= 1; this.y -= 2;
    }

    @Override
    public void bawahKanan(Optional<Integer> steps){
        this.x += 1; this.y += 2;
    }

    @Override
    public void bawahKiri(Optional<Integer> steps){
        this.x -= 1; this.y += 2;
    }
}