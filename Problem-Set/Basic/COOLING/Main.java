import java.io.*;
import java.util.*;
public class Main
{
	static InputStreamReader read=new InputStreamReader(System.in);
	static BufferedReader in=new BufferedReader(read);
	static PrintWriter pw=new PrintWriter(System.out);
	
	public static void main(String args[])throws IOException
	{
		int n=Integer.parseInt(in.readLine());
		for(int i=1;i<=n;i++)
		{
			int N=Integer.parseInt(in.readLine());
			int pies[]=new int[N];
			int racks[]=new int[N];
			StringTokenizer token=new StringTokenizer(in.readLine());
			for(int j=0;j<N;j++)
				pies[j]=Integer.parseInt(token.nextToken());
			token=new StringTokenizer(in.readLine());
			for(int j=0;j<N;j++)
				racks[j]=Integer.parseInt(token.nextToken());
			Arrays.sort(pies);
			Arrays.sort(racks);
			int count=0;
			for(int j=0;j<N;j++)
			{
				if(pies[count]<=racks[j])
					count++;
			}
			pw.println(count);
		}
		pw.close();
	}
}
			
			