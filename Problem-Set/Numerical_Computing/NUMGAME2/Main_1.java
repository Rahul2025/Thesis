import java.io.*;
public class Main_1
{
	public static void main(String[] args) throws IOException
	{
		new Main_1().start();
	}
	public void start() throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
			int n=Integer.parseInt(br.readLine());
			n--;
			if(n%4==0)
				System.out.println("ALICE");
			else
				System.out.println("BOB");
		}
	}
}