import java.io.DataInputStream;
import java.io.InputStream;

public class Main_1 {
	
	public static void main(String args[]) throws Exception{
		
		Parserdoubt in = new Parserdoubt(System.in);
		StringBuffer sb = new StringBuffer();
		
		int t, n, c, a;
		
		t = in.nextInt();
		
		while(t-->0) {
			n = in.nextInt();
			c = in.nextInt();
			a=0;
			while(n-->0)
				a+=in.nextInt();
			
			if(c<a)
				sb.append("No\n");
			else
				sb.append("Yes\n");
		}
		
		System.out.println(sb.toString());
	}

}

class Parserdoubt {
	final private int BUFFER_SIZE = 1 << 17;
	private DataInputStream din;
	private byte[] buffer;
	private int bufferPointer, bytesRead;

	public Parserdoubt(InputStream in) {
		din = new DataInputStream(in);
		buffer = new byte[BUFFER_SIZE];
		bufferPointer = bytesRead = 0;
	}

	public String nextString() throws Exception {
		StringBuffer sb = new StringBuffer("");
		byte c = read();
		while (c <= ' ')
			c = read();
		do {
			sb.append((char) c);
			c = read();
		} while (c > ' ');
		return sb.toString();
	}

	public char nextChar() throws Exception {
		byte c = read();
		while (c <= ' ')
			c = read();
		return (char) c;
	}

	public int nextInt() throws Exception {
		int ret = 0;
		byte c = read();
		while (c <= ' ')
			c = read();
		boolean neg = c == '-';
		if (neg)
			c = read();
		do {
			ret = ret * 10 + c - '0';
			c = read();
		} while (c > ' ');
		if (neg)
			return -ret;
		return ret;
	}

	public long nextLong() throws Exception {
		long ret = 0;
		byte c = read();
		while (c <= ' ')
			c = read();
		boolean neg = c == '-';
		if (neg)
			c = read();
		do {
			ret = ret * 10 + c - '0';
			c = read();
		} while (c > ' ');
		if (neg)
			return -ret;
		return ret;
	}

	private void fillBuffer() throws Exception {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private byte read() throws Exception {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}
}