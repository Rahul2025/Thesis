import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;

public class Main {
	static boolean b[][];
	static int c[][];

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		int n;
		char a[][];
		char cur;
		int x = 0, y = 0;
		while (cases-- > 0) {
			n = sc.nextInt();
			a = new char[n][n];
			b = new boolean[n][n];
			c = new int[n][n];

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cur = sc.nextChar();
					a[i][j] = cur;
					if (cur == 'K') {
						x = i;
						y = j;
					}
				}
			}
			System.out.println(count(a, x, y, n - 1));
		}
	}

	static int count(char a[][], int x, int y, int n) {
		int d, e, f, g, max;
		if (x > n || x < 0 || y > n) {
			return 0;
		}
		if (b[x][y]) {
			return c[x][y];
		}

		if (a[x][y] == 'P') {
			d = 1 + count(a, x - 2, y + 1, n);
			e = 1 + count(a, x - 1, y + 2, n);
			f = 1 + count(a, x + 1, y + 2, n);
			g = 1 + count(a, x + 2, y + 1, n);
		} else {
			d = count(a, x - 2, y + 1, n);
			e = count(a, x - 1, y + 2, n);
			f = count(a, x + 1, y + 2, n);
			g = count(a, x + 2, y + 1, n);
		}
		max = Math.max(Math.max(d, e), Math.max(f, g));
		b[x][y] = true;
		c[x][y] = max;
		return c[x][y];
	}

	static class Scanner {
		private final InputStream is;
		private final byte[] data = new byte[0x2000];
		private int next, size;

		public Scanner(InputStream is) {
			this.is = is;
		}

		private boolean read() throws IOException {
			size = is.read(data);
			if (size == 0) {
				int i = is.read();
				if (i < 0)
					return false;
				data[0] = (byte) i;
				size = 1;
			} else if (size < 0)
				return false;
			next = 0;
			return true;
		}

		public int nextInt() throws IOException {
			int r;
			do {
				if (next >= size && !read())
					throw new EOFException();
				r = data[next++];
			} while (r < '0' || r > '9');
			r -= '0';
			for (int d; (next < size || read()) && '0' <= (d = data[next++])
					&& d <= '9';)
				r = r * 10 + d - '0';
			return r;
		}

		public char nextChar() throws IOException {
			int r;
			do {
				if (next >= size && !read())
					throw new EOFException();
				r = data[next++];
			} while (r <= ' ');
			return (char) r;
		}
	}
}