import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1
{
	public static void main( String args[] ) throws Exception
	{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ));
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		int f_no = Integer.parseInt( st.nextToken() );
		int s_no = Integer.parseInt( st.nextToken() );
		
		int sub_ans = f_no-s_no;
		
		int res = sub_ans%10;
		if ( res < 9 )
			sub_ans= sub_ans +1;
		else
		{sub_ans = sub_ans-1;
		}
		
		System.out.println(sub_ans);
		
			
		
	}
}
				
				
				
				
				
		
			