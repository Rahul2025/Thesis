import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[] g;
	int[] part1, part2;
	int n, m;
	int minCross;
	
	int[] calc;
	int[] bitCnt;
	int[] x, y;
	
	void makeAns(int mask, int sx, int sy) {
		for (int i = 0; i < n; i++)
			if (test(mask, i)) {
				x[i] = sx * (i + 1);
				y[i] = sy * (i + 1);
			}
	}
	
	void makeAns(int mask, int sign) {
		for (int sub = (mask - 1) & mask; sub != 0; sub = (sub - 1) & mask) {
			if (calc[sub] + calc[mask ^ sub] == calc[mask]) {
				makeAns(sub, sign, 1);
				makeAns(mask ^ sub, sign, -1);
				return;
			}
		}
		
		throw new AssertionError("Couldn't restore answer");
	}
	
	boolean test(int mask, int ind) {
		return ((mask >> ind) & 1) == 1;
	}
	
	void solve2() throws IOException {
		n = nextInt();
		m = nextInt();
		g = new int[n];
		minCross = Integer.MAX_VALUE / 10;
		
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1] |= (1 << v2);
			g[v2] |= (1 << v1);
		}
		
		if (n == 2) {
			out.println(m == 1 ? 1 : 0);
			out.println("1 1");
			out.println("-1 1");
			return;
		}
		
		calc = new int[1 << n];
		bitCnt = new int[1 << n];
		Arrays.fill(calc, -1);
		int minBitCnt = n / 4;
		int maxBitCnt = (n + 2) / 4;
		int halfCnt = n / 2;
		
		int fullMask = calc.length - 1;
		
		int minCross = Integer.MAX_VALUE / 10;
		int bestSplit = -1;
		
		for (int mask = 0; mask < calc.length; mask++) {
			bitCnt[mask] = bitCnt[mask >> 1];
			if (test(mask, 0))
				bitCnt[mask]++;
			if (bitCnt[mask] >= minBitCnt && bitCnt[mask] <= maxBitCnt) {
				calc[mask] = 0;
				for (int i = 0; i < n; i++)
					if (test(mask, i))
						calc[mask] += bitCnt[g[i] & mask];
				calc[mask] >>= 1;
			}
			if (bitCnt[mask] == halfCnt) {
				for (int sub = (mask - 1) & mask; sub != 0; sub = (sub - 1) & mask) {
					if (bitCnt[sub] == maxBitCnt)
						calc[mask] = Math.max(calc[mask], calc[sub] + calc[mask ^ sub]);
				}
				if (calc[fullMask ^ mask] != -1) {
					int curCross = m - calc[mask] - calc[fullMask ^ mask];
					if (curCross < minCross) {
						minCross = curCross;
						bestSplit = mask;
					}
				}
			}
		}
		
		x = new int[n];
		y = new int[n];
		
		out.println(minCross);
		makeAns(bestSplit, 1);
		makeAns(fullMask ^ bestSplit, -1);
		
		for (int i = 0; i < n; i++)
			out.println(x[i] + " " + y[i]);
	}

	void solve() throws IOException {
		int tests = nextInt();
		while (tests-- > 0) {
			solve2();
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}