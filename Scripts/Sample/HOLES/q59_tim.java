import java.io.*;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		String input="";
		while(testCases>0)
		{
			input = br.readLine();
			int l = input.length();
			int ctr=0;
			for(int i=0;i<l;i++)
			{
				char c = input.charAt(i);
				switch(c)
				{
				case 'A': ctr++;break;
				case 'B': ctr+=2;break;
				case 'D': ctr++;break;
				case 'O': ctr++;break;
				case 'P': ctr++;break;
				case 'Q': ctr++;break;
				case 'R': ctr++;break;				
				}
			}
			System.out.println(ctr);
			testCases--;
		}
		
		

	}

}