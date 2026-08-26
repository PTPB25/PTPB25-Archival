import java.util.Optional;

public interface Aksi {
    default void atas(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }

    default void atasKanan(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }

    default void atasKiri(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }

    default void kanan(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }

    default void kiri(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }

    default void bawahKanan(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }

    default void bawahKiri(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }

    default void bawah(Optional<Integer> steps){
        System.out.println("[X] Gerakan tidak valid untuk bidak ini!");
    }
}