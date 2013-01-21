import java.io.*;

public class Main
{

	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = parseInt(in);															// number of test cases

		// the constraint K <= 100 allows extracting the results out of this string
		String s = "zyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba";

		while (T-- > 0)																	// cycle test cases
		{
			int K = parseInt(in);														// number of positions
			out.write(s.substring(s.length() - (K + 1 + ((K - 1) / 25)), s.length()));	// extract result as substring
			out.write('\n');
		}

		out.flush();
	}

	public static int parseInt(Reader in) throws IOException
	{
		int c = 0, v = 0;

		while (c > -1 && (c < '0' || c > '9'))
			c = in.read();

		while (c >= '0' && c <= '9')
		{
			v = (v * 10) + (c - '0');
			c = in.read();
		}

		return v;
	}

}