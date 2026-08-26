import java.util.Optional;

public class Rook extends Bidak {
    public Rook(int x, int y, int id) { 
        super(x, y, 'R', id);
        actions.add("1. Atas");
        actions.add("3. Kanan");
        actions.add("5. Kiri");
        actions.add("7. Bawah");
    }
    public Rook(Rook b) { }

    
    @Override
    public void atas(Optional<Integer> steps){
        this.y -= steps.orElse(1);
    }
    
    @Override
    public void kanan(Optional<Integer> steps){
        this.x += steps.orElse(1);
    }
    
    @Override
    public void kiri(Optional<Integer> steps){
        this.x -= steps.orElse(1);
    }
    
    @Override
    public void bawah(Optional<Integer> steps){
        this.y += steps.orElse(1);
    }
}