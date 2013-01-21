import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		summingSubsetsStatic();
	}
	public static void summingSubsetsStatic() throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new java.io.BufferedWriter(new java.io.OutputStreamWriter(System.out));
		
		final int cases = Integer.parseInt(reader.readLine());
		//final int iMOD = 8388608;//2^23
		
		for(int i=0; i<cases; i++){
			int n = Integer.parseInt(reader.readLine());
			switch (n){
			case 1:
				out.append(String.valueOf(1));
				out.append("\n");
				break;
			case 2:
				out.append(String.valueOf(7));
				out.append("\n");
				break;
			case 3:
				out.append(String.valueOf(31));
				out.append("\n");
				break;
			case 4:
				out.append(String.valueOf(111));
				out.append("\n"); 
				break;
			case 5:
				out.append(String.valueOf(351));
				out.append("\n"); 
				break;
			case 6:
				out.append(String.valueOf(1023));
				out.append("\n"); 
				break;
			case 7:
				out.append(String.valueOf(2815));
				out.append("\n"); 
				break;
			case 8:
				out.append(String.valueOf(7423));
				out.append("\n"); 
				break;
			case 9:
				out.append(String.valueOf(18943));
				out.append("\n"); 
				break;
			case 10:
				out.append(String.valueOf(47103));
				out.append("\n"); 
				break;
			case 11:
				out.append(String.valueOf(114687));
				out.append("\n");
				break;
			case 12:
				out.append(String.valueOf(274431));
				out.append("\n");
				break;
			case 13:
				out.append(String.valueOf(647167));
				out.append("\n");
				break;
			case 14:
				out.append(String.valueOf(1507327));
				out.append("\n"); 
				break;
			case 15:
				out.append(String.valueOf(3473407));
				out.append("\n"); 
				break;
			case 16:
				out.append(String.valueOf(7929855));
				out.append("\n"); 
				break;
			case 17:
				out.append(String.valueOf(1179647));
				out.append("\n"); 
				break;
			case 18:
				out.append(String.valueOf(6815743));
				out.append("\n"); 
				break;
			case 19:
				out.append(String.valueOf(6291455));
				out.append("\n"); 
				break;
			case 20:
				out.append(String.valueOf(7340031));
				out.append("\n"); 
				break;
			case 21:
				out.append(String.valueOf(6291455));
				out.append("\n"); 
				break;
			case 22:
				out.append(String.valueOf(8388607));
				out.append("\n"); 
				break;
			default:
				out.append(String.valueOf(8388607));
				out.append("\n"); 
				break;
			}
		}
		out.flush();
	}
}