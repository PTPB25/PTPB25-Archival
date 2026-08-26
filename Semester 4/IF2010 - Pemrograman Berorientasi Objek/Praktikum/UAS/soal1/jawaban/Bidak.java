import java.util.ArrayList;
import java.util.List;

public abstract class Bidak implements Aksi {
    protected int x;
    protected int y;
    protected char simbol;
    protected int id;
    protected List<String> actions = new ArrayList<>();

    public Bidak() {
        this.x = 0;
        this.y = 0;
        this.simbol = '?';
        this.id = 0;
    }

    public Bidak(int x, int y, char simbol, int id) {
        this.x = x;
        this.y = y;
        this.simbol = simbol;
        this.id = id;
    }

    public Bidak(Bidak b) {
        this.x = b.x;
        this.y = b.y;
        this.simbol = b.simbol;
        this.id = b.id;
    }

    public int getX() { return x; }
    public int getY() { return y; }
    public char getSimbol() { return simbol; }
    public int getId() { return id; }

    public void setPosisi(int x, int y) {
        this.x = x;
        this.y = y;
    }
}