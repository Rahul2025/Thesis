import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main_1 {

	public static void main(String[] args) {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;
		try {
			str = br.readLine();
			int numCases = Integer.parseInt(str);
			while(numCases>0){

				String text = br.readLine();
				int midValue = text.length()/2;

				String firstPart = text.substring(0, midValue);
				String secondPart = text.substring(midValue, text.length());
				
				firstPart = new StringBuffer(firstPart).reverse().toString();
				secondPart = new StringBuffer(secondPart).reverse().toString();

				System.out.println(firstPart+secondPart);
				
				numCases--;
			}
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}