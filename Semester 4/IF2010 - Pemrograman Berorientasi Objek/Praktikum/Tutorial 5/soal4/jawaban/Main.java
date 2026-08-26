import java.util.List;
import java.util.Map;

/**
 * Run this class to verify your implementation.
 */
public class Main {

    public static void main(String[] args) {

        // ---- Seed data ------------------------------------------------
        SmartLibrary<Book> library = new SmartLibrary<>();

        library.add(new Book("Clean Code",              "Robert C. Martin", "Technology", 2008, 4.7));
        library.add(new Book("The Pragmatic Programmer","David Thomas",     "Technology", 1999, 4.6));
        library.add(new Book("Design Patterns",         "Gang of Four",     "Technology", 1994, 4.5));
        library.add(new Book("Dune",                    "Frank Herbert",    "Sci-Fi",     1965, 4.8));
        library.add(new Book("Foundation",              "Isaac Asimov",     "Sci-Fi",     1951, 4.6));
        library.add(new Book("Neuromancer",             "William Gibson",   "Sci-Fi",     1984, 4.2));
        library.add(new Book("Sapiens",                 "Yuval Noah Harari","History",    2011, 4.7));
        library.add(new Book("1984",                    "George Orwell",    "Fiction",    1949, 4.8));
        library.add(new Book("Brave New World",         "Aldous Huxley",    "Fiction",    1932, 4.4));

        // ================================================================
        // Custom Collection & Iterator
        // ================================================================
        System.out.println("=== Iterator & Collection ===");
        System.out.println("Library size: " + library.size());

        System.out.println("\nFor-each traversal (uses LibraryIterator):");
        for (Book b : library) {
            System.out.println("  " + b.getTitle() + " by " + b.getAuthor());
        }

        System.out.println("\nManual iterator (with hasPrevious bonus):");
        LibraryIterator<Book> it = (LibraryIterator<Book>) library.iterator();
        Book first = it.next();
        Book second = it.next();
        System.out.println("  next()     -> " + first.getTitle());
        System.out.println("  next()     -> " + second.getTitle());
        System.out.println("  hasPrev()  -> " + it.hasPrevious());
        System.out.println("  previous() -> " + it.previous().getTitle());

        System.out.println("\ncontains(Dune)    -> " + library.contains(new Book("Dune","Frank Herbert","",0,0)));
        System.out.println("contains(Unknown) -> " + library.contains(new Book("Unknown","?","",0,0)));

        // ================================================================
        // Collections Algorithms
        // ================================================================
        System.out.println("\n=== Sorting & Binary Search ===");

        library.sortByTitle();
        System.out.println("After sortByTitle():");
        for (Book b : library) {
            System.out.println("  " + b.getTitle());
        }

        library.sortByRatingDesc();
        System.out.println("\nAfter sortByRatingDesc():");
        for (Book b : library) {
            System.out.printf("  %-30s %.1f%n", b.getTitle(), b.getRating());
        }

        System.out.println("\nfindByAuthor(\"Isaac Asimov\"): " + library.findByAuthor("Isaac Asimov"));
        System.out.println("findByAuthor(\"Unknown\"):       " + library.findByAuthor("Unknown"));

        // ================================================================
        // Stream API
        // ================================================================
        System.out.println("\n=== Stream API ===");

        System.out.println("getTopRated(3):");
        library.getTopRated(3).forEach(b -> System.out.printf("  %.1f  %s%n", b.getRating(), b.getTitle()));

        System.out.println("\ngetByGenre(\"Sci-Fi\"):");
        library.getByGenre("Sci-Fi").forEach(b -> System.out.println("  " + b.getTitle()));

        System.out.printf("%ngetAverageRating(): %.2f%n", library.getAverageRating());

        System.out.println("\ngroupByGenre():");
        Map<String, List<Book>> grouped = library.groupByGenre();
        grouped.forEach((genre, list) -> {
            System.out.println("  [" + genre + "]");
            list.forEach(b -> System.out.println("    - " + b.getTitle()));
        });

        // ================================================================
        // Genre Statistics Report
        // ================================================================
        System.out.println("=== Genre Report ===");
        library.printGenreReport();

        System.out.println("search(\"asimov\"): " + library.search("asimov"));
        System.out.println("exists(\"Orwell\"): " + library.exists("Orwell"));
    }
}