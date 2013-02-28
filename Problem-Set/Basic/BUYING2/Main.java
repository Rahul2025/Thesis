import static java.util.Arrays.*;

import java.io.*;
import java.lang.reflect.*;

class Main {

	final int MOD = (int)1e9 + 7;
	final double eps = 1e-12;
	final int INF = (int)1e9;

	public void solve () {
		sc.nextInt();
		int X = sc.nextInt();
		Integer [] A = sc.nextInts();
		
		int S = 0;
		for (int a : A)
			S += a;
		sort(A);
		int m = A[0];
		
		int R1 = S/X, R2 = (S-m)/X;
		if (R1 == R2)
			print(-1);
		else
			print(R1);
	}
	
	void init () {
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	static MyScanner sc;
	
	static class MyScanner {
		public String next() {
			readToken();
			return new String(b, T[0], T[1]);
		}
		
		public char nextChar() {
			readToken();
			return (char)b[T[0]];
		}
				
		public int nextInt() {
			return (int)nextLong();
		}
		
		public long nextLong() {
			readToken();
			return calc(T[0], T[1]);
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
		public String nextLine() {
			readLine();
			return new String(b, T[0], T[1]);
		}
		
		public String [] nextStrings() {
			readLine();
			String [] res = new String[count(T[0], T[1])];
			for (int i = T[0], s = T[0], c = 0; i < T[1]; ++i)
				if (b[i] == ' ') {
					res[c++] = new String(b, s, i);
					s = i+1;
				}
			return res;
		}
		
		public char [] nextChars() {
			readToken();
			char [] res = new char[T[1] - T[0]];
			for (int i = T[0]; i < T[1]; ++i)
				res[i] = (char)b[i];
			return res;
		}

		public Integer [] nextInts() {
			readLine();
			int s = T[0], c = 0;
			Integer [] res = new Integer[count(T[0], T[1])];
			for (int i = T[0]; i < T[1]; ++i)
				if (b[i] == ' ') {
					res[c++] = (int)calc(s, i);
					s = i+1;
				}
			res[c] = (int)calc(s, T[1]);
			return res;
		}	
		
		public Long [] nextLongs() {
			readLine();
			int s = T[0], c = 0;
			Long [] res = new Long[count(T[0], T[1])];
			for (int i = T[0]; i < T[1]; ++i)
				if (b[i] == ' ') {
					res[c++] = calc(s, i);
					s = i+1;
				}
			res[c] = calc(s, T[1]);
			return res;
		}

		public Double [] nextDoubles() {
			readLine();
			Double [] res = new Double[count(T[0], T[1])];
			for (int i = T[0], s = T[0], c = 0; i < T[1]; ++i)
				if (b[i] == ' ') {
					res[c++] = Double.parseDouble(new String(b, s, i));
					s = i+1;
				}
			return res;
		}

		//////////////////////////////////////////////
		
		private final static int MAX_SZ = 12000000;
		private final byte [] b = new byte[MAX_SZ];
		private final int [] T = new int [2];
		private int cur = 0; 

		MyScanner () {
			try {
				InputStream is = new BufferedInputStream(System.in);
				while (is.available() == 0)
					Thread.sleep(1);
				start();
				is.read(b);
			} catch (Exception e) {
				throw new Error(e);
			}
		}
		
		private void readLine() {
			int c;
			for (c = cur; b[c] != '\n' && b[c] != '\r'; ++c);
			T[0] = cur; T[1] = c;
			for (cur = c; b[cur] == '\n' || b[cur] == '\r'; ++cur);
		}
		
		private void readToken() {
			int c;
			for (c = cur; b[c] != ' ' && b[c] != '\n' && b[c] != '\r'; ++c);
			T[0] = cur; T[1] = c;
			for (cur = c; b[cur] == ' ' || b[cur] == '\n' || b[cur] == '\r'; ++cur);
		}

		private int count(int s, int e) {
			int cnt = 1;
			for (int i = s; i < e; ++i)
				if (b[i] == ' ')
					++cnt;		
			return cnt;
		}
		
		private long calc(int s, int e) {
			long res = 0, f = 1;
			for (int i = s; i < e; ++i)
				if (b[i] == '-')
					f = -1;
				else
					res = '\n' * res + b[i] - '0';
			return res * f;			
		}
	}
	
	static void print (Object... a) {
		pw.println(build(a));
	}

	static void exit (Object... a) {
		print(a);
		exit();
	}

	static void exit () {
		pw.close();
		System.out.flush();
		Thread.yield();
		//System.err.println("------------------");
		//System.err.println("Time: " + ((millis() - t) / 1000.0));
		System.exit(0);
	}
	
	void NO() {
		throw new Error("NO!");
	}

	////////////////////////////////////////////////////////////////////////////////////
	
	public Main () {
		init();
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t)
			solve();
	}
	
	static String build(Object... a) {
		StringBuilder b = new StringBuilder();
		for (Object o : a)
			append(b, o);
		return b.toString().trim();		
	}
	
	static void append(StringBuilder b, Object o) {
		if (o.getClass().isArray()) {
			int L = Array.getLength(o);
			for (int i = 0; i < L; ++i)
				append(b, Array.get(o, i));
		} else if (o instanceof Iterable<?>) {
			for (Object p : (Iterable<?>)o)
				append(b, p);
		} else
			b.append(" ").append(o);		
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public static void main(String[] args) throws IOException {
		sc = new MyScanner ();
		new Main();
		exit();
	}

	static void start() {
		t = millis();
	}

	static PrintWriter pw = new PrintWriter(System.out);
	
	static long t;
	
	static long millis() {
		return System.currentTimeMillis();
	}	
}