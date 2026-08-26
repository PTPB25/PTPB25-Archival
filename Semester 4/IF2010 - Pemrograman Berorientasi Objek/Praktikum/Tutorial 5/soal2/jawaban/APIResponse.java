public class APIResponse<U> {
    private int statusCode;
    private String message;
    private U data;

    APIResponse(int status, String message, U data){
        this.statusCode = status;
        this.message = message;
        this.data = data;
    }

    void printResponse(){
        System.out.println("Response " + Integer.toString(statusCode) + " - " + message + " | Data: " + data + " (Type: " + data.getClass().getSimpleName() + ")");
    }
}
