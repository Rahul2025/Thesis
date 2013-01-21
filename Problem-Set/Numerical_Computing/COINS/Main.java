import java.io.*;
import java.util.HashMap;
import java.util.Map;
public class Main {

    public static long goldCoins(long input, Map<Long, Long> solutions) {
        long n1 = input/2;
        long n2 = input/3;
        long n3 = input/4;

        long result = input;

        if(n1 + n2 + n3 > result) {
            if(solutions.get(n1) == null) {
                solutions.put(n1, goldCoins(n1, solutions));
            }
            if(solutions.get(n2) == null) {
                solutions.put(n2, goldCoins(n2, solutions));
            }
            if(solutions.get(n3) == null) {
                solutions.put(n3, goldCoins(n3, solutions));
            }
            result = solutions.get(n1) + solutions.get(n2) + solutions.get(n3);
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String line;
        while((line = reader.readLine()) != null) {
            System.out.println(goldCoins(Long.parseLong(line.trim()), new HashMap<Long, Long>()));
        }
    }
}