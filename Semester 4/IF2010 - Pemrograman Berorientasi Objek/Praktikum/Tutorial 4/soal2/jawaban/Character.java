class Character{
    protected String name;
    protected int level;
    protected double powerBase;
    Character(String name, int level, double powerBase){
        this.name = name;
        this.level = level;
        this.powerBase = powerBase;
    }
    public String getName(){
        return this.name;
    }
    // mengembalikan atribut name.
    public int getLevel(){
        return this.level;
    }
    // mengembalikan atribut level.
    public double getPowerBase(){
        return this.powerBase;
    }
    // mengembalikan atribut powerBase.
    public double calculatePower(){
        return this.powerBase;
    }
    // mengembalikan atribut powerBase.
    public void printInfo(){    
        System.out.println("Nama: " + this.name);
        System.out.println("Nama Kapital: " + this.name.toUpperCase());
        System.out.println("Inisial: " + this.name.charAt(0));
        System.out.println("Panjang Nama: " + this.name.length());
        System.out.println("Level: " + this.level);
        System.out.println("Power Akhir: " + this.calculatePower());
    }
    // mencetak info sebagai berikut:
}