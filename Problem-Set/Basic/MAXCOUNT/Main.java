import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
import java.io.PrintWriter;

class Main 
{
	public static void main(String[] args) throws Exception
	{
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int t = in.readInt(), c, v, max, x, n;
		int[] count;
		while(t--!=0)
		{
			v=0; c=0;
			max=-1;
			count = new int[10001];
			n = in.readInt();
			for(int i=0; i<n; i++)
			{
				x = in.readInt();
				
				if(max<x)
					max = x;
				
				count[x]++;
			}
			
			for(int i=1; i<=max; i++)
			{
				if(c < count[i])
				{
					c = count[i];
					v = i;
				}
			}
			out.println(v+" "+c);
		}
		out.close();
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
 
    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}