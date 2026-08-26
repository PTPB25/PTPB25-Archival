public class Main {
    public static void main(String[] args) {
        Storage<Object> stringStorage = new Storage<>(2);
        
        try {
            stringStorage.store("A1", "Apple");
            System.out.println("Berhasil menyimpan A1");
            
            stringStorage.store("B1", 27198);
            System.out.println("Berhasil menyimpan B1");
            
            stringStorage.store("A1", "Avocado");
            
            stringStorage.store("C1", "Cherry");
            
            System.out.println("Retrieve A1: " + stringStorage.retrieve("A1"));
            
            stringStorage.remove("A1");
            System.out.println("Berhasil menghapus A1");
            
            stringStorage.retrieve("A1");
            
        } catch (DuplicateIdException | DataNotFoundException | StorageFullException e) {
            System.out.println("Error: " + e.getMessage());
        }
        
        System.out.println("Semua data saat ini: " + stringStorage.getAll());
    }
}
