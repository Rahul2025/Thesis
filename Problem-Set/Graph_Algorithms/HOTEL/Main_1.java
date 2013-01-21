import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

public class Main_1 {


	public static void main (String[] args)
	{


		try {
			//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			Scan in = new Scan(System.in);
			PrintWriter pw = new PrintWriter(System.out);
			int cases = in.nextInt();
			for (int i = 0; i < cases; i++) {
				int N = in.nextInt();
				int[] arrival = new int[N];
				int[] departure = new int[N];
				for (int j = 0; j < N; j++) {
					arrival[j] = in.nextInt();
				}
				for (int j = 0; j < N; j++) {
					departure[j] = in.nextInt();
				}
				int[] nums = new int[1005];
				for (int j = 0; j < N; j++) {
					for (int j2 = arrival[j]; j2 < departure[j]; j2++) {
						nums[j2]++;
					}
				}
				int max = -1;
				for (int j = 0; j < nums.length; j++) {
					if(max<nums[j])
						max = nums[j];
				}
				pw.println(max);

			}
			pw.flush();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	static class Scan {
		private final InputStream is;
		private final byte[] data = new byte[0x2000];
		private int next, size;

		public Scan(InputStream Pis) {
			is = Pis;
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