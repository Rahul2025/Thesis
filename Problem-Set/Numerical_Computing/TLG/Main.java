
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		int n1=0,n2=0,maxdiff=0, winner=0;
		String[] inps;
		for(int i=0;i<t;i++)
		{
			inps = br.readLine().split(" ");
			n1 = n1+Integer.parseInt(inps[0]);
			n2 = n2+Integer.parseInt(inps[1]);
			if(n1 > n2)
			{
				if(maxdiff < (n1-n2))
				{
					maxdiff = n1-n2;
					winner=1;
				}
			}
			else
			{
				if(maxdiff < (n2-n1))
				{
					maxdiff = n2-n1;
					winner=2;
				}
			}
		}
		System.out.println(winner+" "+maxdiff);
		
	}

}