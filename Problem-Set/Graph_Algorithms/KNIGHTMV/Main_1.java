import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main_1{
	public static void main(String[] args) throws IOException {
		BufferedReader br;
		PrintWriter out = new PrintWriter(System.out);
		if (args.length > 0  && args[0].equals("Test"))
			br = new BufferedReader(new FileReader("input"));
		else 
			br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		  
	    for (int i = 0; i < n; i++) {
			String s = br.readLine();
			out.println(ana(s));		
		}  
	    out.flush();
	}

	private static String ana(String s) {
		if (s.length() !=5)
			return "Error";
		else {
			int x1 = s.charAt(0) -96;
			int y1 = s.charAt(1)-48;
			
			int x2 = s.charAt(3)-96;
			int y2 = s.charAt(4)-48;
			
			if(! inRange(x1) || ! inRange(y1) || ! inRange(x2) || ! inRange(y2) || !(s.charAt(2)=='-'))
				return "Error";
			else
				return validKnight(x1,y1,x2,y2);
		}
	}

	private static String validKnight(int x1, int y1, int x2, int y2) {
		int a = Math.abs(x1-x2);
		int b = Math.abs(y1-y2);
		if (a==1 && b==2 || a==2 && b==1)
			return "Yes";
		return "No";
	}

	private static boolean inRange(int x1) {
		if (x1>0 && x1< 9)
			return true;
		return false;
	}
	
}