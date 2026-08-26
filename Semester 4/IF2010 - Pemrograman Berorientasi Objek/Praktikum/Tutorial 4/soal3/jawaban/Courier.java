public class Courier {
    // Implementasi kelas Courier di sini
    protected String name;
    protected int speed;
    Courier(){
        this.name = "Unknown";
        this.speed = 10;
    }
    Courier(String name, int speed){
        this.name = name;
        this.speed = speed;
    }
    public String deliver(String item){
        return this.name + " delivers " + item;
    }
    // mengembalikan: name + " delivers " + item.
    public int getSpeed(){
        return this.speed;
    }
    // mengembalikan speed.
    public String toString(){
        return this.name + " with speed " + this.speed + " is ready to deliver";
    }
    // mengembalikan: name + " with speed " + speed + " is ready to deliver".
}