import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tests = scanner.nextInt();

        while (tests -- > 0) {
            int nVotes = scanner.nextInt();
            Map<String, String> votes = new HashMap<String, String>();
            while (nVotes -- > 0) {
                votes.put(scanner.next(), scanner.next());
            }

            int res = 0;
            for (String vote : votes.values()) {
                res += "+".equals(vote) ? 1 : -1;
            }
            System.out.println(res);
        }
    }
}