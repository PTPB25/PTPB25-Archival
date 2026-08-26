public class Monster {
    private String name;
    private int attack;
    private int defense;

    public Monster(String name, int attack, int defense) {
        this.name = name;
        this.attack = attack;
        this.defense = defense;
    }

    public String getName() {
        return this.name;
    }

    public int getAttackValue() {
        return this.attack;
    }

    public int getDefenseValue() {
        return this.defense;
    }
}
