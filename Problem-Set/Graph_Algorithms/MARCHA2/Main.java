import java.io.*;

public class Main {

	public static void main (String[] args)
	{
	
		try {
			Scan s = new Scan(System.in);
			PrintWriter pw = new PrintWriter(System.out);
			int casos = s.nextInt();
			for (int i = 0; i < casos; i++) {
				int k = s.nextInt();
				int[] niveles = new int[k];
				for (int j = 0; j < k; j++) {
					niveles[j] = s.nextInt();
				}
				int stems = 1;
				for (int j = 0; j < k; j++) {
					if(stems==0)
					{
						stems=-1;
						break;
					}
					stems-=niveles[j];
					if(stems<0)
					{
						stems=-1;
						break;
					}
					stems*=2;
				}
				pw.println(stems==0? "Yes":"No");
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
 
		public Scan(InputStream is) {
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