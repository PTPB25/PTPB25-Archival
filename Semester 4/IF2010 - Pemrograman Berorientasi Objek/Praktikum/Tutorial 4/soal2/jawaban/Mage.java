class Mage extends Character {
    private int magicalAtk;
    Mage(String name, int level, double powerBase, int magicalAtk){
        super(name, level, powerBase);
        this.magicalAtk = magicalAtk;
    }
    public int getMagicalAtk(){
        return this.magicalAtk;
    }
    // mengembalikan atribut magicalAtk.
    public double calculatePower(){
        return powerBase + ((double) this.magicalAtk * 0.5);
    }
    // menjadi: powerBase + (magicalAtk * 0.5).
    public void printInfo(){
        super.printInfo();
        System.out.println("Jenis: Mage");
    }
    // dengan menambah info 
}