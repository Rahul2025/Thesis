import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
 
public class Main {
    
    public static void solve() throws Exception{
        int T = Integer.parseInt(br.readLine());
        int n,last = 2;
        long[] memo = new long[1001];
        memo[1] = memo[0] = memo[2] = 1;
        while(T-->0){
            n = Integer.parseInt(br.readLine());
            if(n>last)
                for(int i=last+1; i<=n; i++){
                    if(i%2==0)
                        memo[i] -= (memo[i/2]*memo[i/2])%10000;
                    for(int j=i/2; j>0; j--)
                        memo[i] += (memo[j]*memo[i-j]*2)%10000;
                    last = i;
                }
            out.println(memo[n]%10000);
        }
    }

    static BufferedReader br;
    static PrintWriter out;

    public static void start(){
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    public static void finish(){
        out.close();
    }

    public static void main(String[] args) throws Exception {
        start();
        solve();
        finish();
    }
}