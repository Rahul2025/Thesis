import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		int n;
		int x = 0, y = 0;
		double d;
		class Point {
			int x;
			int y;

			Point(int x, int y) {
				this.x = x;
				this.y = y;
			}
		}
		while (cases-- > 0) {
			n = sc.nextInt();
			Point[] points = new Point[n];
			Point point;
			for (int i = 0; i < n; i++) {
				point = new Point(sc.nextInt(), sc.nextInt());
				points[i] = point;
			}
			Arrays.sort(points, new Comparator<Point>() {
				@Override
				public int compare(Point p1, Point p2) {
					if (p1.x == p2.x)
						return p2.y - p1.y;
					else
						return p1.x - p2.x;
				}
			});
			d = 0;
			for (int i = 1; i < n; i++) {
				x = points[i].x - points[i - 1].x;
				y = points[i].y - points[i - 1].y;
				d += Math.sqrt(x * x + y * y);
			}
			System.out.printf(Locale.getDefault(), "%.2f\n", d);
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