class Fighter extends Character {
    private int physicalAtk;
    Fighter(String name, int level, double powerBase, int physicalAtk){
        super(name, level, powerBase);
        this.physicalAtk = physicalAtk;
    }
    public int getPhysicalAtk(){
        return this.physicalAtk;
    }
    // mengembalikan atribut physicalAtk.
    public double calculatePower(){
        return powerBase + ((double) this.physicalAtk * 0.7);
    }
    // menjadi: powerBase + (physicalAtk * 0.7).
    public void printInfo(){
        super.printInfo();
        System.out.println("Jenis: Fighter");
    }
    // dengan menambah info 
}