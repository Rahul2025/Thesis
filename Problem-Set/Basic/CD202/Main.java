import java.io.*;
import java.util.*;
public class Main {
    public static String decode(String s) {
        String res = "";
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0 ; i < s.length(); ++i) {
            char c = s.charAt(i);
            res += c;
            for(char j : vowels) {
                if(j == c) {
                    i += 2;
                    break;
                }
            }
        }
        return res;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(decode(br.readLine()));
    }
}