import java.util.Collections;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

public class ThreadTracker {
    public static final Set<Long> threadIds = Collections.newSetFromMap(new ConcurrentHashMap<>());

    public static void mark() {
        threadIds.add(Thread.currentThread().threadId());
    }

    public static void reset() {
        threadIds.clear();
    }

    public static void verifyUsedThreads(int expected) {
        if (threadIds.size() != expected) {
            throw new RuntimeException(
                "Jumlah thread yang terpakai: " + threadIds.size() +
                ". Thread yang diharapkan: " + expected
            );
        }
    }
}
