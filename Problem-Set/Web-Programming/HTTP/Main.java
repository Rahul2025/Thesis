import java.util.Scanner;
import java.net.URL;  
 
public class Main {
    public static void main(String[] args) throws Exception {         
        Scanner sc = new Scanner(new URL("http://www.facebook.com").openStream());
        while (sc.hasNext())
            System.out.println(sc.nextLine());         
    }
}