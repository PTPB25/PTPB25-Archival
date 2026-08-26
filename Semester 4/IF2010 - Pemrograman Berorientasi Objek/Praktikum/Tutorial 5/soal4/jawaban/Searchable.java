import java.util.List;

/**
 * Interface untuk SmartLibrary (Jangan diubah)
 */
public interface Searchable<T> {

    /**
     * Menyaring items berdasarkan keyword yang diberikan. 
     * Field yang difilter itu title, author, genre
     * @param keyword search keyword (case-insensitive)
     * @return list of matching items
     */
    List<T> search(String keyword);

    /**
     * Mengecek apakah ada item yang memiliki keyword sesuai input
     * @return true if ada yang match
     */
    boolean exists(String keyword);
}