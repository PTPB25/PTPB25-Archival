import java.util.Objects;

class BoardGame {
    private String name;
    private int minPlayers;
    private int maxPlayers;
    private int playTimeMinutes;
    private String category;

    public BoardGame(String name, int minPlayers, int maxPlayers, int playTimeMinutes, String category) {
        this.name = name;
        this.minPlayers = minPlayers;
        this.maxPlayers = maxPlayers;
        this.playTimeMinutes = playTimeMinutes;
        this.category = category;
    }

    public String getName() {
        return name;
    }

    public int getMinPlayers() {
        return minPlayers;
    }

    public int getMaxPlayers() {
        return maxPlayers;
    }

    public int getPlayTimeMinutes() {
        return playTimeMinutes;
    }

    public String getCategory() {
        return category;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof BoardGame)) return false;
        BoardGame that = (BoardGame) o;
        return Objects.equals(name, that.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}