public class LaciAngka<T extends Number> extends Laci<T> {
    
    public LaciAngka(String label){
        super(label);
    }

    public double total(){
        double sum = 0;
        for(Number item : items){
            sum += item.doubleValue();
        }
        return sum;
    }
    public double rataRata(){
        if(ukuran() == 0){
            return 0.0;
        }
        return total() / ukuran();
    }
}