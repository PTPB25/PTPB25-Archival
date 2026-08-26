import java.util.ArrayList;

class Academy {
    private ArrayList<Scroll> scrolls; 

    public Academy(){
        this.scrolls = new ArrayList();
    }

    public void addScroll(Scroll scroll){
        scrolls.add(scroll);
    }

    public Scroll getScroll(int index){
        if (index >= 1 && index <= scrolls.size()) {
            return scrolls.get(index - 1);
        }else{
            return null;
        }
    }
    
    public int search(String keyword){
        int count = 0;
        String keyLower = keyword.toLowerCase();
        for (Scroll scroll : scrolls) {
            if (scroll.getContent().toLowerCase().contains(keyLower)) {
                count++;
            }
        }
        return count;
    }

    public int count(){
        return scrolls.size();
    }
}
