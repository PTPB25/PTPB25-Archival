public class SummonedMonster implements ISummoned {
    private Monster monster;
    private boolean isFaceUp;
    private boolean isAttacking;

    public SummonedMonster(Monster m, boolean faceUp, boolean attackPos){
        this.monster = m;
        this.isFaceUp = faceUp;
        this.isAttacking = attackPos;
    }

    @Override
    public boolean flip(){
        if(isFaceUp) return false;
        isFaceUp = true;
        return true;
    }

    @Override
    public void rotate(){
        isAttacking = !isAttacking;
    }

    @Override
    public int getPositionValue(){
        if(isAttacking) return monster.getAttackValue();
        return monster.getDefenseValue();
    }

    @Override
    public void render() {
        String msg = "Monster ";
        msg += this.monster.getName();
        msg += " dalam keadaan ";
        if (this.isFaceUp) {
            msg += "terbuka";
        } else {
            msg += "tertutup";
        }
        msg += " dengan posisi ";
        if (this.isAttacking) {
            msg += "menyerang";
        } else {
            msg += "bertahan";
        }
        System.out.println(msg);
    }
}
