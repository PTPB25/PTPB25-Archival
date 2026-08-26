abstract class Scroll {
    protected String content;

    public Scroll(String content){
        this.content = content;
    }

    public String getContent(){
        return this.content;
    }

    abstract public String process();


    public String toString(){
        return this.content;
    }

}
