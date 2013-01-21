import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class Main {

	public static void main(String[] args) {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try{
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			BigInteger num1 = new BigInteger(st.nextToken());
			BigInteger num2 = new BigInteger(st.nextToken());

			while(!(num1.equals(BigInteger.ZERO) && num2.equals(BigInteger.ZERO))){

				int numFibonacci = findNumFibonacci(num1, num2);
				System.out.println(numFibonacci);

				str = br.readLine();
				st = new StringTokenizer(str);
				num1 = new BigInteger(st.nextToken());
				num2 = new BigInteger(st.nextToken());
			}
		} catch(Exception e){
			System.out.println(e);
		}
	}

	private static int findNumFibonacci(BigInteger num1, BigInteger num2) {
		BigInteger prev = new BigInteger("0");
		BigInteger next = new BigInteger("1");
		int count = 0;
		
		
		while(next.compareTo(num2)!=1){
			if(next.compareTo(num1)!=-1 && next.compareTo(num2)!=1)
				count++;
			BigInteger temp = next;
			next = next.add(prev);
			prev = temp;
		//	System.out.println(prev.toString() + " " + next.toString());
		}
		return count;
	}
}