import java.util.Objects;

/**
 * Book (Jangan diubah)
 */
public class Book implements Comparable<Book> {

    private String title;
    private String author;
    private String genre;
    private int year;
    private double rating; // 1.0 - 5.0

    public Book(String title, String author, String genre, int year, double rating) {
        this.title  = title;
        this.author = author;
        this.genre  = genre;
        this.year   = year;
        this.rating = rating;
    }

    // --- Getters ---

    public String getTitle()  { return title; }
    public String getAuthor() { return author; }
    public String getGenre()  { return genre; }
    public int    getYear()   { return year; }
    public double getRating() { return rating; }

    // --- Natural order: alphabetical by title ---

    @Override
    public int compareTo(Book other) {
        // Null-safe comparison: treat null titles as less than non-null titles
        if (this.title == null && other.title == null) return 0;
        if (this.title == null) return -1;
        if (other.title == null) return 1;
        return this.title.compareToIgnoreCase(other.title);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Book)) return false;
        Book book = (Book) o;
        return Objects.equals(title, book.title) &&
               Objects.equals(author, book.author);
    }

    @Override
    public int hashCode() {
        return Objects.hash(title, author);
    }

    @Override
    public String toString() {
        return String.format("Book{title='%s', author='%s', genre='%s', year=%d, rating=%.1f}",
                title, author, genre, year, rating);
    }
}