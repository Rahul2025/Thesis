import java.io.*;

public class Main_1 {
	public static void main(String[] args) {
		InputStream inStream = System.in;
		OutputStream outStream = System.out;
		InputReader in = new InputReader(inStream);
		PrintWriter out = new PrintWriter(outStream);
	
		int H = in.readInt();
		int W = in.readInt();
		int[][] Mat = new int[H][W];

		for(int i = 0; i < H; ++i)
			for(int j = 0; j < W; ++j)
				Mat[i][j] = in.readInt();

		int[] rows = new int[H];
		int[] cols = new int[W];

		int row_count = 0, col_count = 0;
		boolean found = false;
		for(int i = 0; i < H; ++i) {
			for(int j = 0; j < W; ++j) {
				if(Mat[i][j] > 0) {
					row_count = 1;
					col_count = 1;
					rows[0] = i;
					cols[0] = j;
					found = true;
					break;
				}
			}
			if(found)break;
		}

		System.out.println(row_count+" "+col_count);
		System.out.println(rows[0]);
		System.out.println(cols[0]);

		if(out != null)
			out.close();
		System.exit(0);
	}
}

class InputReader {
	private int numChars;
	private int curChar;
	private byte[] buf = new byte[1024];
	private InputStream stream;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if(numChars == -1) {
			return 0;
		}
		if(curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			}
			catch(IOException e) {
				return 0;
			}
			if(numChars <= 0) {
				return -1;
			}
		}
		return buf[curChar++];
	}
	
	public int readInt() {
		int c = read();
		
		if(isSpaceChar(c))
			c = read();
		
		int sgn = 1;
		int res = 0;
		if(c == '-') {
			sgn = -1;
			c = read();
		}

		do {
			if(c < '0' || c > '9') 
				return 0;
			res *= 10;
			res += c-'0';
			c= read();
		}
		while(!isSpaceChar(c));

		return res*sgn;
	}

	public static boolean isSpaceChar(int c) {
		return c == '\n' || c == '\r' || c == '\t' || c == -1 || c == ' ';
	}
}