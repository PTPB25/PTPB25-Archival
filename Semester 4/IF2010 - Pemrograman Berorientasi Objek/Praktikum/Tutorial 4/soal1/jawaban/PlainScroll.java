import java.util.ArrayList;

class PlainScroll extends Scroll {
    public PlainScroll(String content){
        super(content);
    }

    @Override
    public String process() {
        String content = getContent();

        if (content.trim().isEmpty()) {
            return "";
        }

        // Melakuakn strip menghilangkan white space depan dan belakang, dan split(regex) ini menggunakan
        // \s+ artinya lebih dari 1 spasi sehingga menghasilkan array [Aku, MAKAN, JAva] 
        String[] words = content.trim().split("\\s+");
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            if (!word.isEmpty()) {
                // Mengambilkata [Aku, MAKAN, JAva] misalnya MAKAN
                // M -> tetap Uppercase, AKAN -> menajadi lower case menggunakan substring
                words[i] = word.substring(0,1).toUpperCase() + word.substring(1).toLowerCase();
            }
        }
        return String.join(" ", words);

    }

    @Override
    public String toString() {
        return "[PLAIN] " + super.toString();
    }

}
