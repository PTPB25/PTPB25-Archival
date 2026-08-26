import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            // Request(String) -> Response(Integer)
            String endpoint1 = scanner.nextLine();
            String payload1 = scanner.nextLine();
            int status1 = scanner.nextInt();
            scanner.nextLine();
            String message1 = scanner.nextLine();
            int resData1 = scanner.nextInt();
            scanner.nextLine();
            
            APIRequest<String> req1 = new APIRequest<>(endpoint1, payload1);
            APIResponse<Integer> res1 = req1.execute(status1, message1, resData1);
            res1.printResponse();

            // Request(Integer) -> Response(String)
            String endpoint2 = scanner.nextLine();
            int payload2 = scanner.nextInt();
            scanner.nextLine();
            int status2 = scanner.nextInt();
            scanner.nextLine();
            String message2 = scanner.nextLine();
            String resData2 = scanner.nextLine();
            
            APIRequest<Integer> req2 = new APIRequest<>(endpoint2, payload2);
            APIResponse<String> res2 = req2.execute(status2, message2, resData2);
            res2.printResponse();
            
        } catch (Exception e) {
            System.out.println("Kesalahan membaca input.");
        } finally {
            scanner.close();
        }
    }
}