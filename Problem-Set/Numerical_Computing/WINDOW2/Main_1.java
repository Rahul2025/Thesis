import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vaibhav Mittal
 */
public class Main_1 {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		WholeSubmatrix solver = new WholeSubmatrix();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class WholeSubmatrix {
    final long MOD = 1000000080798150871L;
    long[][] nCr = new long[1001][1001];

    public WholeSubmatrix() {
        for (int i = 0; i < nCr.length; ++i) {
            nCr[i][0] = 1L;
            for (int j = 1; j <= i; ++j)
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.readInt();
        int m = in.readInt();
        int l = in.readInt();
        int k = in.readInt();
        String[] matrix = new String[n];
        for (int i = 0; i < n; ++i)
            matrix[i] = in.readString();
        long res = 0;
        if (n < l || m < k)
            res = 0;
        else {
            for (int mask = 0; mask < (1 << m); ++mask) {
                if (Integer.bitCount(mask) != k) continue;
                int countRows = 0;
                for (int i = 0; i < n; ++i) {
                    boolean good = true;
                    for (int j = 0; j < m; ++j) {
                        if ((mask & (1 << j)) == 0) continue;
                        if (matrix[i].charAt(j) == '1') continue;
                        good = false;
                        break;
                    }
                    if (good)
                        ++countRows;
                }
                res = (res + nCr[countRows][l]) % MOD;
            }
        }
        out.println(res);
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public String next() {
        return readString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}
