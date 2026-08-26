class PalindromeScroll extends Scroll {
    public PalindromeScroll(String content){
        super(content);
    }

    @Override
    public String process() {
        StringBuilder sb = new StringBuilder(content);
        return sb.reverse().toString();
    }
    public boolean isPalindrome(){
        String cleanContent = this.content.replaceAll("\\s+", "").toLowerCase();
        String reverse = new StringBuilder(cleanContent).reverse().toString();
        return cleanContent.equals(reverse);
    }

    @Override
    public String toString() {
        return "[PALINDROME] " + super.toString();
    }
}
