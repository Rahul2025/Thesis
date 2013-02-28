import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;

public class Main_1 {
	static int MOD = 8388608;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		int n;
		long pow, sum = 0;
		StringBuffer sb = new StringBuffer();
		while (cases-- > 0) {
			n = sc.nextInt();
			pow = pow(2, n - 1);
			sum = pow * (n * n - n + 2) - 1;
			if(sum < 0)
				sum+=MOD;
			sb.append((sum % MOD) + "\n");
		}
		System.out.println(sb);
	}

	static long pow(int x, int n) {
		long ans;
		if (n == 0) {
			return 1;
		}
		long p = pow(x, n / 2);
		if (n % 2 == 0) {
			ans = (p * p) % MOD;
			return ans;
		} else {
			ans = (x * p * p) % MOD;
			return ans;
		}
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
	}
}