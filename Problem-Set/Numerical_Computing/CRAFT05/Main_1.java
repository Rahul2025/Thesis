import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1 {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.valueOf(br.readLine()).intValue();
        
        String[] p = new String[10];
        p[0] = "0";
        p[5] = "05";
        p[1] = p[3] = p[7] = p[9] = "0123456789";
        p[2] = p[4] = p[6] = p[8] = "02468";
        
        loop:
            while((t--)>0) {
                int n = Integer.valueOf(br.readLine()).intValue();
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                String xyz = st.nextToken() + st.nextToken() + st.nextToken();
                
                int low = (Integer.valueOf("1" + xyz + "0").intValue())/n;
                int high = (Integer.valueOf("9" + xyz + p[n%10].charAt(p[n%10].length()-1)).intValue())/n;
                
                String p1 = p[n%10];
                for(int i=9; i>=0; i--)
                    for(int j=p1.length()-1; j>=0; j--) {
                        int num = Integer.valueOf(i + xyz + p1.charAt(j)).intValue();
                        if(num%n==0) {
                            System.out.println(i + " " + p1.charAt(j) + " " + (num/n));
                            continue loop;
                        }
                    }
                
                System.out.println("0");
            }
    }
}