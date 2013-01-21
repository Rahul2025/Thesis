import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.RandomAccess;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.io.InputStream;

public class Main 
{
	public static void main(String[] args) 
	{
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		MaxRect solver = new MaxRect();
		int T = 1;
		for(int count = 0; count < T; count++)
		{
			solver.solve(count+1, in, out);			
		}
		out.close();

	}//end of main()
}
 
class MaxRect 
{
	public void solve(int testNumber, InputReader in, OutputWriter out) 
	{
		int H, W;
		long M[][];

		H = in.readInt();
		W = in.readInt();

		M = new long[H][W];

		long max = -1;
		int r = 0, c = 0;

		for(int count1 = 0; count1 < H; count1++)
		{
			for(int count2 = 0; count2 < W; count2++)
			{
				M[count1][count2] = in.readLong();
				if(M[count1][count2] > max)
				{
					max = M[count1][count2];
					r = count1;
					c = count2;
				}
			}
		}
		
		out.print("1 1\n");
		out.print(r + "\n");
		out.print(c + "\n");

	}//end of solve()

}//end of class MaxRect

class InputReader 
{
 
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
 
	public InputReader(InputStream stream) 
	{
		this.stream = stream;
	}
	 
	public int read() 
	{
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) 
		{
			curChar = 0;
			try 
			{
				numChars = stream.read(buf);
			} 
			catch (IOException e) 
			{
				throw new InputMismatchException();
			}

			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
 
	public int readInt() 
	{
		int c = read();

		while (isSpaceChar(c))
			c = read();

		int sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}

		int res = 0;
		do 
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} 
		while (!isSpaceChar(c));

		return res * sgn;
	}

	public long readLong() 
	{
		int c = read();

		while (isSpaceChar(c))
			c = read();

		long sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}

		long res = 0;
		do 
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} 
		while (!isSpaceChar(c));

		return res * sgn;
	}

	public String readString() 
	{
		StringBuilder sb = new StringBuilder();
		int c = read();
		while (isWhiteSpace(c)) 
		{
		    c = read();
		}

		while (!isWhiteSpace(c)) 
		{
		    sb.appendCodePoint(c);
		    c = read();
		}

		return sb.toString();
	}

	public static boolean isWhiteSpace(int c) 
	{
		return c >= -1 && c <= 32;
	}
 
	public static boolean isSpaceChar(int c) 
	{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
}
 
class OutputWriter 
{
	private final PrintWriter writer;
	 
	public OutputWriter(OutputStream outputStream) 
	{
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}
	 
	public OutputWriter(Writer writer) 
	{
		this.writer = new PrintWriter(writer);
	}
	 
	public void print(Object...objects) 
	{
		for (int i = 0; i < objects.length; i++) 
		{
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
	 
	public void printLine(Object...objects) 
	{
		print(objects);
		writer.println();
	}
	 
	public void close() 
	{
		writer.close();
	}
 
}