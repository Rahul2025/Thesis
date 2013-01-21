import java.io.DataInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

class Parser2 {
	final private int BUFFER_SIZE = 1 << 14;

	private DataInputStream din;
	private byte[] buffer;
	private int bufferPointer, bytesRead;
	char[] buf = new char[100];

	public Parser2(InputStream in) {
		din = new DataInputStream(in);
		buffer = new byte[BUFFER_SIZE];
		bufferPointer = bytesRead = 0;
	}

	public int nextInt() throws Exception {
		int ret = 0;
		byte c = (byte)din.read();
		while (c <= ' ')
			c = (byte)din.read();
		boolean neg = c == '-';
		if (neg)
			c = (byte)din.read();
		do {
			ret = ret * 10 + c - '0';
			c = (byte)din.read();
		} while (c > ' ');
		if (neg)
			return -ret;
		return ret;
	}
}

public class Main {

	static Parser2 in = new Parser2(System.in);
	static PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) throws Exception {
		final int N = 1000;
		int[] c = new int[N*N];
		int[][] dp = new int[N][N];
		
		for (int t = in.nextInt(); t > 0; t--) {
			int n = in.nextInt(), q = in.nextInt();
			Arrays.fill(c, 0);
			for (int i = 0; i < q; i++) c[in.nextInt()*n + in.nextInt()]++;
			for (int i = n-1; i > 0; i--)
				for (int j = 0; j < n; j++)
					c[(i-1)*n + j] += c[i*n + j];
			for(int i = 0; i < n; i++)
				for(int j = 1; j < n; j++)
					c[i*n + j] += c[i*n + j-1];
			
			dp[0][0] = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (i == j) continue;
					else if (i == 0) dp[i][j] = dp[i][j-1] + c[(j-1)*n + j];
					else if (j == 0) dp[i][j] = c[i*n + i-1] + dp[i-1][j];
					else if (i == j+1) {
						int val = Integer.MAX_VALUE;
						for(int k = 0; k < j; k++) {
							int cur = c[i*n + k] + dp[k][j];
							if (cur < val) val = cur;
						}
						dp[i][j] = val;
					}
					else if (i+1 == j) {
						int val = Integer.MAX_VALUE;
						for(int k = 0; k < i; k++){
							int cur = dp[i][k] + c[k*n + j];
							if (cur < val) val = cur;
						}
						dp[i][j] = val;
					}
					else if (i > j) dp[i][j] = c[i*n + i-1] + dp[i-1][j];
					else dp[i][j] = dp[i][j-1] + c[(j-1)*n + j];
			
			int res = Integer.MAX_VALUE;
			for(int i = 0; i < n-1; i++){
				int cur = dp[n-1][i] + c[i*n + n-1];
				if (cur < res) res = cur;
			}
			
			out.println(res);
		}
		
		out.flush();
	}

}