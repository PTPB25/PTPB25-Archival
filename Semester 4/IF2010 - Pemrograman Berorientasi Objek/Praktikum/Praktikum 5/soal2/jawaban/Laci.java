import java.util.ArrayList;
public class Laci<T> {
    protected ArrayList<T> items;
    protected String label;

    public Laci(String label){
        this.label = label;
        items = new ArrayList<T>();
    }

    public boolean simpan(T item){
        if(items.size() == 10) return false;
        items.add(item);
        return true;
    }
    public T ambil(int i){
        if(i < 1 || i > items.size()) return null;
        return items.get(i-1);
    }
    public void set(int i, T item){
        if(i < 1 || i > items.size()) return;
        items.set(i-1, item);
    }
    public int ukuran(){
        return items.size();
    }
    public String getLabel(){
        return label;
    }
    public String toString(){
        return "Laci[" + label + "]: " + items.toString();
    }
}