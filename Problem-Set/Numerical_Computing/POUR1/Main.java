import java.io.*;
public class Main {
	static int a,b,c,d;
	public static int min(int a,int b) {
	    return a<b?a:b;
	}
	public static int gcd(int a,int b) {
	    return b==0?a:gcd(b,a%b);
	}
	public static int check(int a,int b) {
	    int ret = 0,ca = 0,cb = 0;
	    for (;;) {
	        if (ca==c || cb==c) return ret;
	        if (cb==b) cb = 0;
	        else if (ca==0) ca = a;
	        else {
	            int dt = min(b-cb,ca);
	            ca -= dt; cb += dt;
	        }
	        ret++;
	    }
	}
	public static void main(String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		int ntest;
		String h = "";
		String []f;
		    ntest = Integer.parseInt(stdin.readLine());
		   for(int i=0 ; i<ntest ; i++) {
		        a = Integer.parseInt(stdin.readLine());
		        b = Integer.parseInt(stdin.readLine());
		        c = Integer.parseInt(stdin.readLine());
		        d = gcd(a,b);
		        if (c%d!=0 || c>a && c>b) System.out.println("-1");
		        else {
		            int ans = check(a,b);
		            ans = min(ans,check(b,a));
		            System.out.println(ans);
		        }
		    }

	}

}