//import io.FastScanner;


import java.io.*;
//http://www.codechef.com/problems/BUYING2

public class Main_1 {
	public static void main(String[] args)throws Exception{
//		long a = System.currentTimeMillis();
		solve();
//		System.err.println("TTL:"+(System.currentTimeMillis() - a )/1000);
	}
	
	public static void solve() throws IOException{
		FastScanner fscan = new FastScanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = fscan.nextInt();
		while(T-- > 0){
			int N = fscan.nextInt();
			int K = fscan.nextInt();
			int sum = 0;
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < N; i++) {
				int t = fscan.nextInt();
				sum += t;
				if(t < min){
					min = t;
				}
			}
			int x = sum - ((sum / K) * K);
			if(min <= x){
				bw.append(String.valueOf(-1));
			}else{
				bw.append(String.valueOf(sum/K));
			}
			bw.append('\n');
		}
		bw.close();
	}
}


class IO {
	
	/**
	 * read into a[0, N) 
	 */
	public static void readIntArray(int a[],int N, FastScanner fscan) throws IOException{
		readIntArray(a,N,0,N,fscan);
	}
	/**
	 * read into a[start, end) 
	 */
	public static void readIntArray(int a[],int N, int start, int end, FastScanner fscan) throws IOException{
		if(end - start != N){
			throw new RuntimeException("Array size mismatch.");
		}
		for (int i = start; i < end; i++) {
			a[i] = fscan.nextInt();
		}
	}
}

class FastScanner {
	InputStream is;
	byte buff[] = new byte[1024];
	int currentChar = -1;
	int buffChars = 0;
	
	public FastScanner(InputStream inputStream){
		is = inputStream;
	}

	public boolean hasNext() throws IOException{
		return buffChars >= 0;
	}
	public int nextChar() throws IOException{
		//if we already have that next char read, just return else input
		if(currentChar == -1 || currentChar >= buffChars){
			currentChar = 0;
			buffChars = is.read(buff);
		}

		if(buffChars <= 0)
			return -1;
		
		return (char) buff[currentChar++];
	}
	
	public String nextString() throws IOException{
		StringBuilder bldr = new StringBuilder();
		int ch;
		while(isSpace(ch = nextChar()));

		do {
			bldr.append((char)ch);
		}while(!isSpace(ch = nextChar()));
		
		return bldr.toString();
	}
	
	public int nextInt() throws IOException{
		//considering ASCII files--> 8 bit chars,     unicode files has 16 bit chars (byte1 then byte2)
		int result = 0;
		int sign = 1;
		int ch;
		while(isSpace(ch = nextChar()));

		if(ch == '-')	{
			sign = -1;
			ch = nextChar();
		}

		do {
			if(ch < '0' || ch > '9')
				throw new NumberFormatException("Found '" + ch + "' while parsing for int.");
			
			result *= 10;
			result += ch - '0';
		}while(!isSpace(ch = nextChar()));
		
		return sign * result;
	}
	
	public long nextLong() throws IOException{
		//considering ASCII files--> 8 bit chars,     unicode files has 16 bit chars (byte1 then byte2)
		long result = 0;
		int sign = 1;
		int ch;
		while(isSpace(ch = nextChar()));

		if(ch == '-')	{
			sign = -1;
			ch = nextChar();
		}

		do {
			if(ch < '0' || ch > '9')
				throw new NumberFormatException("Found '" + ch + "' while parsing for int.");
			
			result *= 10;
			result += ch - '0';
		}while(!isSpace(ch = nextChar()));
		
		return sign * result;
	}
	private boolean isSpace(int ch){
		return ch=='\n' || ch==' ' || ch=='\t' || ch=='\r' || ch == -1;
	}
	
	public void close()  throws IOException{
		is.close();
	}
}