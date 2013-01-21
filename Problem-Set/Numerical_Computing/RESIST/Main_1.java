import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Jacob Jiang
 */
public class Main_1 {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		Resistance solver = new Resistance();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Resistance {
    private static long[][] A = {{1, 1}, {1, 0}};
    private static long[][] B = {{1}, {1}};

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        long MOD = in.nextLong();
        long[][] answer = new Matrix(A, MOD).pow(2 * (n - 1)).multiply(new Matrix(B, MOD)).data;
        out.println(answer[1][0] + "/" + answer[0][0]);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
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

    public int nextInt() {
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
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public long nextLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    }

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void println(String x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

    }

class Matrix {
    public int height;
    public int width;
    public long MOD;
    public long[][] data;

    public Matrix(int height, int width, long MOD) {
        this.height = height;
        this.width = width;
        this.MOD = MOD;
        data = new long[height][width];
    }

    public Matrix(long[][] data, long MOD) {
        this.data = data;
        this.MOD = MOD;
        height = data.length;
        width = data[0].length;
    }

    public Matrix multiply(Matrix that) {
        if (width != that.height || MOD != that.MOD) {
            throw new IllegalArgumentException();
        }
        long[][] result = new long[height][that.width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < that.width; j++) {
                for (int k = 0; k < width; k++) {
                    result[i][j] = (result[i][j] + data[i][k] * that.data[k][j]) % MOD;
                }
            }
        }
        return new Matrix(result, MOD);
    }

    public static Matrix identity(int size, long MOD) {
        long[][] result = new long[size][size];
        long num = 1 % MOD;
        for (int i = 0; i < size; i++) {
            result[i][i] = num;
        }
        return new Matrix(result, MOD);
    }

    public Matrix pow(long exp) {
        if (height != width) {
            throw new UnsupportedOperationException();
        }
        if (exp < 0) {
            throw new IllegalArgumentException();
        }
        return powImpl(exp);
    }

    private Matrix powImpl(long exp) {
        if (exp == 0) {
            return identity(height, MOD);
        }
        Matrix result = powImpl(exp >> 1);
        result = result.multiply(result);
        if ((exp & 1) == 1) {
            result = result.multiply(this);
        }
        return result;
    }

    public String toString() {
        return Arrays.deepToString(data);
    }
}
