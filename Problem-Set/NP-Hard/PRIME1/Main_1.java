import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Main_1 {

    static BitSet primes = new BitSet(31622);
    public static void initPrimes() {
        for (int i=2; i<=31622; i++) {
            primes.set(i);
        }
        for (int i=2; i<=177; i++) {
            if (primes.get(i)) {
                for (int j=2*i; j<=31622; j+=i) {
                    primes.set(j, false);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        initPrimes();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.parseInt(in.readLine());
        StringBuilder sb = new StringBuilder();
        for (int t=0; t<T; t++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int m = Integer.parseInt(st.nextToken());
            if (m==1) {
                m++;
            }
            int n = Integer.parseInt(st.nextToken());
            boolean[] result = new boolean[n-m+1];
            for (int i=2; i<=31622; i++) {
                if (primes.get(i)) {
                    int p = m-m%i;
                    if (p<m) {
                        p += i;
                    }
                    if (p==i) {
                        p += i;
                    }
                    while (p<=n) {
                        result[p-m] = true;
                        p += i;
                    }
                }
            }
            for (int i=m; i<=n; i++) {
                if (!result[i-m]) {
                    sb.append(i).append('\n');
                }
            }
            sb.append('\n');
        }
        out.println(sb);
        out.close();
    }

}