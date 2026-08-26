import java.util.Collections;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

public class ThreadTracker {
    public static final Set<Long> threadIds = Collections.newSetFromMap(new ConcurrentHashMap<>());
    
    public static void mark() {
        threadIds.add(Thread.currentThread().threadId());
        // threadIds.add(Thread.currentThread().getId());
    }
    
    public static void reset() {
        threadIds.clear();
    }
    
    public static void verifyUsedMultipleThreads() {
        if (threadIds.size() != 10) {
            throw new RuntimeException("Jumlah thread yang terpakai: " + threadIds.size() + ". Thread yang diharapkan: 10");
        }
    }
}