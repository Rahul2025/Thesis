import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Collections;
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
		SimilarGraphs solver = new SimilarGraphs();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class SimilarGraphs {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        for (int i = 0; i < 2 * n * n; i++) in.skipNext();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = b[i] = i + 1;
        Collections.shuffle(ArrayUtils.asList(a));
        Collections.shuffle(ArrayUtils.asList(b));
        out.printLine(ArrayUtils.asList(a).toArray());
        out.printLine(ArrayUtils.asList(b).toArray());
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

    public void skipNext() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        do {
            c = read();
        } while (!isSpaceChar(c));
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

    public void print(Object obj) {
        writer.print(obj);
    }

    public void println() {
        writer.println();
    }

    public void print(char c) {
        writer.print(c);
    }

    public void close() {
        writer.close();
    }

    public void printItems(Object... items) {
        for (int i = 0; i < items.length; i++) {
            if (i != 0) {
                print(' ');
            }
            print(items[i]);
        }
    }

    public void printLine(Object... items) {
        printItems(items);
        println();
    }

}

class ArrayUtils {



    public static List<Integer> asList(int[] array) {
        return new IntList(array);
    }

    private static class IntList extends AbstractList<Integer> implements RandomAccess {

        int[] array;

        private IntList(int[] array) {
            this.array = array;
        }

        public Integer get(int index) {
            return array[index];
        }

        public Integer set(int index, Integer element) {
            int result = array[index];
            array[index] = element;
            return result;
        }

        public int size() {
            return array.length;
        }
    }

    }
