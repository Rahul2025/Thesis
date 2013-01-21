import java.io.*;

class Parser {

	final private int BUFFER_SIZE = 1 << 16;
	private DataInputStream din;
	private byte[] buffer;
	private int bufferPointer, bytesRead;

	public Parser(InputStream in) {
		din = new DataInputStream(in);
		buffer = new byte[BUFFER_SIZE];
		bufferPointer = bytesRead = 0;

	}

	public int nextInt() throws Exception {
		int ret = 0;
		byte c = read();
		while (c <= ' ') {
			c = read();
		}
		boolean neg = c == '-';
		if (neg) {
			c = read();
		}
		do {
			ret = ret * 10 + c - '0';
			c = read();
		} while (c > ' ');
		if (neg) {
			return -ret;
		}
		return ret;
	}

	private void fillBuffer() throws Exception {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1) {
			buffer[0] = -1;
		}
	}

	private byte read() throws Exception {
		if (bufferPointer == bytesRead) {
			fillBuffer();
		}
		return buffer[bufferPointer++];
	}
}

public class Main{

	public static void main(String[] args) throws Exception {
		Parser ps = new Parser(System.in);
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		int t = ps.nextInt();
		while(t-- > 0){
			int n = ps.nextInt();
			int x;
			int max = Integer.MAX_VALUE;
			int cnt = 0;
			for(int i = 0; i < n; i++){
				x = ps.nextInt();
				if(x <= max){
					cnt++;
					max = x;
				}
			}
			out.println(cnt);
		}
		out.flush();
	}
} 