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
        public static void main(String[] args) throws Exception{
                InputStream inputStream = System.in;
                OutputStream outputStream = System.out;
                FastScanner in = new FastScanner(inputStream);
                FastPrinter out = new FastPrinter(outputStream);
                TopBatsmen solver = new TopBatsmen();
                int testCount = Integer.parseInt(in.next());
                for (int i = 1; i <= testCount; i++)
                        solver.solve(i, in, out);
                out.close();
        }
}
 
class TopBatsmen {
    public void solve(int testNumber, FastScanner in, FastPrinter out) throws Exception{
        String scores = in.readLine();
        String[] scoreStr = scores.split(" ");
	int[] score = new int[101];
	int numOfPlayers = scoreStr.length;	

	for(int i = 0; i < scoreStr.length; i++)
	{
		int tempScore = Integer.parseInt(scoreStr[i]);
		score[tempScore]++;
	}

	int k = Integer.parseInt(in.readLine());
	int i;
	for(i = 100; i >=0; i--)
	{
		if(score[i] > 0)
		{
			if(score[i] < k)
			{
				k = k - score[i];
			}
			else
			{
				break;
			}
		}

	}

	if(score[i] == k)
	{
		out.println("1");
	}
	else//score[i] > k
	{
		out.println(getnCk(score[i],k));
	}
	}//end of solve method()
	
	public int getnCk(int n, int k)
	{
		int C[][] = new int[n+1][k+1];
		
		for(int i = 0; i <= n; i++)
		{
			C[i][0] = 1;
		}
		
		for(int j = 0; j <=k; j++)
		{
			C[j][j] = 1;
		}
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j < i && j <= k; j++)
			{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}
		
		return C[n][k];
	}

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