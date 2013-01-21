import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;

  class Main_1 {
static StringBuffer sb = new StringBuffer(100);
static Scanner scan = new Scanner(System.in);
public static void main(String args[])throws IOException{
	int testCases = scan.nextInt();
	while(testCases>0){
		boolean chef = false, assist=true;
		int total = scan.nextInt();
		int completed = scan.nextInt();
		boolean[] jobs = new boolean[total+1];
		for(int i=0;i<completed;i++){  jobs[scan.nextInt()]=true;}
		StringBuffer sbChef = new StringBuffer(100);
		StringBuffer sbAssist = new StringBuffer(100);
		for(int i =1;i<total+1;i++){ 
			if(!jobs[i]){
			if(!chef){
				sbChef.append(i).append(" "); chef = true; assist = false;
			}
			else if(!assist){
				sbAssist.append(i).append(" "); chef = false; assist = true;
			}
		} 
		}
		sb.append(sbChef.toString()).append("\n").append(sbAssist.toString()).append("\n");
		--testCases;
	}
	System.out.println(sb.toString());
}
static class Scanner {
	private final InputStream is;
	private final byte[] data = new byte[0x2000];
	private int next, size;

	public Scanner(InputStream is) {
		this.is = is;
	}

	private boolean read() throws IOException {
		size = is.read(data);
		if (size == 0) {
			int i = is.read();
			if (i < 0)
				return false;
			data[0] = (byte) i;
			size = 1;
		} else if (size < 0)
			return false;
		next = 0;
		return true;
	}

	public int nextInt() throws IOException {
		int r;
		do {
			if (next >= size && !read())throw new EOFException();
			r = data[next++];
		} while (r < '0' || r > '9');
		r -= '0';
		for (int d; (next < size || read()) && '0' <= (d = data[next++])
				&& d <= '9';)
			r = r * 10 + d - '0';
		return r;
	}

	public char nextChar() throws IOException {
		int r;
		do {
			if (next >= size && !read())
				throw new EOFException();
			r = data[next++];
		} while (r <= ' ');
		return (char) r;
	}
}
}