import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main_1{

	public static void main(String[] args){
		BigInteger[] fib=new BigInteger[100];
		fib[0] = BigInteger.ONE;
		fib[1] = BigInteger.ONE;
		for(int i=2;i<100;i++)
			fib[i] = fib[i-1].add(fib[i-2]);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;
		
		try {
			while(!(str=br.readLine().trim()).equals("0")){
				int n= Integer.parseInt(str);
				System.out.println(fib[2*n-1]);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}