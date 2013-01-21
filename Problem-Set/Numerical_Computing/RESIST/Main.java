import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;
 
public class Main {
        public static void main(String[] args){
                InputStream inputStream = System.in;
                OutputStream outputStream = System.out;
                FastScanner in = new FastScanner(inputStream);
                FastPrinter out = new FastPrinter(outputStream);
                Resistance solver = new Resistance();
                int testCount = Integer.parseInt(in.next());
                for (int i = 1; i <= testCount; i++)
                        solver.solve(i, in, out);
                out.close();
        }
}
 
class Resistance{
    public void solve(int testNumber, FastScanner in, FastPrinter out){
        int N = Integer.parseInt(in.next());
	int M = Integer.parseInt(in.next());

	long numerator = 1;
	long denominator = 1;
	long prevNumerator = 1;
	long prevDenominator = 1;
        for(int i = 2; i <=N; i++)
        {
                numerator = (prevNumerator + prevDenominator)%M;
                denominator = (2*prevDenominator + prevNumerator)%M;
		prevNumerator = numerator;
		prevDenominator = denominator;
        }

        out.println(numerator + "/" + denominator);

        }//end of solve method()
 
}//end of FitToPlay class
 
class FastScanner extends BufferedReader {
 
    boolean isEOF;
 
    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }
 
    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }
 
    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }
 
    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }
 
    }
 
class FastPrinter extends PrintWriter {
 
    public FastPrinter(OutputStream out) {
        super(out);
    }
 
    public FastPrinter(Writer out) {
        super(out);
    }
 
 
}