import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;
 
public class Main {
 
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int n2 = n*n;
        int[][] a = new int[n2][n2];
        int k = Integer.parseInt(st.nextToken());
        for (int i=0; i<k; i++) {
	st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken())-1;
            int y = Integer.parseInt(st.nextToken())-1;
            int d = Integer.parseInt(st.nextToken());
            a[x][y] = d;
        }
	        for (int i=0; i<n2; i++) {
            StringBuilder sb = new StringBuilder();
            int shift = i/n;
            for (int j=0; j<n2; j++) {
                if (j!=0) {
                    sb.append(' ');
                }
                if (a[i][j]!=0) {
                    sb.append(a[i][j]);
                } else {
                    int val = (i*n+j+shift)%n2;
                    if (val == 0) {
                        val = n2;
                    }
                    sb.append(val);
                }
            }
            out.println(sb);
        }
        out.close();
    }
 
}
 
