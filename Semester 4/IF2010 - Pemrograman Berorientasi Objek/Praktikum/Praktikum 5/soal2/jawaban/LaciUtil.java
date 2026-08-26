import java.util.*;

public class LaciUtil<T> {
    static <T> void tukar(Laci<T> laci, int i, int j){
        T itemi = laci.ambil(i);
        T itemj = laci.ambil(j);

        laci.set(i, itemj);
        laci.set(j, itemi);
    }
    static <T extends Comparable<T>> T terbesar(Laci<T> laci){
        if(laci.ukuran() == 0) return null;
        T largest = laci.ambil(1);
        for(int i = 0; i < laci.ukuran(); i++){
            if(laci.ambil(i + 1).compareTo(largest) > 0) largest = laci.ambil(i+1);
        }
        return largest;
    }  
}
