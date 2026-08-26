class CipherScroll extends Scroll{
    private int shift;
    public CipherScroll(String content, int shift){
        super(content);
        this.shift = shift;
    }

    @Override
    public String process() {
        return encode(shift);
    }

    public String decode(){
        return encode(-shift);
    }

    public String encode(int shift){
        String text = getContent();
        StringBuilder result = new StringBuilder();
        // Normalize shift to 0-25 range
        shift = (shift % 26 + 26) % 26;

        for (char character : text.toCharArray()) {
            if (Character.isLetter(character)) {
                // Set base as 'A' or 'a' based on case
                char base = Character.isUpperCase(character) ? 'A' : 'a';
                // Calculate shifted character: (char - base + shift) % 26 + base
                char shifted = (char) ((character - base + shift) % 26 + base);
                result.append(shifted);
            } else {
                result.append(character); // Maintain spaces and special characters
            }
        }
        return result.toString();
    }

    @Override
    public String toString() {
        return "[CIPHER] " + super.toString();
    }
}
